// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "maejima.h"

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST,
    _TEXGR
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  LCTL_T(KC_TAB), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RGUI_T(KC_QUOT),
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, RGB_TOG,  KC_MUTE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  RAG_T(KC_SLSH),  KC_RSFT,
                          KC_LALT,    LGUI_T(KC_LNG2), LOWER, KC_SPC,  KC_SPC,   RAISE,   RALT_T(KC_LNG1), KC_RGUI
),

[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_EQL,  KC_DEL,
  _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_MINS, RGUI_T(KC_GRV),
  _______, XXXXXXX, XXXXXXX, KC_COMM,  KC_DOT, KC_BSPC, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_1), RAG_T(KC_BSLS), RSFT_T(KC_DEL),
                             _______, _______, _______, KC_ENT, KC_BSPC,  LT(RAISE,KC_ENT), _______, _______
),

[_RAISE] = LAYOUT(
  _______, RGB_MOD, RGB_SAI, RGB_VAI, RGB_HUI, RGB_SPI,                     _______, _______, _______, _______, _______, _______,
  _______, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_LABK,                      S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),A(KC_BSPC),
  _______, KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN, KC_RABK,                      S(KC_6), S(KC_7), S(KC_8),TG(_TEXGR), XXXXXXX, XXXXXXX,
  _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH,  KC_EQL, _______, _______,OSM(MOD_RSFT),OSM(MOD_RGUI),OSM(MOD_RALT),OSM(MOD_RCTL), XXXXXXX, _______,
                             _______, _______, LT(LOWER,KC_ENT), KC_ESC,  _______, _______, _______, _______
),

[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  ),

[_TEXGR] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______,
  TG(_TEXGR), _______, _______, TX_EPSL,  TX_RHO,  TX_TAU,                  TX_UPSL, TX_THET, TX_IOTA, TX_OMCR,   TX_PI,    _______,
  _______, TX_ALPH, TX_SIGM, TX_DLTA,  TX_PHI, TX_GAMM,                   TX_ETA,   TX_XI, TX_KAPP, TX_LMBD, TX_FRAC, _______,
  _______, TX_ZETA,  TX_CHI,  TX_PSI, TX_OMEG, TX_BETA, _______, _______,  TX_NU,   TX_MU, _______, _______, _______, _______,
                          _______, _______, _______, TG(_TEXGR), TX_BSPC, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
//    const uint8_t mods = get_mods();
//    const uint8_t oneshot_mods = get_oneshot_mods();

    switch (keycode) {
        case TX_ALPH ... TX_BSPC:
            return process_latex(keycode, record);
    }
    return true;
}
