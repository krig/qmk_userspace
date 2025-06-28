#include QMK_KEYBOARD_H

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_uslsh[] = {KC_U, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_yo[] = {KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM combo_ca[] = {KC_C, KC_A, COMBO_END};
const uint16_t PROGMEM combo_wquo[] = {KC_W, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_ou[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM combo_ae[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo_qdot[] = {KC_QUOT, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_ei[] = {KC_E, KC_I, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_uslsh, DELWORD),
    COMBO(combo_wquo, KC_DQUO),
    COMBO(combo_yo, KC_CIRC),
    COMBO(combo_ou, SWE_OE),
    COMBO(combo_ae, SWE_AE),
    COMBO(combo_qdot, SWE_AA)
};
#endif
