#include "krig_caps_word.h"

static bool g_caps_word_last_key_was_space = false;

__attribute__ ((weak))
void caps_word_set_keymap(bool active) {}

__attribute__ ((weak))
bool caps_word_press_keymap(uint16_t keycode) {
    return true;
}

void caps_word_set_user(bool active) {
    caps_word_set_keymap(active);
    if (active) {
        g_caps_word_last_key_was_space = false;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    if (!caps_word_press_keymap(keycode)) {
        return false;
    }
    switch (keycode) {
        // Keycodes that continue Caps Word, without shifting.
        case KC_LEFT:
        case KC_RIGHT:
        case KC_UP:
        case KC_DOWN:
        case A(KC_LEFT):
        case A(KC_RIGHT):
        case A(KC_UP):
        case A(KC_DOWN):
        case G(KC_LEFT):
        case G(KC_RIGHT):
        case G(KC_UP):
        case G(KC_DOWN):
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        case KC_SPACE:
            // If the last key was NOT a space, then register it having been pressed and
            // move on as normal
            if (!g_caps_word_last_key_was_space) {
                g_caps_word_last_key_was_space = true;
                return true;
            }
                // if this is the second space in a row, delete one and exit Caps Word
            else {
                tap_code16(KC_BACKSPACE);
                return false;
            }

        // Keys that do NOT break the Caps Word state
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDERSCORE:
        case KC_BACKSPACE:
            // If we're continuing on after a space, then we need to "address" that prior
            // space in some way. The way we do that depends on what mode we're in. But
            // in all cases, first we need to remove that space and then replace it with
            // another character or another operating mode (ex. OSM)
            if (g_caps_word_last_key_was_space) {
                tap_code16(KC_BACKSPACE);
                tap_code16(KC_UNDERSCORE);
                g_caps_word_last_key_was_space = false;
            }
            if (
                KC_A <= keycode && keycode <= KC_Z
            ) {
                add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            }
            return true;

        default:
            return false;  // Deactivate Caps Word
    }
}


