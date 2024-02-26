/*
 * Kristoffer Gronlund, 2024
 * 3w6
 */

#include "krig.h"
#include "features/swapper.h"
#include "features/layer_lock.h"

#define TG_MOUS TG(_MOUSE)
#define LAYOUT_wrapper(...)             LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    QWERTY_L1, QWERTY_R1,
    QWERTY_L2, QWERTY_R2,
    QWERTY_L3, QWERTY_R3,
    THUMB_L3, THUMB_L2, THUMB_L1, THUMB_R1, THUMB_R2, THUMB_R3
  ),
  [_ALTERN] = LAYOUT_wrapper(
    ALTERN_L1, ALTERN_R1,
    ALTERN_L2, ALTERN_R2,
    ALTERN_L3, ALTERN_R3,
    THUMB_L3, THUMB_L2, THUMB_L1, THUMB_R1, THUMB_R2, THUMB_R3
  ),
  [_GAME] = LAYOUT_wrapper(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,     KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
    THUMB_L3, THUMB_L2, THUMB_L1, THUMB_R1, THUMB_R2, THUMB_R3
  ),
  [_NAV] = LAYOUT_wrapper(
    L_NAV_L1, L_NAV_R1,
    L_NAV_L2, L_NAV_R2,
    L_NAV_L3, L_NAV_R3,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TAB, KC_TRNS, KC_TRNS
  ),
  [_NUM] = LAYOUT_wrapper(
    L_NUM_L1, L_NUM_R1,
    L_NUM_L2, L_NUM_R2,
    L_NUM_L3, L_NUM_R3,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_SYM] = LAYOUT_wrapper(
    L_SYM_L1, L_SYM_R1,
    L_SYM_L2, L_SYM_R2,
    L_SYM_L3, L_SYM_R3,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_MOUSE] = LAYOUT_wrapper(
    L_MOUSE_L1, L_MOUSE_R1,
    L_MOUSE_L2, L_MOUSE_R2,
    L_MOUSE_L3, L_MOUSE_R3,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_TRNS, KC_TRNS
  ),
  [_ADJUST] = LAYOUT_wrapper(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    DF_QWER, DF_GAME, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    process_record_swapper(keycode, record);
    if (!process_layer_lock(keycode, record, LLOCK)) {
        return false;
    }
    return true;
}
