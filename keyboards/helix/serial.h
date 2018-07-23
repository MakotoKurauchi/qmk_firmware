#ifndef SOFT_SERIAL_H
#define SOFT_SERIAL_H

#include <stdbool.h>

// ////////////////////////////////////////////
// Need Soft Serial defines in serial_config.h
// ////////////////////////////////////////////
// ex.
//  #define SERIAL_PIN_DDR DDRD
//  #define SERIAL_PIN_PORT PORTD
//  #define SERIAL_PIN_INPUT PIND
//  #define SERIAL_PIN_MASK _BV(PD?)   ?=0,2
//  #define SERIAL_PIN_INTERRUPT INT?_vect  ?=0,2

// Soft Serial Transaction Descriptor
typedef struct _SSTD_t  {
    uint8_t *status;
    uint8_t initiator2target_buffer_size;
    uint8_t *initiator2target_buffer;
    uint8_t target2initiator_buffer_size;
    uint8_t *target2initiator_buffer;
} SSTD_t;

// initiator is transaction start side
void soft_serial_initiator_init(SSTD_t *sstd_table);
// target is interrupt accept side
void soft_serial_target_init(SSTD_t *sstd_table);

// initiator resullt
#define TRANSACTION_END 0
#define TRANSACTION_NO_RESPONSE 0x1
#define TRANSACTION_DATA_ERROR  0x2
#ifndef SERIAL_USE_MULTI_TRANSACTION
int  soft_serial_transaction(void);
#else
int  soft_serial_transaction(int sstd_index);
#endif

// target status
// *SSTD_t.status has
//   initiator:
//       TRANSACTION_END
//    or TRANSACTION_NO_RESPONSE
//    or TRANSACTION_DATA_ERROR
//   target:
//       TRANSACTION_DATA_ERROR
//    or TRANSACTION_ACCEPTED
#define TRANSACTION_ACCEPTED 0x4
#ifdef SERIAL_USE_MULTI_TRANSACTION
int  soft_serial_get_and_clean_status(int sstd_index);
#endif


// debug flags
#define SERIAL_DEBUG_MODE_WATCH_OUTMODE 0x1
#define SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE 0x2
#define SERIAL_DEBUG_MODE_WATCH_BYTEWIDTH 0x4
#define SERIAL_DEBUG_MODE_WATCH_SYNC 0x8
#define SERIAL_DEBUG_MODE_WATCH_IOCHG 0x10
#define SERIAL_DEBUG_MODE_WATCH_PARITY 0x20
#define SERIAL_DEBUG_MODE_WATCH_RETRY 0x40

//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_OUTMODE
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_BYTEWIDTH
//#define SERIAL_DEBUG_MODE (SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE|SERIAL_DEBUG_MODE_WATCH_BYTEWIDTH)
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_SYNC
//#define SERIAL_DEBUG_MODE (SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE|SERIAL_DEBUG_MODE_WATCH_SYNC)
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_IOCHG
//#define SERIAL_DEBUG_MODE (SERIAL_DEBUG_MODE_WATCH_IOCHG|SERIAL_DEBUG_MODE_WATCH_SYNC)
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_PARITY
//#define SERIAL_DEBUG_MODE SERIAL_DEBUG_MODE_WATCH_RETRY

// Helix keyboard unused port (for Logic analyzer or oscilloscope)
#ifdef SERIAL_DEBUG_MODE
#define SERIAL_DBGPIN_DDR DDRB
#define SERIAL_DBGPIN_PORT PORTB
#define SERIAL_DBGPIN_MASK _BV(PB5)
#endif

#ifdef SERIAL_DEBUG_MODE
 #define serial_debug_init() SERIAL_DBGPIN_DDR |= SERIAL_DBGPIN_MASK
#else
 #define serial_debug_init()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_OUTMODE
 #define debug_output_mode() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
 #define debug_input_mode()  SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
 #define debug_output_mode()
 #define debug_input_mode()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_RCVSAMPLE
  #define debug_recvsample() SERIAL_DBGPIN_PORT ^= SERIAL_DBGPIN_MASK
#else
  #define debug_recvsample()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_BYTEWIDTH
  #define debug_bytewidth_start()  SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
  #define debug_bytewidth_end()  SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
  #define debug_bytewidth_start()
  #define debug_bytewidth_end()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_SYNC
  #define debug_sync_start() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
  #define debug_sync_end() SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
  #define debug_sync_start()
  #define debug_sync_end()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_IOCHG
  #define debug_iochg_on() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
  #define debug_iochg_off() SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
  #define debug_iochg_on()
  #define debug_iochg_off()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_PARITY
  #define debug_parity_on() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
  #define debug_parity_off() SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
  #define debug_parity_on()
  #define debug_parity_off()
#endif

#if SERIAL_DEBUG_MODE & SERIAL_DEBUG_MODE_WATCH_RETRY
  #define debug_retry_on() SERIAL_DBGPIN_PORT |= SERIAL_DBGPIN_MASK
  #define debug_retry_off() SERIAL_DBGPIN_PORT &= ~SERIAL_DBGPIN_MASK
#else
  #define debug_retry_on()
  #define debug_retry_off()
#endif

#define SYNC_DEBUG_MODE 0
#if SYNC_DEBUG_MODE == 0
#define debug_dummy_delay_recv()
#define debug_dummy_delay_send()
#endif
#if SYNC_DEBUG_MODE == 1
#define debug_dummy_delay_recv()  _delay_us(3); _delay_sub_us(2)
#define debug_dummy_delay_send()
#endif
#if SYNC_DEBUG_MODE == 2
#define debug_dummy_delay_recv()
#define debug_dummy_delay_send()  _delay_us(3); _delay_sub_us(2)
#endif

#endif /* SOFT_SERIAL_H */
