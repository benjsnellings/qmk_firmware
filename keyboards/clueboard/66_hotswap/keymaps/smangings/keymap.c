#include QMK_KEYBOARD_H
#include "smangings.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
#define _BM 0

#define _FL 3
#define _CL 4

#define _ML 8
#define _LD 9

void matrix_init_user(void) { // Runs boot tasks for keyboard
  clicky_off();
};

//Tap Dance Declarations
enum {
  TD_SHIFT = 0,
  SCL = 1,
  SCR = 2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer
   */
[_BM] = LAYOUT(
  KC_GESC,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,      KC_BSPC,           KC_LSCR, \
  KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,                KC_DEL,  \
  MO(_FL),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,      KC_ENT,                            \
  KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,      KC_RSFT,             KC_UP,        \
  KC_LCTL,KC_LGUI,KC_LALT,               LGUI_T(KC_SPC),RCTL_T(KC_SPC),            KC_RGUI,KC_RALT,MO(_FL),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
  KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,      KC_DEL,            KC_PGUP, \
  _______,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,_______,TD(SCL),TD(SCR),_______,MO(_CL),_______,_______,_______,                KC_PGDN, \
  MO(_FL),_______,KC_VOLD,KC_VOLU,KC_MUTE,_______,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,KC_MINS,_______,    _______,                             \
  _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,        KC_HOME,         \
  KC_SCT1,KC_SCT2,_______,                _______,_______,                        _______,_______,MO(_FL),_______,_______,KC_END ,KC_INS),

  /* Keymap _CL: Control layer
   */
[_CL] = LAYOUT(
  _______,DF(_BM),DF(_BM),_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,            _______, \
  _______,_______,_______,_______,  RESET,  _______,_______,_______,_______,_______,MO(_CL),_______,_______,_______,             _______, \
  MO(_FL),_______,_______,  DEBUG,_______,_______,_______,_______,_______,TG(_LD),_______,_______,    _______,                            \
  _______,        _______,_______,_______,_______,_______,_______,TG(_ML),_______,_______,_______,        _______,        _______,        \
  _______,_______,_______,                _______,_______,                        _______,_______,MO(_FL),_______,_______,_______,_______),

  /* Keymap _ML: Music layer
   */
[_ML] = LAYOUT(
  XXXXXXX,S_BSKTC,S_ODEJY,S_RCKBY,S_DOEDR,S_SCALE,S_ONEUP, S_COIN,S_SONIC,S_ZELDA,S_ZELDT,S_IMPER,XXXXXXX,   XXXXXXX,             XXXXXXX, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                XXXXXXX, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    S_RROLL,                             \
  XXXXXXX,        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,          CK_UP,         \
  TG(_ML),XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,CK_RST ,CK_OFF ,CK_DOWN,CK_ON),

  /* Keymap _LD: LED control layer
   */
[_LD] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   BL_TOGG,             BL_INC, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                BL_DEC, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,                            \
  XXXXXXX,        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,        XXXXXXX,        \
  TG(_LD),XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX),
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Right Shift, thrice for Caps Lock
  [TD_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_to_caps_down, shift_to_caps_up),
  [SCL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_cadet_left, space_cadet_left_reset),
  [SCR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_cadet_right, space_cadet_right_reset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_music(keycode, record) && process_record_secrets(keycode, record);
}
