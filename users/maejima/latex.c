#ifdef LATEX_ENABLE
#include <latex.h>


tex_macro_t latex_codes[6][25] = {
    {
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
        {"\\phi",       4, 0},
        {"\\chi",       4, 0},
        {"\\psi",       4, 0},
        {"\\omega",     6, 0},
        {"\\frac{}{}",  9, 3},
    },
    {
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
        {"\\Omega",     6, 0},
        {"",0, 0},
    },
    {
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"\\partial",   8, 0},
        {"\\varepsilon",11, 0},
        {"",0, 0},
        {"\\left",      5, 0},
        {"\\vartheta",  9, 0},
        {"\\infty",     6, 0},
        {"",0, 0},
        {"\\right",     6, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"\\varpi",     6, 0},
        {"\\varrho",    7, 0},
        {"\\varsigma",  9, 0},
        {"",0, 0},
        {"",0, 0},
        {"\\varphi",    8, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
    },
    {
        {"",0, 0},
        {"",0, 0},
        {"\\rangle",7, 0},
        {"\\right}",7, 0},
        {"\\left{",6, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"\\left(",6, 0},
        {"\\right]",7, 0},
        {"\\langle",7, 0},
        {"",0, 0},
        {"\\right)",7, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"\\left[",6, 0},
    },
    {
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"\\frac{\\partial }{\\partial z}", 28,13},
        {"\\hat{}",                         6, 1},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"\\tilde{}",                       8, 1},
        {"",0, 0},
        {"",0, 0},
        {"\\overline{}",                    11, 1},
        {"",0, 0},
        {"",0, 0},
        {"\\sqrt{}",                        7, 1},
        {"\\frac{\\partial }{\\partial t}", 28,13},
        {"\\frac{\\partial }{\\partial y}", 28,13},
        {"",0, 0},
        {"\\frac{\\partial }{\\partial x}", 28,13},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
    },
    {
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"\\frac{\\partial }{\\partial \\zeta}", 32,17},
        {"\\widehat{}",                         10, 5},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"\\widetilde{}",                       12, 5},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
        {"\\sqrt[]{}",                        9, 3},
        {"\\frac{\\partial }{\\partial \\tau}", 31,16},
        {"\\frac{\\partial }{\\partial \\eta}", 31,16},
        {"",0, 0},
        {"\\frac{\\partial }{\\partial \\xi}", 30,15},
        {"",0, 0},
        {"",0, 0},
        {"",0, 0},
    },
};

static uint8_t lens[NUM_BACKSPACE];
static uint8_t lefts[NUM_BACKSPACE];
static uint8_t pos = 0;

uint8_t get_latex_mods(const uint8_t mods, const uint8_t c){
    uint8_t latex_mods = 0;
    if ((mods & MOD_MASK_ALT) && (latex_codes[latex_mods|1<<2][c].len > 0)){ // Is alt held?
        latex_mods |= 1<<2;

        if ((mods & (MOD_MASK_CTRL|MOD_MASK_SHIFT)) && (latex_codes[latex_mods|1<<0][c].len > 0)) {  // Is ctrl or shift held?
            latex_mods |= 1<<0;
        }
        return latex_mods;
    }

    if ((mods & MOD_MASK_CTRL) && (latex_codes[latex_mods|1<<1][c].len > 0)){ // Is ctrl held?
        latex_mods |= 1<<1;
    }
    if ((mods & MOD_MASK_SHIFT) && (latex_codes[latex_mods|1<<0][c].len > 0)){ // Is shift held?
        latex_mods |= 1<<0;
    }
    if ((mods & MOD_MASK_CTRL) && (mods & MOD_MASK_SHIFT) && (latex_codes[latex_mods|((1<<2)-1)][c].len > 0)){ // Is shift held?
        latex_mods |= ((1<<2)-1);
    }
        
    return latex_mods;
}


bool process_latex(uint16_t keycode, keyrecord_t *record){
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();
    uint8_t c;

    if (record->event.pressed) {
        clear_mods();
        clear_oneshot_mods();
        switch (keycode) {
            case TX_ALPH ... TX_FRAC:
                c = keycode - TX_ALPH;
                uint8_t latex_mods = get_latex_mods(mods|oneshot_mods, c);

                send_string(latex_codes[latex_mods][c].str);
                for (uint8_t i=0; i<latex_codes[latex_mods][c].left; i++){
                    tap_code(KC_LEFT);
                }
                lens[pos] = latex_codes[latex_mods][c].len;
                lefts[pos] = latex_codes[latex_mods][c].left;
                pos++;
                if (pos >= NUM_BACKSPACE){
                    pos = 0;
                }
                break;
            case TX_BSPC:
                if (pos > 0){
                    pos--;
                }else{
                    pos = NUM_BACKSPACE-1;
                }
                for (uint8_t i=0; i<lefts[pos]; i++){
                    tap_code(KC_RIGHT);
                }
                for (uint8_t i=0; i<lens[pos]; i++){
                    tap_code(KC_BSPC);
                }
                lefts[pos] = 0;
                lens[pos] = 0;
                break;
        }
        set_mods(mods);
        layer_move(0);
    }
    return false;
}
//bool process_latex_macro(uint16_t keycode, keyrecord_t *record);
#endif
