#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define NEXTTAB ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define PREVTAB ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)
#define NEXTWIN ACTION_MODS_KEY(MOD_LGUI, KC_TAB)
#define PREVWIN ACTION_MODS_KEY(MOD_LSFT | MOD_LGUI, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer:
 *
 * .-------------------------------------------------.           .--------------------------------------------------.
 * |        |  1! |   2@ |   3# |   4$ |   5% |      |           |      |   6^ |   7& |   8* |  9(  |  0)  |        |
 * |--------+-----+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | =+     |  Q  |   W  |   E  |   R  |   T  | NTAB |           | PTAB |   Y  |   U  |   I  |   O  |  P   |   -_   |
 * |--------+-----+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ESC    |A L2 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;: L2 |   '"   |
 * |--------+-----+------+------+------+------| Eisu |           | Kana |------+------+------+------+------+--------|
 * | Eisu   |  Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,<  |  .>  |  /?  |  Kana  |
 * `--------+-----+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |     |  Alt |  Cmd |  L1  |                                       |  L1  |  Cmd | Alt  |      |      |
 *   `---------------------------------'                                       `----------------------------------'
 *                                    ,----------------,       ,---------------,
 *                                    |         |      |       |      |        |
 *                             ,------|---------|------|       |------+--------+------.
 *                             |Space |         |      |       |      |        |Enter |
 *                             |/Shift|BackSpace|------|       |------|  Tab   |/Shift|
 *                             |      |         |      |       |      |        |      |
 *                             `-----------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
  [BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_TRNS,         KC_1,             KC_2,      KC_3,      KC_4,     KC_5,    KC_TRNS,
        KC_EQL,          KC_Q,             KC_W,      KC_E,      KC_R,     KC_T,    PREVTAB,
        CTL_T(KC_ESC),   LT(MDIA,KC_A),    KC_S,      KC_D,      KC_F,     KC_G,
        KC_LANG2,        KC_Z,             KC_X,      KC_C,      KC_V,     KC_B,    KC_LANG2,
        KC_TRNS,         KC_TRNS,          KC_LALT,   KC_LGUI,   MO(SYMB),
                                                                           KC_TRNS, KC_TRNS,
                                                                                    KC_TRNS,
                                                            SFT_T(KC_SPC), KC_BSPC, KC_TRNS,
        // right hand
        KC_TRNS,     KC_6,    KC_7,      KC_8,      KC_9,      KC_0,                KC_TRNS,
        NEXTTAB,     KC_Y,    KC_U,      KC_I,      KC_O,      KC_P,                KC_MINS,
                     KC_H,    KC_J,      KC_K,      KC_L,      LT(MDIA,KC_SCLN),    KC_QUOT,
        KC_LANG1,    KC_N,    KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,             KC_LANG1,
                              MO(SYMB),  KC_RGUI,   KC_RALT,   KC_TRNS,             KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TAB, SFT_T(KC_ENT)
    ),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    ~    |   !  |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |   (  |   )  |   `    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   |  |   \  |   +  |   =  |   _  |      |           |      |   -  |   [  |   ]  |   {  |   }  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

  [SYMB] = KEYMAP(
       // left hand
       KC_TRNS,   KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,     KC_F6,
       KC_TRNS,   KC_1,      KC_2,      KC_3,      KC_4,       KC_5,      KC_TRNS,
       KC_TILD,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,     KC_PERC,
       KC_TRNS,   KC_PIPE,   KC_BSLS,   KC_PLUS,   KC_EQL,     KC_UNDS,    KC_TRNS,
       KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    
                                                               KC_TRNS,   KC_TRNS,
                                                                          KC_TRNS,
                                                   KC_TRNS,    KC_TRNS,   KC_TRNS,
       // right hand
       KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,     KC_F12,    KC_TRNS,
       KC_TRNS,   KC_6,      KC_7,      KC_8,      KC_9,       KC_0,      KC_TRNS,
                  KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,    KC_RPRN,   KC_GRV,
       KC_TRNS,   KC_MINS,   KC_LBRC,   KC_RBRC,   KC_LCBR,    KC_RCBR,   KC_TRNS,
                  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
       KC_TRNS,   KC_TRNS,
       KC_TRNS,
       KC_TRNS,   KC_TRNS,   KC_TRNS
  ),


/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | MPRV | MPLY | MNXT | Mute |VolDn |VolUp |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MPRV | MsUp | MNXT | WH_U |      |           |      | Home | PgUp | Up   | PgDn |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Reset  |      |MsLeft|MsDown|MsRght| WH_D |------|           |------| End  | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | BTN3 |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | BTN1 | BTN2 |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
  [MDIA] = KEYMAP(
       KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MPRV, KC_MS_U, KC_MNXT, KC_WH_U, KC_TRNS,
       RESET,   KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_BTN3, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,
       KC_TRNS,  KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, KC_TRNS, KC_TRNS,
                 KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS,   KC_TRNS, KC_TRNS
  ),
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

}
