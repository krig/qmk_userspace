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
    SQ_PIPL,              // <|
    SQ_PIPR,              // |>
    CMD_TAB,              // single-key cmd+tab (features/swapper)
    CMD_GRV,              // single-key cmd+` (features/swapper)

    NEW_SAFE_RANGE,
};

enum custom_layers {
    _ALTERN,
    _QWERTY,
    _GAME,
    _NAV,
    _NUM,
    _SYM,
#ifdef KRIG_MOUSE_LAYER
    _MOUSE,
#endif
    _ADJUST,
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
#define SFT_TAB LSFT(KC_TAB)

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

#define THUMB_L1 KC_SPC
#define THUMB_L2 LT(_NAV, KC_ESC)
#define THUMB_L3 LT(_NUM, KC_TAB)
#define THUMB_L4 QK_REP

#define THUMB_R1 LSFT_T(KC_ENT)
#define THUMB_R2 LT(_SYM, KC_BSPC)
#ifdef KRIG_MOUSE_LAYER
#define THUMB_R3 LT(_MOUSE, KC_BSPC)
#else
#define THUMB_R3 KC_BSPC
#endif
#define THUMB_R4 QK_AREP

// toggles between qwerty and AKL
#define DF_QWER  DF(_QWERTY)
#define DF_GAME  DF(_GAME)

bool krig_process_default_layers(uint16_t keycode, keyrecord_t* record);

#define NUMROW_L KC_1,     KC_2,    KC_3,    KC_4,    KC_5
#define NUMROW_R KC_6,     KC_7,    KC_8,    KC_9,    KC_0

//#include "layout/qwerty.h"
#include "layout/snthpig.h"
#include "layout/snthpig-alt.h"
#include "layout/nav.h"
#include "layout/num.h"
#include "layout/sym.h"
#include "layout/mouse.h"
#include "layout/adj34.h"

#ifdef KRIG_CAPS_WORD
#include "features/krig_caps_word.h"
#endif

#ifdef KRIG_CUSTOM_SHIFT
#include "features/custom_shift_keys.h"
#endif
