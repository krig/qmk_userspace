#pragma once

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

#define THUMB_L1 KC_SPC
#define THUMB_L2 LT(_NAV, KC_ESC)
#ifdef KRIG_MOUSE_LAYER
#define THUMB_L3 TG(_MOUSE)
#define THUMB_L4 QK_REP
#else
#define THUMB_L3 QK_REP
#define THUMB_L4 QK_AREP
#endif

#define THUMB_R1 LSFT_T(KC_ENT)
#define THUMB_R2 LT(_SYM, KC_BSPC)
#define THUMB_R3 RGUI_T(KC_TAB)
#define THUMB_R4 RCTL_T(KC_DEL)

#define ALT_THUMB_R2 LT(_SYM, KC_ENT)

// toggles between qwerty and AKL
#define DF_QWER  DF(_QWERTY)
#define DF_GAME  DF(_GAME)

bool krig_process_default_layers(uint16_t keycode, keyrecord_t* record);

#define NUMROW_L KC_1,     KC_2,    KC_3,    KC_4,    KC_5
#define NUMROW_R KC_6,     KC_7,    KC_8,    KC_9,    KC_0

#include "layout/qwerty.h" // standard layout
#include "layout/waffle4.h"  // alternative layout
#include "layout/l_nav.h"  // navigation layer
#include "layout/l_num.h"  // number layer
#include "layout/l_sym.h"  // symbol layer
#include "layout/l_mouse.h"

