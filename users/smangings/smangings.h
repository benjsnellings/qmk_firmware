#pragma once

#include "quantum.h"

// Custom Keycodes
enum custom_keycodes {
    // Music Keycodes
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
    S_ZELDT,

    // Custom Secret Keycodes
    KC_SCT1,
    KC_SCT2
};

// =============================================
// Tapdance Definitions
// =============================================

// Turn on capslock when pressed three times
void shift_to_caps_down (qk_tap_dance_state_t *state, void *user_data);
void shift_to_caps_up (qk_tap_dance_state_t *state, void *user_data);

// Space Cadet tap dance 1=() 2={} 3=[]
void space_cadet_left (qk_tap_dance_state_t *state, void *user_data);
void space_cadet_left_reset (qk_tap_dance_state_t *state, void *user_data);
void space_cadet_right (qk_tap_dance_state_t *state, void *user_data);
void space_cadet_right_reset (qk_tap_dance_state_t *state, void *user_data);

// ===============================================
// Macro Definitions
// ===============================================

// Make Songs playable
bool process_record_music(uint16_t keycode, keyrecord_t *record);

// Macros for secrets
bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
