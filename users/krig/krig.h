#pragma once
#include QMK_KEYBOARD_H

enum custom_keycodes {
    SQ_COLN = SAFE_RANGE, // ::
    SQ_AMPR,              // &&
    SQ_PIPE,              // ||
    SQ_PATH,              // ../
    SQ_SLAS,              // //
    SQ_PHEX,              // 0x
    SQ_LTLT,              // <<
    SQ_GTGT,              // >>
    SQ_RTAR,              // ->
    SQ_LTAR,              // <-
    SQ_EXPI,              // |>
    LLOCK,                // layer lock
    CMD_TAB,              // single-key cmd+tab (features/swapper)
    CMD_GRV,              // single-key cmd+` (features/swapper)
    OSL_ADJ,              // flow one-shot adjust layer

    NEW_SAFE_RANGE,
};

// Mac OS navigation shortcuts
#define GUI_LFT LGUI(KC_LEFT)
#define GUI_RGT LGUI(KC_RGHT)
#define GUI__C LGUI(KC_C)
#define GUI__N LGUI(KC_N)
#define GUI__Q LGUI(KC_Q)
#define GUI__R LGUI(KC_R)
#define GUI__T LGUI(KC_T)
#define GUI__V LGUI(KC_V)
#define GUI__W LGUI(KC_W)
#define GUI__X LGUI(KC_X)
#define GUI__Z LGUI(KC_Z)
#define GUI__B LGUI(KC_B)
#define GUI_SPC LGUI(KC_SPC)

// Mac OS spaces navigation
#define WS_PREV LCTL(KC_LEFT)
#define WS_NEXT LCTL(KC_RIGHT)
#define WS_DESK LCTL(KC_DOWN)
#define WS_ALL LCTL(KC_UP)

// One shot modifiers (not callum style)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_SFT OSM(MOD_LSFT)

#define LCTL_W LCTL(KC_W)

// Preonic specials
#define CTL_ENT RCTL_T(KC_ENT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_QUO LCTL_T(KC_QUOT)
#define CTL_SFT LCTL(KC_LSFT)
#define SFT_QUO RSFT_T(KC_QUOT)
#define SFT_SLS RSFT_T(KC_SLSH)
#define SFT_SPC LSFT_T(KC_SPC)
#define SFT_ENT LSFT_T(KC_ENT)

// Swedish letters (Eurkey layout)
#define SWE_AA RALT(KC_W)
#define SWE_OE RALT(KC_O)
#define SWE_AE RALT(KC_A)

// Convenience
#define ZOOM_IN LGUI(KC_PLUS)
#define ZOOM_UT LGUI(KC_MINS)


#ifdef KRIG_CUSTOM_SHIFT
#include "features/custom_shift_keys.h"
#endif

#include "layer_system.h"

#ifdef KRIG_CAPS_WORD
#include "features/krig_caps_word.h"
#endif
