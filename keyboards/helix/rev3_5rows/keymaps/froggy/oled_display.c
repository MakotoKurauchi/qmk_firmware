/* Copyright 2020 yushakobo
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

 /*
   How to Customize

   $ make helix/rev3_5rows:YOUR_KEYMAP:clean
   $ cp keyboards/helix/rev3_5rows/oled_display.c keyboards/helix/rev3_5rows/keymaps/YOUR_KEYMAP

   $ edit keyboards/helix/rev3_5rows/keymaps/YOUR_KEYMAP/oled_display.c
   $ make helix/rev3_5rows:YOUR_KEYMAP
   $ make helix/rev3_5rows:YOUR_KEYMAP:flash
 */

#include QMK_KEYBOARD_H

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_OPT 2
#define L_FUNC 4
#define L_SYM 8
#define L_NUM 16
#define L_FNLAYER 64
#define L_NUMLAY 128
#define L_NLOWER 136
#define L_NFNLAYER 192
#define L_MOUSECURSOR 256

#ifdef OLED_DRIVER_ENABLE

void render_status(void) {

  // froggy logo
  static const char PROGMEM logo[4][1][17]=
  {
    {
      {0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,0x70,0x71,0x72,0x73,0x74,0}
    },
    {
      {0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,0}
    },
    {
      {0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,0}
    },
    {
      {0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0}
    }
  };

  static const char PROGMEM indctr[8][2][4]=
  {
    // white icon
    {
      {0x60,0x61,0x62,0},
      {0x63,0x64,0}
    },
    {
      {0x80,0x81,0x82,0},
      {0x83,0x84,0}
    },
    {
      {0xa0,0xa1,0xa2,0},
      {0xa3,0xa4,0}
    },
    {
      {0xc0,0xc1,0xc2,0},
      {0xc3,0xc4,0}
    },
    // Black icon
    {
      {0x75,0x76,0x77,0},
      {0x78,0x79,0}
    },
    {
      {0x95,0x96,0x97,0},
      {0x98,0x99,0}
    },
    {
      {0xb5,0xb6,0xb7,0},
      {0xb8,0xb9,0}
    },
    {
      {0xd5,0xd6,0xd7,0},
      {0xd8,0xd9,0}
    },
  };

  int rown = 0;
  int rowf = 0;
  int rowa = 0;
  int rows = 0;

  //Set Indicator icon
  if (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) { rown = 4; } else { rown = 0; }
  if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) { rowa = 4; } else { rowa = 0; }
  if (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) { rows = 4; } else { rows = 0; }
  if (layer_state == L_FUNC) { rowf = 4; }

  oled_write_P(indctr[rown]  [0], false);
  oled_write_P(indctr[rowf]  [1], false);
  oled_write_P(logo  [0]     [0], false);
  oled_write_P(indctr[rown+1][0], false);
  oled_write_P(indctr[rowf+1][1], false);
  oled_write_P(logo  [1]     [0], false);
  oled_write_P(indctr[rowa+2][0], false);
  oled_write_P(indctr[rows+2][1], false);
  oled_write_P(logo  [2]     [0], false);
  oled_write_P(indctr[rowa+3][0], false);
  oled_write_P(indctr[rows+3][1], false);
  oled_write_P(logo  [3]     [0], false);

}

void oled_task_user(void) {
  render_status();
}
#endif
