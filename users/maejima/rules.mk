MOUSEKEY_ENABLE = yes    # Mouse keys
#PERMISSIVE_HOLD = yes
HOLD_ON_OTHER_KEY_PRESS = yes

LTO_ENABLE      = yes

CAPS_WORD_ENABLE = yes

SRC += maejima.c
SRC += latex.c

ifdef COMBO_ENABLE
SRC += combo.c
endif
