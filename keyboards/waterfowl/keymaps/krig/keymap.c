/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "krig.h"
#include "features/swapper.h"
#include "features/layer_lock.h"

#define TG_MOUS TG(_MOUSE)
#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)
#define THUMB_ROW KC_MPRV,      THUMB_L2,  THUMB_L1,  THUMB_L3, KC_MCTL, KC_MPLY,  THUMB_R3, THUMB_R1, THUMB_R2,          KC_MNXT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    QWERTY_L1, QWERTY_R1,
    QWERTY_L2, QWERTY_R2,
    QWERTY_L3, QWERTY_R3,
    THUMB_ROW
  ),
  [_ALTERN] = LAYOUT_wrapper(
    ALTERN_L1, ALTERN_R1,
    ALTERN_L2, ALTERN_R2,
    ALTERN_L3, ALTERN_R3,
    THUMB_ROW
  ),
  [_GAME] = LAYOUT_wrapper(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,     KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
    THUMB_ROW
  ),
  [_NAV] = LAYOUT_wrapper(
    L_NAV_L1, L_NAV_R1,
    L_NAV_L2, L_NAV_R2,
    L_NAV_L3, L_NAV_R3,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TAB, KC_TRNS, KC_TRNS
  ),
  [_NUM] = LAYOUT_wrapper(
    L_NUM_L1, L_NUM_R1,
    L_NUM_L2, L_NUM_R2,
    L_NUM_L3, L_NUM_R3,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_SYM] = LAYOUT_wrapper(
    L_SYM_L1, L_SYM_R1,
    L_SYM_L2, L_SYM_R2,
    L_SYM_L3, L_SYM_R3,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_MOUSE] = LAYOUT_wrapper(
    L_MOUSE_L1, L_MOUSE_R1,
    L_MOUSE_L2, L_MOUSE_R2,
    L_MOUSE_L3, L_MOUSE_R3,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS
  ),
   [_ADJUST] = LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    DF_QWER, DF_GAME, TG_MOUS, _______, _______, _______, _______, _______, _______, QK_BOOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    process_record_swapper(keycode, record);
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left roller
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else if (index == 1) { // Left encoder
        if (clockwise) {
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }
    } else if (index == 2) { // Right roller
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    } else if (index == 3) { // Right encoder
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }

    return false;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("\n"), false);
        // Host Keyboard Layer Status
        if (layer_state_cmp(default_layer_state, _QWERTY)) {
            oled_write_P(PSTR("qwerty\n"), false);
        } else if (layer_state_cmp(default_layer_state, _ALTERN)) {
            oled_write_P(PSTR("altern\n"), false);
        } else if (layer_state_cmp(default_layer_state, _GAME)) {
            oled_write_P(PSTR("uhc\n"), false);
        } else {
            oled_write_P(PSTR("wat\n"), false);
        }
        oled_write_P(PSTR("\n"), false);

        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
            case _ALTERN:
            case _GAME:
                oled_write_P(PSTR("....\n\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("<-->\n\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("1234\n\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR(":();\n\n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("mous\n\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("ffff\n\n"), false);
                break;
            default:
                oled_write_ln_P(PSTR("????\n\n"), false);
                break;
        }
        if (is_caps_word_on()) {
            oled_write_ln_P(PSTR("CAPS!!!\n"), false);

        } else {
            oled_write_ln_P(PSTR("\n"), false);

        }
        return false;
    }
    return true;
}
