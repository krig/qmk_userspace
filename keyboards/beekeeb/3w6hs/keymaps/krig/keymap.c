/*
 * Kristoffer Gronlund, 2024
 * 3w6
 */

#include "krig.h"
#include "features/swapper.h"

#define LAYOUT_wrapper(...)             LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    QWERTY_L1, QWERTY_R1,
    QWERTY_L2, QWERTY_R2,
    QWERTY_L3, QWERTY_R3,
    THUMB_L3, THUMB_L2, THUMB_L1, THUMB_R1, THUMB_R2, THUMB_R3
  ),
  [_GAME] = LAYOUT_wrapper(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,
    KC_SLSH, THUMB_L2, THUMB_L1, THUMB_R1, THUMB_R2, KC_P
  ),
  [_NAV] = LAYOUT_wrapper(
    L_NAV_L1, L_NAV_R1,
    L_NAV_L2, L_NAV_R2,
    L_NAV_L3, L_NAV_R3,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_NUM] = LAYOUT_wrapper(
    L_NUM_L1, L_NUM_R1,
    L_NUM_L2, L_NUM_R2,
    L_NUM_L3, L_NUM_R3,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_LGUI, KC_LCTL
  ),
  [_SYM] = LAYOUT_wrapper(
    L_SYM_L1, L_SYM_R1,
    L_SYM_L2, L_SYM_R2,
    L_SYM_L3, L_SYM_R3,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_ADJUST] = LAYOUT_wrapper(
    L_ADJ34_L1, L_ADJ34_R1,
    L_ADJ34_L2, L_ADJ34_R2,
    L_ADJ34_L3, L_ADJ34_R3,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    process_record_swapper(keycode, record);
    return true;
}
