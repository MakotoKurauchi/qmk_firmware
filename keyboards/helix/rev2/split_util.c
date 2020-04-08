#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "split_util.h"
#include "matrix.h"
#include "keyboard.h"
#include "quantum.h"

#ifdef USE_MATRIX_I2C
#  include "i2c.h"
#else
#  include "split_scomm.h"
#endif

#ifdef EE_HANDS
#    include "eeconfig.h"
#endif

#ifndef SPLIT_USB_TIMEOUT
#    define SPLIT_USB_TIMEOUT 2000
#endif

#ifndef SPLIT_USB_TIMEOUT_POLL
#    define SPLIT_USB_TIMEOUT_POLL 10
#endif

volatile bool isLeftHand = true;

bool waitForUsb(void) {
    for (uint8_t i = 0; i < (SPLIT_USB_TIMEOUT / SPLIT_USB_TIMEOUT_POLL); i++) {
        // This will return true if a USB connection has been established
        if (UDADDR & _BV(ADDEN)) {
            return true;
        }
        wait_ms(SPLIT_USB_TIMEOUT_POLL);
    }

    // Avoid NO_USB_STARTUP_CHECK - Disable USB as the previous checks seem to enable it somehow
    (USBCON &= ~(_BV(USBE) | _BV(OTGPADE)));

    return false;
}

#ifdef SPLIT_HAND_MATRIX_GRID
static uint8_t peek_matrix_intersection(pin_t out_pin, pin_t in_pin) {
    setPinInputHigh(in_pin);
    setPinOutput(out_pin);
    writePinLow(out_pin);
    // It's almost unnecessary, but wait until it's down to low, just in case.
    wait_us(1);
    uint8_t pin_state = readPin(in_pin);
    // Set out_pin to a setting that is less susceptible to noise.
    setPinInputHigh(out_pin);
    wait_us(30);
    return pin_state;
}
#endif

bool is_keyboard_left(void) {
#if defined(SPLIT_HAND_PIN)
    // Test pin SPLIT_HAND_PIN for High/Low, if low it's right hand
    setPinInput(SPLIT_HAND_PIN);
    return readPin(SPLIT_HAND_PIN);
#elif defined(SPLIT_HAND_MATRIX_GRID)
#   ifdef SPLIT_HAND_MATRIX_GRID_LOW_IS_RIGHT
    return peek_matrix_intersection(SPLIT_HAND_MATRIX_GRID);
#   else
    return ! peek_matrix_intersection(SPLIT_HAND_MATRIX_GRID);
#   endif
#elif defined(EE_HANDS)
    return eeconfig_read_handedness();
#elif defined(MASTER_RIGHT)
    return !is_helix_master();
#endif

    return is_helix_master();
}

bool is_helix_master(void) {
    static enum { UNKNOWN, MASTER, SLAVE } usbstate = UNKNOWN;

    // only check once, as this is called often
    if (usbstate == UNKNOWN) {
#if defined(SPLIT_USB_DETECT)
        usbstate = waitForUsb() ? MASTER : SLAVE;
#elif defined(__AVR__)
        USBCON |= (1 << OTGPADE);  // enables VBUS pad
        wait_us(5);

        usbstate = (USBSTA & (1 << VBUS)) ? MASTER : SLAVE;  // checks state of VBUS
#else
        usbstate = MASTER;
#endif
    }

    return (usbstate == MASTER);
}

static void keyboard_master_setup(void) {

#ifdef USE_MATRIX_I2C
    i2c_master_init();
#else
    serial_master_init();
#endif
}

static void keyboard_slave_setup(void) {

#ifdef USE_MATRIX_I2C
    i2c_slave_init(SLAVE_I2C_ADDRESS);
#else
    serial_slave_init();
#endif
}

void split_keyboard_setup(void) {
   isLeftHand = is_keyboard_left();

   if (is_helix_master()) {
      keyboard_master_setup();
   } else {
      keyboard_slave_setup();
   }
   sei();
}
