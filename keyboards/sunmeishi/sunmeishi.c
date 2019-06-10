/* Copyright 2019 MakotoKurauchi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "sunmeishi.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

/*

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  led_set_user(usb_led);
}

*/

#include <avr/pgmspace.h>
//#include "i2c.h"
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#include "pca9956.h"
#include "i2cmaster.h"

// led driver address
#define LED_ADDR        0x3F
// led iref
#define KEYLED_DEF_IREF 50
#define KEYLED_CTRL_IREF 2
#define KEYLED_MAX_IREF 100

uint8_t ledt[3];
uint8_t ledp[] = {2,3,1,4,0,5,6};

extern rgblight_config_t rgblight_config;

void rgblight_set(void) {
    if (!rgblight_config.enable) {
        for (uint8_t i = 0; i < RGBLED_NUM; i++) {
            led[i].r = 0;
            led[i].g = 0;
            led[i].b = 0;
        }
    }
	PCA9956_iref_all(LED_ADDR, KEYLED_DEF_IREF);

  for (uint8_t i = 0; i < RGBLED_NUM; i++) {
    ledt[0] = led[ledp[i]].r;
    ledt[1] = led[ledp[i]].g;
    ledt[2] = led[ledp[i]].b;
    PCA9956_pwm(LED_ADDR, i*3, ledt, 3);
  }
    //i2c_send(0xb0, (uint8_t*)led, 3 * RGBLED_NUM);
}
#endif

void matrix_init_kb(void) {
#ifdef RGBLIGHT_ENABLE
	i2c_init();
#endif
}
