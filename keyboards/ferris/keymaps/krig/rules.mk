LTO_ENABLE = no
VIA_ENABLE = no
BOOTLOADER = rp2040
CONVERT_TO = promicro_rp2040
CONSOLE_ENABLE = yes

SRC += features/custom_shift_keys.c
SRC += features/krig_caps_word.c
SRC += features/swapper.c
SRC += features/layer_lock.c
