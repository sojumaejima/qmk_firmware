/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

char gr_l[24][9] = {
    "\\alpha",
    "\\beta",
    "\\gamma",
    "\\delta",
    "\\epsilon",
    "\\zeta",
    "\\eta",
    "\\theta",
    "\\iota",
    "\\kappa",
    "\\lambda",
    "\\mu",
    "\\nu",
    "\\xi",
    "o",
    "\\pi",
    "\\rho",
    "\\sigma",
    "\\tau",
    "\\upsilon",
    "\\phi",
    "\\chi",
    "\\psi",
    "\\omega"
};

char gr_u[24][9] = {
    "A",
    "B",
    "\\Gamma",
    "\\Delta",
    "E",
    "Z",
    "H",
    "\\Theta",
    "I",
    "K",
    "\\Lambda",
    "M",
    "N",
    "\\Xi",
    "O",
    "\\Pi",
    "P",
    "\\Sigma",
    "T",
    "\\Upsilon",
    "\\Phi",
    "X",
    "\\Psi",
    "\\Omega"
};

char gr_v[24][12] = {
    "\\alpha",
    "\\beta",
    "\\gamma",
    "\\partial",
    "\\varepsilon",
    "\\zeta",
    "\\eta",
    "\\vartheta",
    "\\iota",
    "\\kappa",
    "\\lambda",
    "\\mu",
    "\\nu",
    "\\xi",
    "o",
    "\\pi",
    "\\varrho",
    "\\sigma",
    "\\tau",
    "\\upsilon",
    "\\varphi",
    "\\chi",
    "\\psi",
    "\\omega"
};

enum custom_keycodes {
    TG_ALPH = SAFE_RANGE,
    TG_BETA,
    TG_GAMM,
    TG_DLTA,
    TG_EPSL,
    TG_ZETA,
    TG_ETA,
    TG_THET,
    TG_IOTA,
    TG_KAPP,
    TG_LMBD,
    TG_MU,
    TG_NU,
    TG_XI,
    TG_OMCR,
    TG_PI,
    TG_RHO,
    TG_SIGM,
    TG_TAU,
    TG_UPSL,
    TG_PHI,
    TG_CHI,
    TG_PSI,
    TG_OMEG,
    TX_REF,
    TX_CITE,
    TM_FRAC,
    TM_TILD,
    TM_SQRT,
    TM_DFDT,
    TM_DFDX,
    TM_DFDY,
    TM_DFDZ,
    TM_MTRX,
    TM_BMRX,
    TM_PMRX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      LALT_T(KC_ESC),KC_Q, KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_T(KC_TAB),KC_A, KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, RGUI_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, RAG_T(KC_SLSH),  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                LGUI_T(KC_LNG2),   MO(1),  KC_SPC,     KC_SPC,   MO(2), RALT_T(KC_LNG1)
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_EQL,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_MINS, RGUI_T(KC_GRV),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_COMM,  KC_DOT, KC_BSPC,                      XXXXXXX, XXXXXXX, XXXXXXX, S(KC_1), RAG_T(KC_BSLS), RSFT_T(KC_DEL),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_ENT,    KC_BSPC, LT(2,KC_ENT),_______ 
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_LABK,                      S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),A(KC_BSPC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN, KC_RABK,                      S(KC_6), S(KC_7), S(KC_8),   TG(4),   TG(5), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH,  KC_EQL,                     OSM(MOD_RSFT),OSM(MOD_RGUI),OSM(MOD_RALT),OSM(MOD_RCTL), XXXXXXX, _______,
                             _______, LT(1,KC_ENT), KC_ESC,  _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,     KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT(
      _______, XXXXXXX, XXXXXXX, TG_EPSL,  TG_RHO,  TG_TAU,     TG_UPSL, TG_THET, TG_IOTA, TG_OMCR,   TG_PI, _______,
      _______, TG_ALPH, TG_SIGM, TG_DLTA,  TG_PHI, TG_GAMM,      TG_ETA,   TG_XI, TG_KAPP, TG_LMBD, TM_FRAC, TM_TILD,
      _______, TG_ZETA,  TG_CHI,  TG_PSI, TG_OMEG, TG_BETA,       TG_NU,   TG_MU, XXXXXXX, XXXXXXX, _______, _______,
                                 _______, _______,   TG(4),     _______, _______, _______
    ),

  [5] = LAYOUT(
      _______, XXXXXXX, XXXXXXX, XXXXXXX,  TX_REF, TM_DFDT,     TM_DFDY, XXXXXXX, XXXXXXX, XXXXXXX, TM_PMRX, _______,
      _______, XXXXXXX, TM_SQRT, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TM_FRAC, TM_TILD,
      _______, TM_DFDZ, TM_DFDX, TX_CITE, XXXXXXX, TM_BMRX,     XXXXXXX, TM_MTRX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                 _______, _______,   TG(5),     _______, _______, _______
    )
};

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, 1, 2, 3);
  return state;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    switch (keycode) {
        case TG_ALPH:
        case TG_BETA:
        case TG_GAMM:
        case TG_DLTA:
        case TG_EPSL:
        case TG_ZETA:
        case TG_ETA:
        case TG_THET:
        case TG_IOTA:
        case TG_KAPP:
        case TG_LMBD:
        case TG_MU:
        case TG_NU:
        case TG_XI:
        case TG_OMCR:
        case TG_PI:
        case TG_RHO:
        case TG_SIGM:
        case TG_TAU:
        case TG_UPSL:
        case TG_PHI:
        case TG_CHI:
        case TG_PSI:
        case TG_OMEG:
            if (record->event.pressed) {
                int c = keycode - TG_ALPH;
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {  // Is shift held?
                    del_mods(MOD_MASK_SHIFT);  // Temporarily delete shift.
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    send_string(gr_u[c]);
                    set_mods(mods);
                } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {  // Is ctrl held?
                    del_mods(MOD_MASK_CTRL);  // Temporarily delete ctrl.
                    del_oneshot_mods(MOD_MASK_CTRL);
                    send_string(gr_v[c]);
                    set_mods(mods);
                } else {
                    send_string(gr_l[c]);
                }
                layer_move(0);
            return false;
            }
        case TX_REF:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("(\\ref{})");
                for (int i = 0; i<2; i++){
                    tap_code(KC_LEFT);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TX_CITE:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\cite{}");
                for (int i = 0; i<1; i++){
                    tap_code(KC_LEFT);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TM_FRAC:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\frac{}{}");
                for (int i = 0; i<3; i++){
                    tap_code(KC_LEFT);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TM_TILD:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\tilde{}");
                for (int i = 0; i<1; i++){
                    tap_code(KC_LEFT);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TM_SQRT:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\sqrt{}");
                for (int i = 0; i<1; i++){
                    tap_code(KC_LEFT);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TM_DFDT:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\frac{\\partial }{\\partial t}");
                for (int i = 0; i<13; i++){
                    tap_code(KC_LEFT);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TM_DFDX:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\frac{\\partial }{\\partial x}");
                for (int i = 0; i<13; i++){
                    tap_code(KC_LEFT);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TM_DFDY:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\frac{\\partial }{\\partial y}");
                for (int i = 0; i<13; i++){
                    tap_code(KC_LEFT);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TM_DFDZ:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\frac{\\partial }{\\partial z}");
                for (int i = 0; i<13; i++){
                    tap_code(KC_LEFT);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TM_MTRX:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\begin{matrix}\n\t\n\\end{matrix}");
                for (int i = 0; i<1; i++){
                    tap_code(KC_UP);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TM_BMRX:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\begin{bmatrix}\n\t\n\\end{bmatrix}");
                for (int i = 0; i<1; i++){
                    tap_code(KC_UP);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;
        case TM_PMRX:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                send_string("\\begin{pmatrix}\n\t\n\\end{pmatrix}");
                for (int i = 0; i<1; i++){
                    tap_code(KC_UP);
                }
                set_mods(mods);
                layer_move(0);
            }
            return false;

    }

//    if (!process_caps_word(keycode, record)) { return false; }

#ifdef OLED_ENABLE
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
#endif // OLED_ENABLE
  return true;
}
