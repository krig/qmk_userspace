#include "krig.h"
#include "features/flow.h"
#include "features/achordion.h"

#ifdef KRIG_CUSTOM_SHIFT
#include "features/custom_shift_keys.h"
const custom_shift_key_t custom_shift_keys[] = {
    {  KC_DOT, KC_EXLM },
    { KC_COMM, KC_QUES },
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys)/sizeof(custom_shift_key_t);
#endif

// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {THUMB_L1, KC_LALT},
    {THUMB_L1, KC_LGUI},
    {THUMB_L1, KC_LCTL},
    {THUMB_L1, KC_LSFT},
    {THUMB_L1, KC_RALT},

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

    {THUMB_R2, KC_LALT},
    {THUMB_R2, KC_LGUI},
    {THUMB_R2, KC_LCTL},
    {THUMB_R2, KC_LSFT},
    {THUMB_R2, KC_RALT},

    {LT(_NUM, KC_D), KC_LALT},
    {LT(_NUM, KC_D), KC_LGUI},
    {LT(_NUM, KC_D), KC_LCTL},
    {LT(_NUM, KC_D), KC_LSFT},
    {LT(_NUM, KC_D), KC_RALT},

    {MO(_NUM), KC_LALT},
    {MO(_NUM), KC_LGUI},
    {MO(_NUM), KC_LCTL},
    {MO(_NUM), KC_LSFT},
    {MO(_NUM), KC_RALT},
};

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifndef KRIG_MONOBLOCK
    if (!process_achordion(keycode, record)) {
        return false;
    }
#endif
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
        case SQ_PIPR: // |>
            if (record->event.pressed) {
                SEND_STRING("|>");
            }
            return false;
        case SQ_PIPL: // <|
            if (record->event.pressed) {
                SEND_STRING("<|");
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
#ifndef KRIG_MONOBLOCK
    achordion_task();
#endif
    flow_matrix_scan();
    matrix_scan_keymap();
}

static bool is_thumb_key(uint16_t keycode) {
    switch (keycode) {
        case THUMB_L1:
        case THUMB_L2:
        case THUMB_L3:
        case THUMB_R1:
        case THUMB_R2:
        case THUMB_R3: // currently same as L3
        case LSFT_T(KC_SPC):
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return is_thumb_key(keycode);
}

static bool is_finger_key(uint16_t keycode) {
    return (keycode <= KC_0 || (keycode >= KC_SEMICOLON && keycode <= KC_SLASH) || keycode == QK_REP);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    // Get base keycode
    if (IS_QK_MOD_TAP(tap_hold_keycode) || IS_QK_LAYER_TAP(tap_hold_keycode)) {
        tap_hold_keycode &= 0xff;
    }
    if (is_finger_key(tap_hold_keycode)) {
        return 2000;
    } else {
        return 200;
    }
}

#ifdef KRIG_3W6HS
static bool k3w6hs_left_hand(keypos_t pos) {
  return pos.row < MATRIX_ROWS / 2;
}
#endif

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    if (is_thumb_key(tap_hold_keycode)) {
        return true;
    }
#ifdef KRIG_3W6HS
  return k3w6hs_left_hand(tap_hold_record->event.key) !=
         k3w6hs_left_hand(other_record->event.key);
#else
    return achordion_opposite_hands(tap_hold_record, other_record);
#endif
}

bool krig_process_default_layers(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case DF_GAME:
            if (record->event.pressed) {
                if (get_highest_layer(default_layer_state) == _GAME) {
                    set_single_persistent_default_layer(_QWERTY);
                } else {
                    set_single_persistent_default_layer(_GAME);
                }
            }
            return false;
    };
    return true;
}
