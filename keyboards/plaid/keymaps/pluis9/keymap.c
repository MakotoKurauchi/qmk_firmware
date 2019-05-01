/* Copyright 2019 Takuya Urakawa (dm9records.com)
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

extern keymap_config_t keymap_config;

enum plaid_layers {
  _QWERTY,
  _EUCALYN,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum plaid_keycodes {
  QWERTY = SAFE_RANGE,
  EUCALYN,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   /  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Alt  | Alt  |Lower |Enter |Space |Raise |`+Alt | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_plaid_grid(
    KC_ESC,             KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,         KC_O,    KC_P,    KC_BSPC,
    LT(_LOWER, KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,         KC_L,    KC_SLSH, LT(_RAISE, KC_MINS),
    KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,      KC_DOT,  KC_UP,   RSFT_T(KC_SCLN),
    KC_LCTL,            KC_LALT, KC_LALT, KC_LALT, LOWER,   KC_ENT,  KC_SPC,  RAISE,   RALT(KC_GRV), KC_LEFT, KC_DOWN, KC_RGHT
),

/* EUCALYN
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   ,  |   .  |   /  |   M  |   R  |   D  |   Y  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   I  |   U  |   G  |   T  |   K  |   S  |   N  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   F  |   B  |   H  |   J  |   L  |  Up  |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Alt  | Alt  |Lower |Enter |Space |Raise |`+Alt | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_EUCALYN] = LAYOUT_plaid_grid(
    KC_ESC,             KC_Q,    KC_W,    KC_COMM, KC_DOT,  KC_SLSH, KC_M,    KC_R,    KC_D,         KC_Y,    KC_P,    KC_BSPC,
    LT(_LOWER, KC_TAB), KC_A,    KC_O,    KC_E,    KC_I,    KC_U,    KC_G,    KC_T,    KC_K,         KC_S,    KC_N,    LT(_RAISE, KC_MINS),
    KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,    KC_B,    KC_H,    KC_J,         KC_L,    KC_UP,   RSFT_T(KC_SCLN),
    KC_LCTL,            KC_LALT, KC_LALT, KC_LALT, LOWER,   KC_ENT,  KC_SPC,  RAISE,   RALT(KC_GRV), KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   |  |   "  |   _  |   +  |   {  |   }  |  F10 |  F11 |  F12 |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapsLk|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_plaid_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_PIPE, KC_DQT,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_F10,  KC_F11,  KC_F12,  _______, _______,
    KC_CLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |   '  |   -  |   =  |   [  |   ]  |  F10 |  F11 |  F12 |PrnScr|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NumLck|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_plaid_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_F10,  KC_F11,  KC_F12,  KC_PSCR, _______,
    KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |Qwerty|Eucaly|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_plaid_grid(
    _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, QWERTY,  EUCALYN, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

void matrix_init_user(void) {
    LED1_LED2_INIT;
}

void led_set_user(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
	} else {
	}
	if (usb_led & (1<<USB_LED_NUM_LOCK)) {
    LED1ON;
	} else {
    LED1OFF;
	}
	if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    LED2ON;
	} else {
    LED2OFF;
	}
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
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
  }
  return true;
}
