#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
#define _BM 0
#define _BL 1

#define _FL 3
#define _CL 4
#define _I3 5

#define _ML 8
#define _LD 9

#define i3_mod KC_LGUI

void matrix_init_user(void) { // Runs boot tasks for keyboard
  clicky_off();
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable=true;
  // debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

//Tap Dance Declarations
enum {
  TD_SHIFT = 0
};

enum custom_keycodes {
    S_BSKTC = SAFE_RANGE,
    S_ODEJY,
    S_RCKBY,
    S_DOEDR,
    S_SCALE,
    S_ONEUP,
    S_COIN,
    S_SONIC,
    S_ZELDA,
    S_IMPER
};

#ifdef AUDIO_ENABLE
  float song_basketcase[][2] = SONG(BASKET_CASE);
  float song_ode_to_joy[][2]  = SONG(ODE_TO_JOY);
  float song_rock_a_bye_baby[][2]  = SONG(ROCK_A_BYE_BABY);
  float song_doe_a_deer[][2]  = SONG(DOE_A_DEER);
  float song_scale[][2]  = SONG(MUSIC_SCALE_SOUND);
  float song_coin[][2]  = SONG(COIN_SOUND);
  float song_one_up[][2]  = SONG(ONE_UP_SOUND);
  float song_sonic_ring[][2]  = SONG(SONIC_RING);
  float song_zelda_puzzle[][2]  = SONG(ZELDA_PUZZLE);
  float song_imperial_march[][2]  = SONG(IMPERIAL_MARCH);
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = LAYOUT(
  KC_GESC,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,      KC_BSPC,           KC_LSCR, \
  KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,                KC_DEL,  \
  MO(_FL),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,      KC_ENT,                            \
  KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,      TD(TD_SHIFT),       KC_UP,         \
  KC_LCTL,KC_LGUI,KC_LALT,             LM(_I3, i3_mod),KC_SPC,                    KC_RGUI,KC_RALT,MO(_FL),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _BL: Base Layer Mac
   */
[_BM] = LAYOUT(
  KC_GESC,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,      KC_BSPC,           KC_LSCR, \
  KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,                KC_DEL,  \
  MO(_FL),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,      KC_ENT,                            \
  KC_LSFT,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,      TD(TD_SHIFT),        KC_UP,        \
  KC_LCTL,KC_LGUI,KC_LALT,               LGUI_T(KC_SPC),KC_SPC,                    KC_RGUI,KC_RALT,MO(_FL),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   */
[_FL] = LAYOUT(
  KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,      KC_DEL,            KC_PGUP, \
  _______,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,_______,_______,_______,_______,MO(_CL),_______,_______,_______,                KC_PGDN, \
  MO(_FL),_______,KC_VOLD,KC_VOLU,KC_MUTE,_______,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,_______,_______,    _______,                             \
  _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,        KC_PGUP,         \
  _______,_______,_______,                _______,_______,                        _______,_______,MO(_FL),_______,KC_HOME,KC_PGDN,KC_END),

  /* Keymap _CL: Control layer
   */
[_CL] = LAYOUT(
  _______,DF(_BL),DF(_BM),_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,            _______, \
  _______,_______,_______,_______,  RESET,  _______,_______,_______,_______,_______,MO(_CL),_______,_______,_______,             _______, \
  MO(_FL),_______,_______,  DEBUG,_______,_______,_______,_______,_______,TG(_LD),_______,_______,    _______,                            \
  _______,        _______,_______,_______,_______,_______,_______,TG(_ML),_______,_______,_______,        _______,        _______,        \
  _______,_______,_______,                _______,_______,                        _______,_______,MO(_FL),_______,_______,_______,_______),

  /* Keymap _I3:  i3 command layer
   */
[_I3] = LAYOUT(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,             _______, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                _______, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,                             \
  _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,        _______,         \
  _______,_______,_______,                _______,_______,                        _______,_______,_______,_______,_______,_______,_______),

  /* Keymap _ML: Music layer
   */
[_ML] = LAYOUT(
  XXXXXXX,S_BSKTC,S_ODEJY,S_RCKBY,S_DOEDR,S_SCALE,S_ONEUP, S_COIN,S_SONIC,S_ZELDA,S_IMPER,XXXXXXX,XXXXXXX,   XXXXXXX,             XXXXXXX, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                XXXXXXX, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,                             \
  XXXXXXX,        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,          CK_UP,         \
  TG(_ML),XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,CK_RST ,CK_OFF ,CK_DOWN,CK_ON),

  /* Keymap _LD:  LED control layer
   */
[_LD] = LAYOUT(
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   BL_TOGG,             BL_INC, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                BL_DEC, \
  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,    XXXXXXX,                            \
  XXXXXXX,        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,        XXXXXXX,        \
  TG(_LD),XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX),
};

//Tap Dance Definitions
void shift_caps_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code(KC_CAPS);
    wait_ms(100);
  } else {
    register_code(KC_RSFT);
  }
}

void shift_caps_up (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    unregister_code(KC_CAPS);
  } else {
    unregister_code(KC_RSFT);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Right Shift, twice for Caps Lock
  [TD_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_caps_down, shift_caps_up)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        #ifdef AUDIO_ENABLE
            case S_BSKTC:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_basketcase);
                }
                return false;
            case S_ODEJY:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_ode_to_joy);
                }
                return false;
            case S_RCKBY:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_rock_a_bye_baby);
                }
                return false;
            case S_DOEDR:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_doe_a_deer);
                }
                return false;
            case S_SCALE:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_scale);
                }
                return false;
            case S_ONEUP:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_one_up);
                }
                return false;
            case S_COIN:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_coin);
                }
                return false;
            case S_SONIC:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_sonic_ring);
                }
                return false;
            case S_ZELDA:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_zelda_puzzle);
                }
                return false;
            case S_IMPER:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_imperial_march);
                }
                return false;
        #endif
    }
    return true;
}
