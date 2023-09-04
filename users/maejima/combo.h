#pragma once
#include "maejima.h"

enum combos {
    COMBO_LSFT,
    COMBO_LCTL,
    COMBO_LGUI,
    COMBO_LALT,
    COMBO_RSFT,
    COMBO_RCTL,
    COMBO_RGUI,
    COMBO_RALT,
//    COMBO_LSFT_LOWER,
//    COMBO_LCTL_LOWER,
//    COMBO_LGUI_LOWER,
//    COMBO_LALT_LOWER,
//    COMBO_RSFT_LOWER,
//    COMBO_RCTL_LOWER,
//    COMBO_RGUI_LOWER,
//    COMBO_RALT_LOWER,
//    COMBO_LSFT_RAISE,
//    COMBO_LCTL_RAISE,
//    COMBO_LGUI_RAISE,
//    COMBO_LALT_RAISE,
//    COMBO_RSFT_RAISE,
//    COMBO_RCTL_RAISE,
//    COMBO_RGUI_RAISE,
//    COMBO_RALT_RAISE,
    // more here...

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

// define keys that make up combos
const uint16_t PROGMEM l_index  [3];
const uint16_t PROGMEM l_middle [3];
const uint16_t PROGMEM l_ring   [3];
const uint16_t PROGMEM l_pinky  [3];
const uint16_t PROGMEM r_index  [3];
const uint16_t PROGMEM r_middle [3];
const uint16_t PROGMEM r_ring   [3];
const uint16_t PROGMEM r_pinky  [3];
//const uint16_t PROGMEM l_index_lower  [3];
//const uint16_t PROGMEM l_middle_lower [3];
//const uint16_t PROGMEM l_ring_lower   [3];
//const uint16_t PROGMEM l_pinky_lower  [3];
//const uint16_t PROGMEM r_index_lower  [3];
//const uint16_t PROGMEM r_middle_lower [3];
//const uint16_t PROGMEM r_ring_lower   [3];
//const uint16_t PROGMEM r_pinky_lower  [3];
//const uint16_t PROGMEM l_index_raise  [3];
//const uint16_t PROGMEM l_middle_raise [3];
//const uint16_t PROGMEM l_ring_raise   [3];
//const uint16_t PROGMEM l_pinky_raise  [3];
//const uint16_t PROGMEM r_index_raise  [3];
//const uint16_t PROGMEM r_middle_raise [3];
//const uint16_t PROGMEM r_ring_raise   [3];
//const uint16_t PROGMEM r_pinky_raise  [3];

// map combo names to their keys and the key they trigger
combo_t key_combos[COMBO_LENGTH];
