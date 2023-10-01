// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "maejima.h"

#define LAYOUT_wrapper(...)     LAYOUT(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_wrapper(
             KC_ESC, _________________NUMROW_15_________________,                   _________________NUMROW_60_________________,    KC_GRV,
            _____________________6C_BASE_L1_____________________,                   _____________________6C_BASE_R1_____________________,
            _____________________6C_BASE_L2_____________________,                   _____________________6C_BASE_R2_____________________,
            _____________________6C_BASE_L3_____________________, RGB_TOG, KC_MUTE, _____________________6C_BASE_R3_____________________,
            MT(MOD_LALT|MOD_LSFT,KC_NO), _______BASE_LTHUMB_______,                 _______BASE_RTHUMB_______,  KC_RCTL
            ),

    [_LOWER] = LAYOUT_wrapper(
            _______, _______, _______, _______, _______, _______,                   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
            ____________________6C_LOWER_L1_____________________,                   ____________________6C_LOWER_R1_____________________,
            ____________________6C_LOWER_L2_____________________,                   ____________________6C_LOWER_R2_____________________,
            ____________________6C_LOWER_L3_____________________, _______, _______, ____________________6C_LOWER_R3_____________________,
            MT(MOD_LALT|MOD_LSFT,KC_NO), ______LOWER_LTHUMB_______,                 ______LOWER_RTHUMB_______,  KC_RCTL
            ),

    [_RAISE] = LAYOUT_wrapper(
            _______, RGB_MOD, RGB_SAI, RGB_VAI, RGB_HUI, RGB_SPI,                   _______, _______, _______, _______, _______, _______,
            ____________________6C_RAISE_L1_____________________,                   ____________________6C_RAISE_R1_____________________,
            ____________________6C_RAISE_L2_____________________,                   ____________________6C_RAISE_R2_____________________,
            ____________________6C_RAISE_L3_____________________, _______, _______, ____________________6C_RAISE_R3_____________________,
            MT(MOD_LALT|MOD_LSFT,KC_NO), ______RAISE_LTHUMB_______,                 ______RAISE_RTHUMB_______,  KC_RCTL
            ),

    [_ADJUST] = LAYOUT_wrapper(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            ____________________6C_ADJUST_L1____________________,                   ____________________6C_ADJUST_R1____________________,
            ____________________6C_ADJUST_L2____________________,                   ____________________6C_ADJUST_R2____________________,
            ____________________6C_ADJUST_L3____________________, _______, _______, ____________________6C_ADJUST_R3____________________,
            MT(MOD_LALT|MOD_LSFT,KC_NO), ______ADJUST_LTHUMB______,                 ______ADJUST_RTHUMB______,  KC_RCTL
            ),

#ifdef LATEX_ENABLE
    [_GREEK] = LAYOUT_wrapper(
            _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
            _______, _________________GREEK_L1__________________,                   _________________GREEK_R1__________________, _______,
            _______, _________________GREEK_L2__________________,                   _________________GREEK_R2__________________,    TX_MU,
            _______, _________________GREEK_L3__________________, _______, _______, _________________GREEK_R3__________________, _______,
            MT(MOD_LALT|MOD_LSFT,KC_NO), _______, _______, TG(_GREEK),              TX_BSPC, _______, _______,  KC_RCTL
            ),
    /*
       [_LATEX] = LAYOUT_wrapper(
       _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______,
       _______, _________________LATEX_L1__________________,                                       _________________LATEX_R1__________________, _______,
       _______, _________________LATEX_L2__________________,                                       _________________LATEX_R2__________________, TX_TILD,
       _______, _________________LATEX_L3__________________, _______,                     _______, _________________LATEX_R3__________________, _______,
       MT(MOD_LALT|MOD_LSFT,KC_NO), _______, _______, TG(_LATEX),                                  TX_BSPC, _______, _______,  KC_RCTL
       ),
  */
#endif
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            if (index == 0) {
                if (clockwise) {
                    rgb_matrix_increase_hue();
                } else {
                    rgb_matrix_decrease_hue();
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            break;
        case 1:
            if (index == 0) {
                if (clockwise) {
                    rgb_matrix_increase_speed();
                } else {
                    rgb_matrix_decrease_speed();
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            break;
    }
    return false;
}
#endif
/*
bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}
*/
