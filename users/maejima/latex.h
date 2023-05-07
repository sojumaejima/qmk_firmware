#pragma once

#include QMK_KEYBOARD_H

typedef struct tex_macro{
    char *str;
    uint8_t len;
    uint8_t left;
}tex_macro_t;

tex_macro_t gr_l[24];
tex_macro_t gr_u[24];
tex_macro_t gr_v[24];
tex_macro_t tex_cmd[11];
tex_macro_t tex_cmd_ctrl[11];

enum custom_keycodes {
    TX_ALPH = SAFE_RANGE,
    TX_BETA,
    TX_GAMM,
    TX_DLTA,
    TX_EPSL,
    TX_ZETA,
    TX_ETA,
    TX_THET,
    TX_IOTA,
    TX_KAPP,
    TX_LMBD,
    TX_MU,
    TX_NU,
    TX_XI,
    TX_OMCR,
    TX_PI,
    TX_RHO,
    TX_SIGM,
    TX_TAU,
    TX_UPSL,
    TX_PHI,
    TX_CHI,
    TX_PSI,
    TX_OMEG,
    TX_TILD,
    TX_HAT,
    TX_OVLN,
    TX_SQRT,
    TX_FRAC,
    TX_DFDT,
    TX_DFDX,
    TX_DFDY,
    TX_DFDZ,
    TX_REF,
    TX_CITE,
    TX_BSPC,
    NEW_SAFE_RANGE
};

bool process_latex(uint16_t keycode, keyrecord_t *record);
