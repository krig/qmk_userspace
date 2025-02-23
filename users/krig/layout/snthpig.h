#pragma once
// my custom keyboard layout
// q m h k v j y o u ;
// r s n t p g c a e i
// x f l D b z w ' . ,
//
// D: tap: d, hold: NUM

#define QWERTY_L1 KC_Q, KC_M, KC_H, KC_K, KC_V
#define QWERTY_L2 KC_R, KC_S, KC_N, KC_T, KC_P
#define QWERTY_R1 KC_J, KC_Y, KC_O, KC_U, DELWORD
#define QWERTY_R2 KC_G, KC_C, KC_A, KC_E, KC_I

#ifdef KRIG_HOMEROWMODS

#define QWERTY_L3 ALT_T(KC_X), CTL_T(KC_F), CMD_T(KC_L), LT(_NUM, KC_D), KC_B
#define QWERTY_R3 KC_Z, KC_W, CMD_T(KC_QUOT), CTL_T(KC_DOT), ALT_T(KC_COMM)

#else

#define QWERTY_L3 KC_X, KC_F, KC_L, LT(_NUM, KC_D), KC_B
#define QWERTY_R3 KC_Z, KC_W, KC_QUOT, KC_DOT, KC_COMM

#endif
