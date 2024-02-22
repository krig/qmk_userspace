#include "krig.h"
#include "features/flow.h"
#include "features/achordion.h"

#ifdef KRIG_CUSTOM_SHIFT
#include "features/custom_shift_keys.h"
const custom_shift_key_t custom_shift_keys[] = {
    {  KC_DOT, KC_EXCL },
    { KC_COMM, KC_QUES },
    { KC_UNDS, KC_MINS },
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys)/sizeof(custom_shift_key_t);
#endif

// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {THUMB_L2, KC_LALT},
    {THUMB_L2, KC_LGUI},
    {THUMB_L2, KC_LCTL},
    {THUMB_L2, KC_LSFT},
    {THUMB_L2, KC_RALT},

    {THUMB_R1, KC_LALT},
    {THUMB_R1, KC_LGUI},
    {THUMB_R1, KC_LCTL},
    {THUMB_R1, KC_LSFT},
    {THUMB_R1, KC_RALT},

    {MO(_NUM), KC_LALT},
    {MO(_NUM), KC_LGUI},
    {MO(_NUM), KC_LCTL},
    {MO(_NUM), KC_LSFT},
    {MO(_NUM), KC_RALT},
};
// for layers configuration follow this format:
// * custom layer key
// * layer name
const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OSL_ADJ, _ADJUST},
};


__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    if (!update_flow(keycode, record->event.pressed, record->event.key)) {
        return false;
    }
    if (!process_record_keymap(keycode, record)) {
        return false;
    }
    #ifdef KRIG_CUSTOM_SHIFT
    // handle custom shift keys like ./:, ,/; etc.
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }
    #endif
    #ifdef KRIG_CUSTOM_SEQUENCES
    switch (keycode) {
        case SQ_COLN:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
        case SQ_PIPE:
            if (record->event.pressed) {
                SEND_STRING("||");
            }
            return false;
        case SQ_AMPR:
            if (record->event.pressed) {
                SEND_STRING("&&");
            }
            return false;
        case SQ_PATH:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;
        case SQ_PHEX:
            if (record->event.pressed) {
                SEND_STRING("0x");
            }
            return false;
        case SQ_SLAS: //
            if (record->event.pressed) {
                SEND_STRING("//");
            }
            return false;
        case SQ_LTLT: // <<
            if (record->event.pressed) {
                SEND_STRING("<<");
            }
            return false;
        case SQ_GTGT: // >>
            if (record->event.pressed) {
                SEND_STRING(">>");
            }
            return false;
        case SQ_RTAR: // ->
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case SQ_LTAR: // <-
            if (record->event.pressed) {
                SEND_STRING("<-");
            }
            return false;
        case SQ_EXPI: // <-
            if (record->event.pressed) {
                SEND_STRING("|>");
            }
            return false;
    }
    #endif
    if (!krig_process_default_layers(keycode, record)) {
        return false;
    }
    return true;
}

__attribute__ ((weak))
layer_state_t layer_state_set_keymap (layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _SYM, _ADJUST);
    return layer_state_set_keymap(state);
}

__attribute__ ((weak))
layer_state_t default_layer_state_set_keymap (layer_state_t state) {
  return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    return default_layer_state_set_keymap(state);
}

__attribute__ ((weak))
void matrix_scan_keymap(void) {
}

void matrix_scan_user(void) {
    achordion_task();
    flow_matrix_scan();
    matrix_scan_keymap();
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THUMB_L2:
        case THUMB_R1:
        case THUMB_R2:
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

static bool is_finger_key(uint16_t keycode) {
    return (keycode <= KC_0 || (keycode >= KC_SEMICOLON && keycode <= KC_SLASH));
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    // Get base keycode
    if ((tap_hold_keycode >= QK_MOD_TAP && tap_hold_keycode <= QK_MOD_TAP_MAX) ||
        (tap_hold_keycode >= QK_LAYER_TAP && tap_hold_keycode <= QK_LAYER_TAP_MAX)) {
        tap_hold_keycode &= 0xff;
    }
    if (is_finger_key(tap_hold_keycode)) {
        return 2000;
    } else {
        return 200;
    }
}


bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    // Get base keycode
    if ((tap_hold_keycode >= QK_MOD_TAP && tap_hold_keycode <= QK_MOD_TAP_MAX) ||
        (tap_hold_keycode >= QK_LAYER_TAP && tap_hold_keycode <= QK_LAYER_TAP_MAX)) {
        tap_hold_keycode &= 0xff;
    }

    static const uint16_t homerow_qwerty[] = { QWERTY_R2 };
    static const uint16_t homerow_altern[] = { ALTERN_R2 };
    const uint16_t* homerow = homerow_qwerty;
    if (IS_LAYER_ON_STATE(default_layer_state, _ALTERN)) {
        homerow = homerow_altern;
    }
    if (is_finger_key(tap_hold_keycode)) {
        for (int i = 0; i < (sizeof(homerow_qwerty) / sizeof(homerow_qwerty[0])); ++i) {
            if (other_keycode == homerow[i])
                return true;
        }
        return false;
    } else {
        return true;
    }
}
