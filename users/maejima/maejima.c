#include "maejima.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}


__attribute__ ((weak))
layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef LATEX_ENABLE
        case TX_ALPH ... TX_BSPC:
            return process_latex(keycode, record);
#endif
    }
    return process_record_keymap(keycode, record);
}
