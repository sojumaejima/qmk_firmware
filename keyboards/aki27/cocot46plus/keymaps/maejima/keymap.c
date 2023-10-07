/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"
#include "maejima.h"


// Defines names for use in layer keycodes and the keymap
//enum layer_number {
//    _BASE = 0,
//    _LOWER = 1,
//    _RAISE = 2,
//    _TRACKBALL = 3,
//    _Layer4 = 4,
//    _Layer5 = 5,
//    _Layer6 = 6
//};
enum layer_kb {
    _TRACK= _LAYER_SAFE_RANGE,
};


#define LW_MHEN LT(1,KC_LNG2)  // lower
#define RS_HENK LT(2,KC_LNG1)  // raise
#define DEL_ALT ALT_T(KC_DEL)

#define LAYOUT_wrapper(...)     LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      _____________________6C_BASE_L1_____________________,                                       _____________________6C_BASE_R1_____________________,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      _____________________6C_BASE_L2_____________________,                                       _____________________6C_BASE_R2_____________________,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      _____________________6C_BASE_L3_____________________,                                       _____________________6C_BASE_R3_____________________,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      MT(MOD_LALT|MOD_LSFT,KC_NO), _______BASE_LTHUMB_______, KC_MS_BTN1,             KC_MS_BTN2, _______BASE_RTHUMB_______,  KC_RCTL,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_LOWER] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      ____________________6C_LOWER_L1_____________________,                                       ____________________6C_LOWER_R1_____________________,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      ____________________6C_LOWER_L2_____________________,                                       ____________________6C_LOWER_R2_____________________,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      ____________________6C_LOWER_L3_____________________,                                       ____________________6C_LOWER_R3_____________________,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      MT(MOD_LALT|MOD_LSFT,KC_NO), ______LOWER_LTHUMB_______, KC_MS_BTN4,             KC_MS_BTN5, ______LOWER_RTHUMB_______,  KC_RCTL,
                                                                 KC_VOLD, TG(_TRACK),  KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_RAISE] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      ____________________6C_RAISE_L1_____________________,                                       ____________________6C_RAISE_R1_____________________,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      ____________________6C_RAISE_L2_____________________,                                       ____________________6C_RAISE_R2_____________________,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      ____________________6C_RAISE_L3_____________________,                                       ____________________6C_RAISE_R3_____________________,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      MT(MOD_LALT|MOD_LSFT,KC_NO), ______RAISE_LTHUMB_______, KC_MS_BTN4,             KC_MS_BTN5, ______RAISE_RTHUMB_______,  KC_RCTL,
                                                                 KC_VOLD, TG(_TRACK),  KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_ADJUST] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      ____________________6C_ADJUST_L1____________________,                                       ____________________6C_ADJUST_R1____________________,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      ____________________6C_ADJUST_L2____________________,                                       ____________________6C_ADJUST_R2____________________,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      ____________________6C_ADJUST_L3____________________,                                       ____________________6C_ADJUST_R3____________________,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      MT(MOD_LALT|MOD_LSFT,KC_NO), ______ADJUST_LTHUMB______, KC_MS_BTN1,             KC_MS_BTN2, ______ADJUST_RTHUMB______,  KC_RCTL,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_TRACK] = LAYOUT_wrapper(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                                       SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                                       SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD,                                       SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      MT(MOD_LALT|MOD_LSFT,KC_NO), ______ADJUST_LTHUMB______, KC_MS_BTN1,             KC_MS_BTN2, ______ADJUST_RTHUMB______,  KC_RCTL,
                                                                 KC_PGUP, TG(_TRACK),  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
#ifdef LATEX_ENABLE

  [_GREEK] = LAYOUT_wrapper(
  //,-----------------------------------------------------.                                     ,-----------------------------------------------------.
      _______, _________________GREEK_L1__________________,                                       _________________GREEK_R1__________________, _______,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      _______, _________________GREEK_L2__________________,                                       _________________GREEK_R2__________________,   TX_MU,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      _______, _________________GREEK_L3__________________,                                       _________________GREEK_R3__________________, _______,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      MT(MOD_LALT|MOD_LSFT,KC_NO), _______, _______, TG(_GREEK), KC_MS_BTN1,          KC_MS_BTN2, TX_BSPC, _______, _______,  KC_RCTL,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'                   `--------------------------'
    ),
/*
  [_LATEX] = LAYOUT_wrapper(
  //,-----------------------------------------------------.                                     ,-----------------------------------------------------.
      _______, _________________LATEX_L1__________________,                                       _________________LATEX_R1__________________, _______,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      _______, _________________LATEX_L2__________________,                                       _________________LATEX_R2__________________, TX_TILD,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      _______, _________________LATEX_L3__________________,                                       _________________LATEX_R3__________________, _______,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      MT(MOD_LALT|MOD_LSFT,KC_NO), _______, _______, TG(_LATEX), KC_MS_BTN1,          KC_MS_BTN2, TX_BSPC, _______, _______,  KC_RCTL,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'                   `--------------------------'
    ),
*/
#endif
};

keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }

    return true;
}


void matrix_scan_user(void) {

    if (encoder1_ccw.pressed) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (encoder1_cw.pressed) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

}



layer_state_t layer_state_set_keymap(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        rgblight_sethsv_range(HSV_RED, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _ADJUST:
        rgblight_sethsv_range(HSV_PURPLE, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _TRACK:
        rgblight_sethsv_range(HSV_GREEN, 0, 2);
        cocot_set_scroll_mode(false);
        break;
#ifdef LATEX_ENABLE
    case _GREEK:
        rgblight_sethsv_range(HSV_YELLOW, 0, 2);
        cocot_set_scroll_mode(false);
        break;
//    case _LATEX:
//        rgblight_sethsv_range(HSV_ORANGE, 0, 2);
//        cocot_set_scroll_mode(false);
//        break;
#endif
//    case _Layer5:
//        rgblight_sethsv_range(HSV_CYAN, 0, 2);
//        cocot_set_scroll_mode(false);
//        break;
    default:
        rgblight_sethsv_range( 0, 0, 0, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    }
    rgblight_set_effect_range( 2, 10);
      return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

