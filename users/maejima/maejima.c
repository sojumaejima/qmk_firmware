#include "maejima.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TX_ALPH ... TX_BSPC:
            return process_latex(keycode, record);
    }
    return true;
}
