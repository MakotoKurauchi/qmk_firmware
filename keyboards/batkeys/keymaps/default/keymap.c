#include "batkeys.h"

#define ____ KC_TRNS
#define XXXX KC_NO

// for MacOS
#define NEXTTAB ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define PREVTAB ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)

enum LAYER {
  TOP,
  LOWER,
  RAISE,
  MEDIA 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [TOP] = {
    { KC_Q,        KC_W,      KC_E,          KC_R,      KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P},
    { LT(MEDIA,    KC_A),     KC_S,          KC_D,      KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,            LT(MEDIA, KC_SCLN)},
    { CTL_T(KC_Z), KC_X,      KC_C,          KC_V,      KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   CTL_T(KC_SLSH)},
    { 
      KC_LGUI,     MO(LOWER), SFT_T(KC_SPC), KC_BSPC,   KC_LCTL,
      KC_LALT,     KC_TAB,    SFT_T(KC_ENT), MO(RAISE), KC_ESC
    }
  },

  [LOWER] = {
    {KC_EXLM,      KC_AT,     KC_HASH,       KC_DLR,    KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN},
    {KC_F1,        KC_F2,     KC_F3,         KC_F4,     KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR,  KC_RCBR},
    {KC_F7,        KC_F8,     KC_F9,         KC_F10,    KC_F11,  KC_F12,  KC_TILD, KC_PIPE, KC_QUOT,  ____},
    {KC_RGUI,      ____,      ____,          KC_DEL,    KC_RCTL, KC_RALT, ____,    ____,    KC_LANG1, ____},
  },

  [RAISE] = {
    {KC_1,         KC_2,      KC_3,          KC_4,      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0},
    {KC_F1,        KC_F2,     KC_F3,         KC_F4,     KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC,  KC_RBRC},
    {KC_F7,        KC_F8,     KC_F9,         KC_F10,    KC_F11,  KC_F12,  KC_GRV,  KC_BSLS, KC_DQT,   ____},
    {KC_RGUI,      KC_LANG2,  ____,          KC_DEL,    KC_RCTL, KC_RALT, ____,    ____,    ____,     ____},
  },

  [MEDIA] = {
    {PREVTAB,      KC_WH_U,   KC_MS_U,       KC_WH_D,   ____,    KC_HOME,  KC_PGDN, KC_UP,   KC_PGUP,  NEXTTAB},
    {____,         KC_MS_L,   KC_MS_D,       KC_MS_R,   ____,    KC_END,   KC_LEFT, KC_DOWN, KC_RIGHT, ____},
    {____,         ____,      ____,          ____,      KC_MPRV, KC_MPLY,  KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU},
    {____,         KC_BTN2,   KC_BTN1,       ____,      ____,    RESET,   ____,    ____,    ____,     ____}
  }
};

//const uint16_t PROGMEM fn_actions[] = {
//
//};
//
//const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
//{
//  // MACRODOWN only works in this function
//      switch(id) {
//        case 0:
//          if (record->event.pressed) {
//            register_code(KC_RSFT);
//          } else {
//            unregister_code(KC_RSFT);
//          }
//        break;
//      }
//    return MACRO_NONE;
//};
//
//
//void matrix_init_user(void) {
//
//}
//
//void matrix_scan_user(void) {
//
//}
//
//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  return true;
//}
//
//void led_set_user(uint8_t usb_led) {
//
//}
