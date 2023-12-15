VIA_ENABLE = no
OLED_ENABLE = yes
# OLED_DRIVER = SSD1306
MOUSEKEY_ENABLE = no
LTO_ENABLE = yes
CONSOLE_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes

SRC += features/custom_shift_keys.c
SRC += features/krig_caps_word.c
