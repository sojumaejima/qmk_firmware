#include <latex.h>

bool process_greek(uint16_t keycode, keyrecord_t *record){
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();
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
    }
    return false;
}
bool process_latex_macro(uint16_t keycode, keyrecord_t *record);
