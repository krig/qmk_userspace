# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = yes
ORYX_ENABLE = no
SPACE_CADET_ENABLE = yes
AUDIO_ENABLE = yes
SRC += matrix.c
SRC += features/custom_shift_keys.c
SRC += features/krig_caps_word.c
SRC += features/layer_lock.c
