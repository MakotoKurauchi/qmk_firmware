/* Copyright 2017 MakotoKurauchi <http://yushakobo.jp/>
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
#include "alter.h"
#include "keyled.h"
#include "bpm.h"

enum alter_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NumLayers
};

enum alter_keycodes {
  LEDIUP = SAFE_RANGE,
  LEDIDN,
  LEDHUP,
  LEDHDN,
  LEDON,
  LEDOFF,
  DANCE,
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


#ifdef KEYLED_ENABLE

// base color
#define KEYLED_BASE_COLOR_HSV 205
#define KEYLED_CTRL_H 10

uint16_t BaseColorH = KEYLED_BASE_COLOR_HSV;
uint8_t DanceMode = 0;

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | Shift|
 * `------+------+------+------+------+------+-------------+------+------+------+------+------+------'
 *        |Adjust| Esc  | GUI  | Alt  |Lower |Enter |Space |Raise | Left | Down |  Up  |Right |
 *        `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC , \
  MO(_ADJUST),KC_ESC,KC_LGUI, KC_LALT, MO(_LOWER),KC_ENT, KC_SPC, MO(_RAISE),KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      | Bksp |   7  |   8  |   9  |   *  |             |   `  |   ~  |   !  |   @  |   #  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |   /  |   4  |   5  |   6  |   -  |             |   $  |   %  |   ^  |   &  |   |  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |   0  |   1  |   2  |   3  |   +  |             |   _  |   '  |   "  |   =  |   \  |      |
 * `------+------+------+------+------+------+-------------+------+------+------+------+------+------'
 *        |      |      |   .  |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 *        `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  _______, KC_BSPC, KC_7,   KC_8,   KC_9,  KC_ASTR,  KC_GRV,   KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, _______, \
  _______, KC_SLSH, KC_4,   KC_5,   KC_6,  KC_MINS,  KC_DLR,   KC_PERC,   KC_CIRC, KC_AMPR, KC_PIPE, _______, \
  _______, KC_0,    KC_1,   KC_2,   KC_3,  KC_PLUS,  KC_UNDS,  S(KC_QUOT),KC_QUOT, KC_EQL,  KC_BSLS, _______, \
  _______, _______, KC_DOT, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   {  |  F7  |  F8  |  F9  |  F12 |             | PrtSc| Home |  Up  | PgUp |   }  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |   (  |  F4  |  F5  |  F6  |  F11 |             |  Ins | Left | Down | Right|   )  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |   [  |  F1  |  F2  |  F3  |  F10 |             |  Del |  End |      | PgDwn|   ]  |      |
 * `------+------+------+------+------+------+-------------+------+------+------+------+------+------'
 *        |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 *        `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  _______, S(KC_LBRC),KC_F7,   KC_F8,   KC_F9,  KC_F12,  KC_PSCR, KC_HOME, KC_UP,   KC_PGUP, S(KC_RBRC), _______, \
  _______, S(KC_9),   KC_F4,   KC_F5,   KC_F6,  KC_F11,  KC_INS,  KC_LEFT, KC_DOWN, KC_RGHT, S(KC_0),    _______, \
  _______, KC_LBRC,   KC_F1,   KC_F2,   KC_F3,  KC_F10,  KC_DEL,  KC_END,  _______, KC_PGDN, KC_RBRC,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      | Reset|      |      |      |LEDON |             |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      | Dance|      |LEDOFF|             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * `------+------+------+------+------+------+-------------+------+------+------+------+------+------'
 *        |      | CapLk| NumLk| ScrLk|      |      |      |      |LEDHDN|LEDIDN|LEDIUP|LEDHUP|
 *        `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, LEDON,   _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, DANCE,   _______, LEDOFF,  _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_CAPS, KC_NLCK, KC_SLCK, TO(_LOWER), TO(_LOWER), TO(_RAISE), TO(_RAISE), LEDHDN, LEDIDN, LEDIUP, LEDHUP \
)

};

void keyled_layer(uint16_t layer, unsigned int h, float s, float v) {
  uint8_t r, g, b;

  hsv2rgb(h, s, v, &r, &g, &b);
	for (uint8_t i=0; i < MATRIX_ROWS; i++) {
		for (uint8_t j=0; j < MATRIX_COLS; j++) {
      if(pgm_read_word_near(&keymaps[layer][i][j])!=_______){
        keyled_dot(j, i, r, g, b);
      }
		}
	}
}


const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {
  #ifdef KEYLED_ENABLE
  	keyled_fill_hsv(BaseColorH, 1, 1);
  	keyled_set_iref(KEYLED_DEF_IREF);
  #endif
}


uint32_t before_layer_state=1;

void matrix_scan_user(void) {
#ifdef KEYLED_ENABLE
#ifdef PROTOCOL_LUFA
  switch (USB_DeviceState) {
    case DEVICE_STATE_Configured:

      if(before_layer_state != layer_state){

        keyled_fill_hsv(BaseColorH, 1, 1);

        for(uint8_t i=0; i<_NumLayers; i++){
          if( IS_LAYER_ON(i) ){
            keyled_layer(i, BaseColorH+(360/_NumLayers)*i, 1, 1);
          }
        }
        keyled_dot(0, 0, 255, 255, 255);
        keyled_dot(1, 1, 255, 0, 0);
        keyled_dot(2, 1, 0, 255, 0);
        keyled_dot(3, 1, 0, 0, 255);

        before_layer_state = layer_state;
      }

      if(DanceMode){
        uint8_t state= bpm_isDancing();
        if(state){
          if(state==1){
            keyled_fillcheck(255,0,255, 0,0,0);
          }else{
            keyled_fillcheck(0,0,0, 0,255,0);
          }
        }else{
          keyled_fill(0,0,0);
        }
      }

        break;
      case DEVICE_STATE_Unattached:
      case DEVICE_STATE_Suspended:
      case DEVICE_STATE_Powered:
      case DEVICE_STATE_Default:
      case DEVICE_STATE_Addressed:
      default:
        keyled_fill_hsv(0, 0, 0);
    }
#endif
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LEDIUP:
      if (record->event.pressed) {
        #ifdef KEYLED_ENABLE
          keyled_up_iref(KEYLED_CTRL_IREF);
        #endif
      }
      return false;
      break;
    case LEDIDN:
      if (record->event.pressed) {
        #ifdef KEYLED_ENABLE
          keyled_down_iref(KEYLED_CTRL_IREF);
        #endif
      }
      return false;
      break;
    case LEDHUP:
      if (record->event.pressed) {
        #ifdef KEYLED_ENABLE
          BaseColorH += KEYLED_CTRL_H;
          keyled_fill_hsv(BaseColorH, 1, 1);
        #endif
      }
      return false;
      break;
    case LEDHDN:
      if (record->event.pressed) {
        #ifdef KEYLED_ENABLE
          if((BaseColorH - KEYLED_CTRL_H)<0){
            BaseColorH = 360 - KEYLED_CTRL_H ;
          }else{
            BaseColorH -= KEYLED_CTRL_H;
          }
          keyled_fill_hsv(BaseColorH, 1, 1);
        #endif
      }
      return false;
      break;
    case LEDON:
      if (record->event.pressed) {
        #ifdef KEYLED_ENABLE
        keyled_on_iref();
        #endif
      }
      return false;
      break;
    case LEDOFF:
      if (record->event.pressed) {
        #ifdef KEYLED_ENABLE
        keyled_off_iref();
        #endif
      }
      return false;
      break;
    case DANCE:
      if (record->event.pressed) {
        #ifdef KEYLED_ENABLE
          if(DanceMode){
            DanceMode = 0 ;
          }else{
            DanceMode = 1 ;
          }
        #endif
      }
      return false;
      break;
  }

  if (record->event.pressed){
    print_val_dec(record->event.time);
    bpm_record(record->event.time);
  }

  return true;
}

void led_set_user(uint8_t usb_led) {

}
