#pragma once

#include QMK_KEYBOARD_H
#include "latex.h"
#include "wrapper.h"
#ifdef COMBO_ENABLE
#include "combo.h"
#endif

enum userspace_layers {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
#ifdef LATEX_ENABLE
    _LATEX,
#endif
    _LAYER_SAFE_RANGE,
};
