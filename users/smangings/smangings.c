#include "smangings.h"
// #include "personal_song_list.h"

// ===============================================
// CAPS LOCK Tap-Dance Functions
// ===============================================
void shift_to_caps_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code(KC_CAPS);
    wait_ms(100); // On Mac caps lock must be pressed for an extended time to register
  } else {
    register_code(KC_RSFT);
  }
}

void shift_to_caps_up (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    unregister_code(KC_CAPS);
  } else {
    unregister_code(KC_RSFT);
  }
}

/*
bool led_matrix_custom() {

  uint16_t time = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 8);
  uint8_t val = scale8(abs8(sin8(time) - 128) * 2, rgb_matrix_config.val);

  for (uint8_t i = 0x24 ; i < 0x72; i++) {
    led_matrix_set_index_value(i, val)
  }
  return 0x72 < DRIVER_LED_TOTAL;
}
*/


// ===============================================
// Space Cadet Funtions
// ===============================================
void space_cadet_left (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) { // Press (
    register_code(KC_LSFT);
    register_code(KC_9);
  } else if (state->count == 2) { // Press {
    register_code(KC_LSFT);
    register_code(KC_LBRC);
  } else if (state->count == 3) { // Press [
    register_code(KC_LBRC);
  } else {
    register_code(KC_RSFT);
  }
}

void space_cadet_left_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) { // Un-Press (
    unregister_code(KC_LSFT);
    unregister_code(KC_9);
  } else if (state->count == 2) { // Un-Press {
    unregister_code(KC_LSFT);
    unregister_code(KC_LBRC);
  } else if (state->count == 3) { // Un-Press [
    unregister_code(KC_LBRC);
  } else {
    unregister_code(KC_RSFT);
  }
}

void space_cadet_right (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) { // Press )
    register_code(KC_LSFT);
    register_code(KC_0);
  } else if (state->count == 2) { // Press }
    register_code(KC_LSFT);
    register_code(KC_RBRC);
  } else if (state->count >= 3) { // Press ]
    register_code(KC_RBRC);
  }
}

void space_cadet_right_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) { // Un-Press )
    unregister_code(KC_LSFT);
    unregister_code(KC_0);
  } else if (state->count == 2) { // Un-Press }
    unregister_code(KC_LSFT);
    unregister_code(KC_RBRC);
  } else if (state->count >= 3) { // Un-Press ]
    unregister_code(KC_RBRC);
  }
}

// ===============================================
// Play Songs with Custom Keycodes
// ===============================================
#ifdef AUDIO_ENABLE
  float song_basketcase[][2] = SONG(BASKET_CASE);
  float song_ode_to_joy[][2] = SONG(ODE_TO_JOY);
  float song_rock_a_bye_baby[][2] = SONG(ROCK_A_BYE_BABY);
  float song_doe_a_deer[][2] = SONG(DOE_A_DEER);
  float song_scale[][2] = SONG(MUSIC_SCALE_SOUND);
  float song_coin[][2] = SONG(COIN_SOUND);
  float song_one_up[][2] = SONG(ONE_UP_SOUND);
  float song_sonic_ring[][2] = SONG(SONIC_RING);
  float song_zelda_puzzle[][2] = SONG(ZELDA_PUZZLE);
  float song_imperial_march[][2] = SONG(IMPERIAL_MARCH);
  float song_rick_roll[][2] = SONG(RICK_ROLL);
  float song_zelda_treasure[][2] = SONG(ZELDA_TREASURE);
#endif

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
            case S_RROLL:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_rick_roll);
                }
                return false;
            case S_ZELDT:
                if (record->event.pressed) {
                    stop_all_notes();
                    PLAY_SONG(song_zelda_treasure);
                }
                return false;
        #endif
    }
    return true;
}
