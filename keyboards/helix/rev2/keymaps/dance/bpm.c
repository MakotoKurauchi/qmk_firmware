#include "bpm.h"
#include <stdint.h>
#include <stdlib.h>
#include "timer.h"
#include "quantum.h"

uint16_t bpm_buf[BPM_COUNT] = {100};
uint16_t bpm_before_millis = 0;
uint8_t bpm_buf_c = 0;
uint8_t bpm_is_danving = 0;
uint8_t bpm_state = 0;

void bpm_record(uint16_t time){
  // record time
  if(time < bpm_before_millis){
    bpm_buf[bpm_buf_c] = time + 65535 - bpm_before_millis;
  }else{
    bpm_buf[bpm_buf_c] = time - bpm_before_millis;
  }
  bpm_before_millis = time;
  bpm_buf_c ++;
  if (bpm_buf_c == BPM_COUNT) bpm_buf_c = 0;

  // check bpm
  uint16_t bpm_avr = 0;
  for (uint8_t i = 0; i < BPM_COUNT; i++) {
    bpm_avr += bpm_buf[i];
print_val_dec(bpm_buf[i]);
  }
  bpm_avr = bpm_avr / BPM_COUNT;
print_val_dec(bpm_avr);
  uint16_t margin = bpm_avr / 100 * BPM_MARGIN;
print_val_dec(margin);
  for (uint8_t i = 0; i < BPM_COUNT; i++) {
    uint16_t tmp = bpm_buf[i] - bpm_avr;
print_val_dec(abs(tmp));

    if (abs(tmp) > margin) {
      if(bpm_state){
        for (uint8_t i = 0; i < BPM_COUNT; i++) {
          bpm_buf[i] = 0 ;
        }
        bpm_state = 0;
      }
      return;
    }
  }
  if(bpm_state==1){
    bpm_state = 2;
  }else{
    bpm_state = 1;
  }
}

uint8_t bpm_isDancing(void){
  if((timer_read() - bpm_before_millis) > 1000){
    for (uint8_t i = 0; i < BPM_COUNT; i++) {
      bpm_buf[i] = 0 ;
    }
    return 0;
  }

  return bpm_state;
}
