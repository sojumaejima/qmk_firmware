#include <latex.h>

tex_macro_t gr_l[24] = {
    {"\\alpha",     6, 0},
    {"\\beta",      5, 0},
    {"\\gamma",     6, 0},
    {"\\delta",     6, 0},
    {"\\epsilon",   8, 0},
    {"\\zeta",      5, 0},
    {"\\eta",       4, 0},
    {"\\theta",     6, 0},
    {"\\iota",      5, 0},
    {"\\kappa",     6, 0},
    {"\\lambda",    7, 0},
    {"\\mu",        3, 0},
    {"\\nu",        3, 0},
    {"\\xi",        3, 0},
    {"o",           1, 0},
    {"\\pi",        3, 0},
    {"\\rho",       4, 0},
    {"\\sigma",     6, 0},
    {"\\tau",       4, 0},
    {"\\upsilon",   8, 0},
    {"\\phi",       5, 0},
    {"\\chi",       4, 0},
    {"\\psi",       4, 0},
    {"\\omega",     6, 0}
};

tex_macro_t gr_u[24] = {
    {"A",           1, 0},
    {"B",           1, 0},
    {"\\Gamma",     6, 0},
    {"\\Delta",     6, 0},
    {"E",           1, 0},
    {"Z",           1, 0},
    {"H",           1, 0},
    {"\\Theta",     6, 0},
    {"I",           1, 0},
    {"K",           1, 0},
    {"\\Lambda",    7, 0},
    {"M",           1, 0},
    {"N",           1, 0},
    {"\\Xi",        3, 0},
    {"O",           1, 0},
    {"\\Pi",        3, 0},
    {"P",           1, 0},
    {"\\Sigma",     6, 0},
    {"T",           1, 0},
    {"\\Upsilon",   8, 0},
    {"\\Phi",       4, 0},
    {"X",           1, 0},
    {"\\Psi",       4, 0},
    {"\\Omega",     6, 0}
};

tex_macro_t gr_v[24] = {
    {"\\alpha",     6, 0},
    {"\\beta",      5, 0},
    {"\\gamma",     6, 0},
    {"\\partial",   8, 0},
    {"\\varepsilon",11, 0},
    {"\\zeta",      5, 0},
    {"\\eta",       4, 0},
    {"\\vartheta",  9, 0},
    {"\\iota",      5, 0},
    {"\\kappa",     6, 0},
    {"\\lambda",    7, 0},
    {"\\mu",        3, 0},
    {"\\nu",        3, 0},
    {"\\xi",        3, 0},
    {"o",           1, 0},
    {"\\pi",        3, 0},
    {"\\varrho",    7, 0},
    {"\\sigma",     6, 0},
    {"\\tau",       4, 0},
    {"\\upsilon",   8, 0},
    {"\\varphi",    8, 0},
    {"\\chi",       4, 0},
    {"\\psi",       4, 0},
    {"\\omega",     6, 0}
};

tex_macro_t tex_cmd[11] = {
    {"\\tilde{}",                       8, 1},
    {"\\hat{}",                         6, 1},
    {"\\overline{}",                    11, 1},
    {"\\sqrt{}",                        7, 1},
    {"\\frac{}{}",                      9, 3},
    {"\\frac{\\partial }{\\partial t}", 28,13},
    {"\\frac{\\partial }{\\partial x}", 28,13},
    {"\\frac{\\partial }{\\partial y}", 28,13},
    {"\\frac{\\partial }{\\partial z}", 28,13},
    {"\\ref{}",                         6, 1},
    {"\\cite{}",                        7, 1}
};

tex_macro_t tex_cmd_ctrl[11] = {
    {"\\widetilde{}",                   12, 1},
    {"\\widehat{}",                     10, 1},
    {"\\overline{}",                    11, 1},
    {"\\sqrt{}",                        7, 1},
    {"\\frac{}{}",                      9, 3},
    {"\\frac{\\partial }{\\partial \\tau}",   31,16},
    {"\\frac{\\partial }{\\partial \\xi}",    30,15},
    {"\\frac{\\partial }{\\partial \\eta}",   31,16},
    {"\\frac{\\partial }{\\partial \\zeta}",  32,17},
    {"\\ref{}",                         6, 1},
    {"\\cite{}",                        7, 1}
};

static uint8_t len = 0;
static uint8_t left = 0;

bool process_latex(uint16_t keycode, keyrecord_t *record){
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();
    int c;
    if (record->event.pressed) {
        switch (keycode) {
            case TX_ALPH ... TX_OMEG:
                c = keycode - TX_ALPH;
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {  // Is shift held?
                    del_mods(MOD_MASK_SHIFT);  // Temporarily delete shift.
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    send_string(gr_u[c].str);
                    len = gr_u[c].len;
                    left = gr_u[c].left;
                } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {  // Is ctrl held?
                    del_mods(MOD_MASK_CTRL);  // Temporarily delete ctrl.
                    del_oneshot_mods(MOD_MASK_CTRL);
                    send_string(gr_v[c].str);
                    len = gr_v[c].len;
                    left = gr_v[c].left;
                } else {
                    send_string(gr_l[c].str);
                    len = gr_l[c].len;
                    left = gr_l[c].left;
                }
                set_mods(mods);
                break;
            case TX_TILD ... TX_CITE:
                c = keycode - TX_TILD;
                if ((mods | oneshot_mods) & MOD_MASK_CTRL) {  // Is ctrl held?
                    del_mods(MOD_MASK_CTRL);  // Temporarily delete ctrl.
                    del_oneshot_mods(MOD_MASK_CTRL);
                    send_string(tex_cmd_ctrl[c].str);
                    len = tex_cmd_ctrl[c].len;
                    left = tex_cmd_ctrl[c].left;
                } else {
                    send_string(tex_cmd[c].str);
                    len = tex_cmd[c].len;
                    left = tex_cmd[c].left;
                }
                for (uint8_t i=0; i<left; i++){
                    tap_code(KC_LEFT);
                }
                set_mods(mods);
                break;
            case TX_BSPC:
                for (uint8_t i=0; i<left; i++){
                    tap_code(KC_RIGHT);
                }
                for (uint8_t i=0; i<len; i++){
                    tap_code(KC_BSPC);
                }
                left = 0;
                len = 0;
                break;
        }
        layer_move(0);
    }
    return false;
}
//bool process_latex_macro(uint16_t keycode, keyrecord_t *record);
