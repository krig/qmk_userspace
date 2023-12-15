// number layer

#ifdef KRIG_NUMPAD

#define L_NUM_L1 _______, _______, _______, _______, _______
#define L_NUM_L2 _______, _______, _______, _______, _______
#define L_NUM_L3 _______, _______, _______, _______, _______

#define L_NUM_R1 SQ_PHEX,    KC_1,    KC_2,    KC_3, S(KC_G)
#define L_NUM_R2    KC_J,    KC_4,    KC_5,    KC_6,    KC_0
#define L_NUM_R3    KC_K,    KC_7,    KC_8,    KC_9, _______

#else

#define L_NUM_L1    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define L_NUM_L2 SQ_PHEX, S(KC_G),    KC_K,    KC_J, _______
#define L_NUM_L3 _______, _______, _______, _______, _______

#define L_NUM_R1    KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define L_NUM_R2 _______, KC_LSFT, KC_LGUI, KC_LCTL, KC_LALT
#define L_NUM_R3 _______, _______, _______, _______, _______

#endif
