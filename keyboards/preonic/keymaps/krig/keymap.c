/*
 * Kristoffer Gronlund, 2023
 * Preonic
 *
 * Apart from the alternate layout layer, this layout
 * is fairly stable and basically what I use for work.
 */

#include "krig.h"
#include "features/layer_lock.h"

#define LAYOUT_wrapper(...) LAYOUT_preonic_grid(__VA_ARGS__)
#define BOTTOM_ROW \
            CW_TOGG,  CTL_SFT, KC_LALT, KC_LGUI, THUMB_L2, THUMB_L1,  \
    THUMB_R1, THUMB_R2, KC_LEFT, KC_DOWN,    KC_UP,  KC_RGHT
#define OSM_SFR OSM(MOD_RSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALTERN] = LAYOUT_wrapper(
       KC_GRV,     NUMROW_L,     NUMROW_R, TG(_MOUSE),
       KC_TAB,    ALTERN_L1,    ALTERN_R1, KC_BSPC,
      CTL_ESC,    ALTERN_L2,    ALTERN_R2, KC_QUOT,
      KC_LSFT,    ALTERN_L3,    ALTERN_R3, OSM_SFR,
      BOTTOM_ROW
    ),
    [_QWERTY] = LAYOUT_wrapper(
       KC_GRV,     NUMROW_L,     NUMROW_R, TG(_MOUSE),
       KC_TAB,    QWERTY_L1,    QWERTY_R1, KC_BSPC,
      CTL_ESC,    QWERTY_L2,    QWERTY_R2, KC_QUOT,
      KC_LSFT,    QWERTY_L3,    QWERTY_R3, OSM_SFR,
      BOTTOM_ROW
    ),
    [_GAME] = LAYOUT_wrapper(
       KC_GRV,     NUMROW_L,     NUMROW_R, KC_F9,
       KC_TAB,    QWERTY_L1,    QWERTY_R1, KC_BSPC,
      KC_LCTL,    QWERTY_L2,    QWERTY_R2, CTL_ENT,
      KC_LSFT,    QWERTY_L3,    QWERTY_R3, KC_RSFT,
      KC_NO, CTL_SFT, KC_LALT, KC_LGUI, THUMB_L2, THUMB_L1,  \
    KC_SPC, THUMB_R2, KC_LEFT, KC_DOWN,    KC_UP,  KC_RGHT
    ),
    [_NAV] = LAYOUT_wrapper(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, L_NAV_L1, L_NAV_R1, _______,
      _______, L_NAV_L2, L_NAV_R2, _______,
      _______, L_NAV_L3, L_NAV_R3, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),
    [_NUM] = LAYOUT_wrapper(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, L_NUM_L1, L_NUM_R1, _______,
      _______, L_NUM_L2, L_NUM_R2, _______,
      _______, L_NUM_L3, L_NUM_R3, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_SYM] = LAYOUT_wrapper(
      _______, L_SYM_L0, L_SYM_R0, _______,
      _______, L_SYM_L1, L_SYM_R1, _______,
      _______, L_SYM_L2, L_SYM_R2, _______,
      _______, L_SYM_L3, L_SYM_R3, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_MOUSE] = LAYOUT_wrapper(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, L_MOUSE_L1, L_MOUSE_R1, _______,
      _______, L_MOUSE_L2, L_MOUSE_R2, _______,
      _______, L_MOUSE_L3, L_MOUSE_R3, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_wrapper(
      DF_QWER,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
      DF_GAME, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_INS,
      RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT
    ),
};


const rgblight_segment_t PROGMEM lightlayer_0[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM lightlayer_1[] = RGBLIGHT_LAYER_SEGMENTS({3, 3, HSV_GREEN});
const rgblight_segment_t PROGMEM lightlayer_2[] = RGBLIGHT_LAYER_SEGMENTS({RGBLIGHT_LED_COUNT-3, 3, HSV_GREEN});
const rgblight_segment_t PROGMEM lightlayer_3[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_YELLOW}, {RGBLIGHT_LED_COUNT-1, 1, HSV_BLUE});
const rgblight_segment_t PROGMEM lightlayer_4[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_MAGENTA});
const rgblight_segment_t PROGMEM lightlayer_5[] = RGBLIGHT_LAYER_SEGMENTS({RGBLIGHT_LED_COUNT-4, 4, HSV_AZURE});
const rgblight_segment_t PROGMEM lightlayer_6[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLIGHT_LED_COUNT, HSV_PURPLE});
const rgblight_segment_t PROGMEM lightlayer_7[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLIGHT_LED_COUNT, HSV_ORANGE});
const rgblight_segment_t PROGMEM lightlayer_capsword[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_RED}, {RGBLIGHT_LED_COUNT-2, 2,});

const rgblight_segment_t* const PROGMEM lightlayers[] = RGBLIGHT_LAYERS_LIST(
    lightlayer_0,
    lightlayer_1,
    lightlayer_2,
    lightlayer_3,
    lightlayer_4,
    lightlayer_5,
    lightlayer_6,
    lightlayer_7,
    lightlayer_capsword
);

void keyboard_post_init_user(void) {
    rgblight_layers = lightlayers;
}

#ifdef AUDIO_ENABLE
float caps_word_on_song[][2] = SONG(CAPS_LOCK_ON_SOUND);
float caps_word_off_song[][2] = SONG(CAPS_LOCK_OFF_SOUND);
#endif

void caps_word_set_keymap(bool active) {
    rgblight_set_layer_state(_ADJUST+1, active);
    #ifdef AUDIO_ENABLE
    if (active) {
        PLAY_SONG(caps_word_on_song);
    } else {
        PLAY_SONG(caps_word_off_song);
    }
    #endif
}

layer_state_t default_layer_state_set_keymap(layer_state_t state) {
    for (int i = 0; i <= _GAME; ++i) {
        rgblight_set_layer_state(i, layer_state_cmp(state, i));
    }
    return state;
}

layer_state_t layer_state_set_keymap(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _SYM, _ADJUST);
    for (int i = _GAME + 1; i <= _ADJUST; ++i) {
        rgblight_set_layer_state(i, layer_state_cmp(state, i));
    }
    return state;
}
