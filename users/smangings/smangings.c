#include "smangings.h"
#include "personal_song_list.h"

extern rgb_counters_t g_rgb_counters;
extern rgb_config_t rgb_matrix_config;


void matrix_init_user(void) { // Runs boot tasks for keyboard
  clicky_off();
};

//Tap Dance Definitions
void shift_caps_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code(KC_CAPS);
    wait_ms(100); // On Mac caps lock must be pressed for an extended time to register
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

// void led_matrix_custom () {

//   dprintf("DO THE LED BREATHING \n");
//   // led_matrix_set_index_value(C1_1, 0);
//   IS31FL3731_set_value_all(0x0000);
//   dprintf("DID THE LED BREATHING \n");
// }


bool led_matrix_custom() {

  uint16_t time = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 8);
  uint8_t val = scale8(abs8(sin8(time) - 128) * 2, rgb_matrix_config.val);

  for (uint8_t i = 0x24 ; i < 0x72; i++) {
    led_matrix_set_index_value(i, val)
  }
  return 0x72 < DRIVER_LED_TOTAL;
}

