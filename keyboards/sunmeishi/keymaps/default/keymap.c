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
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  YUSHAKOBO = SAFE_RANGE,
  YUSHAURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    RGB_MOD,   RGB_HUI,  YUSHAKOBO, \
    RGB_RMOD,  RGB_HUD,  YUSHAURL, \
    KC_MUTE
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case YUSHAKOBO:
      if (record->event.pressed) {
        // when keycode YUSHAKOBO is pressed
        SEND_STRING("Yushakobo is a keyboard shop in Japan");
      } else {
        // when keycode YUSHAKOBO is released
      }
      break;
    case YUSHAURL:
      if (record->event.pressed) {
        // when keycode YUSHAURL is pressed
        SEND_STRING("https://yushakobo.jp/" SS_TAP(X_ENTER));
      } else {
        // when keycode YUSHAURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }
}
