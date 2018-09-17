/* Copyright 2017 Wunder
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
#include "xd75.h"

// Layer shorthand
#define _QWERTY 0
#define _EUCALYN 1
#define _FN 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EUCALYN,
  FN,
  EISU,
  KANA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 7      | 8      | 9      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | 4      | 5      | 6      | Y      | U      | I      | O      | P      | -      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      | 1      | 2      | 3      | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | [      | 0      | ]      | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | ADJUST | `      | LALT   | GUI    | EISU   |      ENTER      | FN     |      SPACE      | KANA   | LEFT   | DOWN   | UP     | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = {
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_KP_7, KC_KP_8, KC_KP_9, KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_KP_4, KC_KP_5, KC_KP_6, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_MINS },
  { KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_KP_1, KC_KP_2, KC_KP_3, KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOTE },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_KP_0, KC_RBRC, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
  { MO(_ADJUST), KC_GRV, KC_LALT, KC_LGUI, EISU, KC_ENT,  KC_ENT,  TT(_FN), KC_SPC,  KC_SPC, KANA,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT },
 },

 /* EUCALYN
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | ESC    | 1      | 2      | 3      | 4      | 5      | INSERT | HOME   | PGUP   | 6      | 7      | 8      | 9      | 0      | BACKSP |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
  * | TAB    | Q      | W      | ,      | .      | /      | DELETE | END    | PGDOWN | M      | R      | D      | Y      | P      | '      |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
  * | LCTRL  | A      | O      | E      | I      | U      | PRSCRN | NUMLOCK| SCLOCK | G      | T      | K      | S      | N      | -      |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
  * | LSHIFT | Z      | X      | C      | V      | F      | [      | CAPS   | ]      | B      | H      | J      | L      | UP     | RSHIFT |
  * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
  * | ADJUST | `      | LALT   | GUI    | EISU   |      ENTER      | FN     |      SPACE      | KANA   | ;      | LEFT   | DOWN   | RIGHT  |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */

 [_EUCALYN] = {
   { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_INS,  KC_HOME, KC_PGUP, KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC },
   { KC_TAB,  KC_Q,    KC_W,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,  KC_END,  KC_PGDN, KC_M,   KC_R,   KC_D,    KC_Y,    KC_P,    KC_QUOTE },
   { KC_LCTL, KC_A,    KC_O,    KC_E,    KC_I,    KC_U,    KC_PSCR, KC_NLCK, KC_SLCK, KC_G,   KC_T,   KC_K,    KC_S,    KC_N,    KC_MINS },
   { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,    KC_LBRC, KC_CAPS, KC_RBRC, KC_B,   KC_H,   KC_J,    KC_L,    KC_UP,   KC_RSFT },
   { MO(_ADJUST), KC_GRV, KC_LALT, KC_LGUI, EISU, KC_ENT,  KC_ENT,  TT(_FN), KC_SPC,  KC_SPC, KANA,   KC_SCLN, KC_LEFT, KC_DOWN, KC_RGHT },
  },

/* FN
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | 7      | 8      | 9      | F6     | F7     | F8     | F9     | F10    | DELETE |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | BS     | 7      | 8      | 9      | =      | 4      | 5      | 6      | F11    | F12    |        | +      | |      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | 4      | 5      | 6      | -      | 1      | 2      | 3      |        |        |        | =      | \      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | 0      | 1      | 2      | 3      | +      |        | 0      |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | .      |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = {
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_KP_7, KC_KP_8, KC_KP_9, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL },
  { _______, KC_BSPC, KC_KP_7, KC_KP_8, KC_KP_9, KC_PEQL, KC_KP_4, KC_KP_5, KC_KP_6, KC_F11,  KC_F12,  _______, KC_PLUS, KC_PIPE, _______ },
  { _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______, _______, KC_EQL,  KC_BSLS, _______ },
  { _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, _______, KC_KP_0, _______, _______, _______, _______, _______, _______, _______ },
  { _______, KC_PDOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
},

/* ADJUST
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | RESET  |        |        |        |        |        |        |        | QWERTY |EUCALYN |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        | Mac    |        |        |        | Win    |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        | RGB ON | HUE+   | SAT+   | VAL+   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        | MODE   | HUE-   | SAT-   | VAL-   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_ADJUST] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, RESET,   _______, _______, _______, _______, _______, _______, _______, QWERTY,  EUCALYN, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, AG_NORM, _______, _______, _______, AG_SWAP, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SMOD, RGB_HUD, RGB_SAD, RGB_VAD },
},

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case EUCALYN:
            if (record->event.pressed) {
              set_single_persistent_default_layer(_EUCALYN);
            }
            return false;
            break;
        case EISU:
          if (record->event.pressed) {
            if(keymap_config.swap_lalt_lgui==false){
              register_code(KC_LANG2);
            }else{
              SEND_STRING(SS_LALT("`"));
            }
          } else {
            unregister_code(KC_LANG2);
          }
          return false;
          break;
        case KANA:
          if (record->event.pressed) {
            if(keymap_config.swap_lalt_lgui==false){
              register_code(KC_LANG1);
            }else{
              SEND_STRING(SS_LALT("`"));
            }
          } else {
            unregister_code(KC_LANG1);
          }
          return false;
          break;
      }
    return true;
};

void matrix_scan_user(void) {
#ifdef RGBLIGHT_ENABLE
#ifdef PROTOCOL_LUFA
  switch (USB_DeviceState) {
    case DEVICE_STATE_Configured:
      rgblight_mode(rgblight_get_mode());
      break;
    case DEVICE_STATE_Unattached:
    case DEVICE_STATE_Suspended:
    case DEVICE_STATE_Powered:
    case DEVICE_STATE_Default:
    case DEVICE_STATE_Addressed:
      rgblight_effect_breathing(100);
      //rgblight_setrgb(0,0,0);
  }
#endif
#endif
}
