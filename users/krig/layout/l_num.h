// number layer

#ifdef KRIG_NUMPAD

#define L_NUM_L1 _______, _______, _______, _______, _______
#define L_NUM_L2 KC_LALT, KC_LCTL, KC_LGUI, KC_LSFT, KC_RALT
#define L_NUM_L3 _______, _______, _______, _______, _______

#define L_NUM_R1 _______,    KC_1,    KC_2,    KC_3, _______
#define L_NUM_R2 _______,    KC_4,    KC_5,    KC_6,    KC_0
#define L_NUM_R3 _______,    KC_7,    KC_8,    KC_9, _______

#else

#define L_NUM_L1    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define L_NUM_L2 SQ_PHEX, S(KC_G),    KC_K,    KC_J, _______
#define L_NUM_L3 _______, _______, _______, _______, _______

#define L_NUM_R1    KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define L_NUM_R2 _______, KC_LSFT, KC_LGUI, KC_LCTL, KC_LALT
#define L_NUM_R3 _______, _______, _______, _______, _______

#endif
