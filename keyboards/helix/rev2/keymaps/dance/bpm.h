#ifndef BPM_H
#define BPM_H

#include <stdint.h>

// BPM
#define BPM_COUNT  10  // Count Num
#define BPM_MARGIN  20  // Recognition range（%）

void bpm_record(uint16_t time);
uint8_t bpm_isDancing(void);

#endif
