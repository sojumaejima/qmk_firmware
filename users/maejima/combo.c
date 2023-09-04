#include "maejima.h"
#include "combo.h"

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos
const uint16_t PROGMEM l_index[] = {KC_F, KC_R, COMBO_END};
const uint16_t PROGMEM l_middle[] = {KC_D, KC_E, COMBO_END};
const uint16_t PROGMEM l_ring[] = {KC_S, KC_W, COMBO_END};
const uint16_t PROGMEM l_pinky[] = {KC_A, KC_Q, COMBO_END};
const uint16_t PROGMEM r_index[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM r_middle[] = {KC_K, KC_I, COMBO_END};
const uint16_t PROGMEM r_ring[] = {KC_L, KC_O, COMBO_END};
const uint16_t PROGMEM r_pinky[] = {KC_SCLN, KC_P, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_LCTL] = COMBO(l_index, KC_LCTL),
    [COMBO_LSFT] = COMBO(l_middle, KC_LSFT),
    [COMBO_LGUI] = COMBO(l_ring, KC_LGUI),
    [COMBO_LALT] = COMBO(l_pinky, KC_LALT),
    [COMBO_RCTL] = COMBO(r_index, KC_RCTL),
    [COMBO_RSFT] = COMBO(r_middle, KC_RSFT),
    [COMBO_RGUI] = COMBO(r_ring, KC_RGUI),
    [COMBO_RALT] = COMBO(r_pinky, KC_RALT),
};
