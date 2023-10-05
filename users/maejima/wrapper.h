#pragma once
#include "maejima.h"

#define MODTAP_R3(K01, K02, K03, K04, K05) K01, K02, K03, K04, RAG_T(K05)

//      1......, 2......, 3......, 4......, 5......     1......, 2......, 3......, 4......, 5......
#define ____________VI_ARROWS_____________              KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT
#define ______________VI_PG_______________              KC_HOME, KC_PGDN, KC_PGUP,  KC_END

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH

#define _________________NUMROW_15_________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMROW_60_________________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define __________________FUNC_15__________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __________________FUNC_60__________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10
#define _________________FUNC_1115_________________      KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15

#define ______________SHIFT_NUMROW_15______________     S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5)
#define ______________SHIFT_NUMROW_60______________     S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0)

#define __________PARENTHESES_L___________              KC_LBRC, KC_LCBR, KC_LPRN, KC_LABK
#define __________PARENTHESES_R___________              KC_RBRC, KC_RCBR, KC_RPRN, KC_RABK

#ifdef LATEX_ENABLE
#define _________________GREEK_L1__________________     XXXXXXX, TX_SIGM, TX_EPSL,  TX_RHO,  TX_TAU
#define _________________GREEK_L2__________________     TX_ALPH, TX_SIGM, TX_DLTA,  TX_PHI, TX_GAMM
#define _________________GREEK_L3__________________     TX_ZETA,  TX_CHI,  TX_PSI, TX_OMEG, TX_BETA
#define _________________GREEK_R1__________________     TX_UPSL, TX_THET, TX_IOTA, TX_OMCR,   TX_PI
#define _________________GREEK_R2__________________      TX_ETA,   TX_XI, TX_KAPP, TX_LMBD, TX_FRAC
#define _________________GREEK_R3__________________       TX_NU,   TX_MU, XXXXXXX,TG(_GREEK), _______

/*
#define _________________LATEX_L1__________________     XXXXXXX, XXXXXXX, XXXXXXX, TX_RGHT, TX_DFDT
#define _________________LATEX_L2__________________     XXXXXXX, TX_SQRT, XXXXXXX, XXXXXXX, XXXXXXX
#define _________________LATEX_L3__________________     TX_DFDZ, TX_DFDX, XXXXXXX, XXXXXXX, XXXXXXX
#define _________________LATEX_R1__________________     TX_DFDY, XXXXXXX, XXXXXXX, TX_OVLN, XXXXXXX
#define _________________LATEX_R2__________________      TX_HAT, XXXXXXX, XXXXXXX, TX_LEFT, TX_FRAC
#define _________________LATEX_R3__________________     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
*/

#define ______GREEK_LTHUMB_______                       _______,  KC_MEH, TG(_GREEK)
#define ______GREEK_RTHUMB_______                       TX_BSPC,  KC_MEH, _______
#endif

#define ___________ONESHOTMODS____________              OSM(MOD_RSFT),OSM(MOD_RGUI),OSM(MOD_RALT),OSM(MOD_RCTL)


#define __________________BASE_L1__________________     _________________QWERTY_L1_________________
#define __________________BASE_L2__________________     _________________QWERTY_L2_________________
#define __________________BASE_L3__________________     _________________QWERTY_L3_________________

#define __________________BASE_R1__________________     _________________QWERTY_R1_________________
#define __________________BASE_R2__________________     _________________QWERTY_R2_________________
#define __________________BASE_R3__________________        KC_N,    KC_M, KC_COMM,  KC_DOT, RAG_T(KC_SLSH)

#define _____________________6C_BASE_L1_____________________    LALT_T(KC_ESC), __________________BASE_L1__________________
#define _____________________6C_BASE_L2_____________________    LCTL_T(KC_TAB), __________________BASE_L2__________________
#define _____________________6C_BASE_L3_____________________    KC_LSFT, __________________BASE_L3__________________

#define _____________________6C_BASE_R1_____________________    __________________BASE_R1__________________, KC_BSPC
#define _____________________6C_BASE_R2_____________________    __________________BASE_R2__________________, RGUI_T(KC_QUOT)
#define _____________________6C_BASE_R3_____________________    __________________BASE_R3__________________, KC_RSFT

//#define _______BASE_LTHUMB_______                       LGUI_T(KC_LNG2), MO(_LOWER), KC_SPC
#define _______BASE_LTHUMB_______                       LGUI_T(KC_LNG2), LT(_LOWER,KC_TAB), KC_SPC
#define _______BASE_RTHUMB_______                       KC_SPC, MO(_RAISE), RALT_T(KC_LNG1)


#define _________________LOWER_L1__________________     _________________NUMROW_15_________________
#define _________________LOWER_L2__________________     _________________NUMROW_60_________________
#define _________________LOWER_L3__________________     XXXXXXX, XXXXXXX, KC_COMM,  KC_DOT, KC_BSPC

#define _________________LOWER_R1__________________     ______________VI_PG_______________,  KC_EQL
#define _________________LOWER_R2__________________     ____________VI_ARROWS_____________, KC_MINS
#define _________________LOWER_R3__________________     MODTAP_R3(XXXXXXX,  KC_GRV, KC_QUOT, S(KC_1), KC_BSLS)

#define ____________________6C_LOWER_L1_____________________    _______, _________________LOWER_L1__________________
#define ____________________6C_LOWER_L2_____________________    _______, _________________LOWER_L2__________________
#define ____________________6C_LOWER_L3_____________________    _______, _________________LOWER_L3__________________

#define ____________________6C_LOWER_R1_____________________    _________________LOWER_R1__________________, A(KC_BSPC)
#define ____________________6C_LOWER_R2_____________________    _________________LOWER_R2__________________, RGUI_T(KC_GRV)
#define ____________________6C_LOWER_R3_____________________    _________________LOWER_R3__________________, RSFT_T(KC_DEL)

#define ______LOWER_LTHUMB_______                       _______, _______,  KC_ENT
#define ______LOWER_RTHUMB_______                       KC_BSPC, LT(_RAISE,KC_ENT), _______


#define _________________RAISE_L1__________________     _______, __________PARENTHESES_L___________
#define _________________RAISE_L2__________________      KC_TAB, __________PARENTHESES_R___________
#define _________________RAISE_L3__________________     KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH,  KC_EQL

#define _________________RAISE_R1__________________     ______________SHIFT_NUMROW_15______________
#ifdef LATEX_ENABLE
#define _________________RAISE_R2__________________     S(KC_6), S(KC_7), S(KC_8),TG(_GREEK),S(KC_MINS)
#else
#define _________________RAISE_R2__________________     ______________SHIFT_NUMROW_60______________
#endif
#define _________________RAISE_R3__________________     _______, S(KC_GRV), S(KC_QUOT),TG(_GREEK), S(KC_BSLS)

#define ____________________6C_RAISE_L1_____________________    _______, _________________RAISE_L1__________________
#define ____________________6C_RAISE_L2_____________________    _______, _________________RAISE_L2__________________
#define ____________________6C_RAISE_L3_____________________    _______, _________________RAISE_L3__________________

#define ____________________6C_RAISE_R1_____________________    _________________RAISE_R1__________________,  KC_DEL
#define ____________________6C_RAISE_R2_____________________    _________________RAISE_R2__________________, _______
#define ____________________6C_RAISE_R3_____________________    _________________RAISE_R3__________________, _______

#define ______RAISE_LTHUMB_______                       _______, LT(_LOWER,KC_ENT), KC_ESC
#define ______RAISE_RTHUMB_______                        KC_ENT, _______, _______


#define _________________ADJUST_L1_________________     __________________FUNC_15__________________
#define _________________ADJUST_L2_________________     __________________FUNC_60__________________
#define _________________ADJUST_L3_________________     _________________FUNC_1115_________________

#define ____________________6C_ADJUST_L1____________________    _______, _________________ADJUST_L1_________________
#define ____________________6C_ADJUST_L2____________________    _______, _________________ADJUST_L2_________________
#define ____________________6C_ADJUST_L3____________________    _______, _________________ADJUST_L3_________________

#define ____________________6C_ADJUST_R1____________________     KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU
#define ____________________6C_ADJUST_R2____________________     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX
#define ____________________6C_ADJUST_R3____________________     KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX

#define ______ADJUST_LTHUMB______                       _______, _______, _______
#define ______ADJUST_RTHUMB______                       _______, _______, _______
