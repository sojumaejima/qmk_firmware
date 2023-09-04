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
//const uint16_t PROGMEM l_index_lower[] = {KC_4, KC_9, COMBO_END};
//const uint16_t PROGMEM l_middle_lower[] = {KC_3, KC_8, COMBO_END};
//const uint16_t PROGMEM l_ring_lower[] = {KC_2, KC_7, COMBO_END};
//const uint16_t PROGMEM l_pinky_lower[] = {KC_1, KC_6, COMBO_END};
//const uint16_t PROGMEM r_index_lower[] = {KC_DOWN, KC_PGDN, COMBO_END};
//const uint16_t PROGMEM r_middle_lower[] = {KC_UP, KC_PGUP, COMBO_END};
//const uint16_t PROGMEM r_ring_lower[] = {KC_RGHT, KC_END, COMBO_END};
//const uint16_t PROGMEM r_pinky_lower[] = {KC_MINS, KC_EQL, COMBO_END};
//const uint16_t PROGMEM l_index_raise[] = {KC_LPRN, KC_RPRN, COMBO_END};
//const uint16_t PROGMEM l_middle_raise[] = {KC_LCBR, KC_RCBR, COMBO_END};
//const uint16_t PROGMEM l_ring_raise[] = {KC_LBRC, KC_RBRC, COMBO_END};
//const uint16_t PROGMEM l_pinky_raise[] = {KC_Q, KC_TAB, COMBO_END};
//const uint16_t PROGMEM r_index_raise[] = {S(KC_2), S(KC_7), COMBO_END};
//const uint16_t PROGMEM r_middle_raise[] = {S(KC_3), S(KC_8), COMBO_END};
//#ifdef LATEX_ENABLE
//const uint16_t PROGMEM r_ring_raise[] = {S(KC_4), S(KC_9), COMBO_END};
//const uint16_t PROGMEM r_pinky_raise[] = {S(KC_5), S(KC_0), COMBO_END};
//#else
//const uint16_t PROGMEM r_ring_raise[] = {S(KC_4), TG(_GREEK), COMBO_END};
//const uint16_t PROGMEM r_pinky_raise[] = {S(KC_5), TG(_LATEX), COMBO_END};
//#endif

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
//    [COMBO_LCTL_LOWER] = COMBO(l_index_lower, KC_LCTL),
//    [COMBO_LSFT_LOWER] = COMBO(l_middle_lower, KC_LSFT),
//    [COMBO_LGUI_LOWER] = COMBO(l_ring_lower, KC_LGUI),
//    [COMBO_LALT_LOWER] = COMBO(l_pinky_lower, KC_LALT),
//    [COMBO_RCTL_LOWER] = COMBO(r_index_lower, KC_RCTL),
//    [COMBO_RSFT_LOWER] = COMBO(r_middle_lower, KC_RSFT),
//    [COMBO_RGUI_LOWER] = COMBO(r_ring_lower, KC_RGUI),
//    [COMBO_RALT_LOWER] = COMBO(r_pinky_lower, KC_RALT),
//    [COMBO_LCTL_RAISE] = COMBO(l_index_raise, KC_LCTL),
//    [COMBO_LSFT_RAISE] = COMBO(l_middle_raise, KC_LSFT),
//    [COMBO_LGUI_RAISE] = COMBO(l_ring_raise, KC_LGUI),
//    [COMBO_LALT_RAISE] = COMBO(l_pinky_raise, KC_LALT),
//    [COMBO_RCTL_RAISE] = COMBO(r_index_raise, KC_RCTL),
//    [COMBO_RSFT_RAISE] = COMBO(r_middle_raise, KC_RSFT),
//    [COMBO_RGUI_RAISE] = COMBO(r_ring_raise, KC_RGUI),
//    [COMBO_RALT_RAISE] = COMBO(r_pinky_raise, KC_RALT),
};
