#pragma once

#include "quantum.h"

#undef ZELDA_TREASURE
#define ZELDA_TREASURE \
    Q__NOTE(_A4 ), \
    Q__NOTE(_AS4), \
    Q__NOTE(_B4 ), \
    HD_NOTE(_C5 )

// Turn into capslock with pressed three times
void shift_to_caps_down (qk_tap_dance_state_t *state, void *user_data);
void shift_to_caps_up (qk_tap_dance_state_t *state, void *user_data);

// Space Cadet tap dance 1=() 2={} 3=[]
void space_cadet_left (qk_tap_dance_state_t *state, void *user_data);
void space_cadet_left_reset (qk_tap_dance_state_t *state, void *user_data);
void space_cadet_right (qk_tap_dance_state_t *state, void *user_data);
void space_cadet_right_reset (qk_tap_dance_state_t *state, void *user_data);

// Make Songs playable
// enum custom_keycodes;

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
    S_IMPER,
    S_RROLL,
    S_ZELDT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record);
