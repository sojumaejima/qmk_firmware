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

combo_t key_combos[COMBO_LENGTH];
