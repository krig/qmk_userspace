#pragma once

#include "quantum.h"

/*
 * To use:
 * Add to rules.mk:
 * SRC += features/krig_caps_word.c
 *
 * Add
 *
 * bool caps_word_press_user(uint16_t keycode) {
 *   return krig_caps_word_press(keycode);
 * }
 */

void caps_word_set_krig(bool active);
bool caps_word_press_krig(uint16_t keycode);
