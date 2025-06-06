#pragma once
// Symbol layer
// inspired by https://getreuer.info/posts/keyboards/symbol-layer/index.html

//#define L_SYM_L0 SQ_COLN, SQ_LTLT, SQ_GTGT, SQ_PATH, _______
//#define L_SYM_R0 SQ_PIPE, SQ_AMPR, SQ_LTAR, SQ_RTAR, SQ_PHEX
#define L_SYM_L0 LSG(KC_1), LSG(KC_2), LSG(KC_3), LSG(KC_4), LSG(KC_5)
#define L_SYM_R0 LSG(KC_6), LSG(KC_7), LSG(KC_8), LSG(KC_9), LSG(KC_0)

#define L_SYM_L1  KC_GRV,   KC_LT,   KC_GT, KC_HASH, KC_PERC
#define L_SYM_L2 KC_EXLM, KC_MINS, KC_UNDS,  KC_EQL,   KC_AT
#define L_SYM_L3 KC_TILD, KC_PLUS, KC_ASTR, KC_SLSH,  KC_DOT

#define L_SYM_R1 KC_BSLS, KC_AMPR, KC_LBRC, KC_RBRC, DELWORD
#define L_SYM_R2 KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_SCLN
#define L_SYM_R3 KC_CIRC,  KC_DLR, KC_LCBR, KC_RCBR, KC_QUES
