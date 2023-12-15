 /* Copyright 2020 Naoki Katahira
  * Copyright 2023 Elliot Powell
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include "krig.h"
#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY] = LAYOUT_wrapper(
   KC_GRV,         NUMROW_L,                    NUMROW_R, GUI_SPC,
   KC_TAB,        QWERTY_L1,                   QWERTY_R1, SWE_AA,
  CTL_ESC,        QWERTY_L2,                   QWERTY_R2, SWE_AE,
  OSM_SFT,        QWERTY_L3, QK_REP,  TT(_NUM), QWERTY_R3, SWE_OE,
  KC_LALT, KC_LGUI, THUMB_L2,  THUMB_L1, THUMB_R1, THUMB_R2, RGUI_T(KC_PGDN), RALT_T(KC_PGUP)
 ),
 [_ALTERN] = LAYOUT_wrapper(
   KC_GRV,         NUMROW_L,                    NUMROW_R, GUI_SPC,
   KC_TAB,        ALTERN_L1,                   ALTERN_R1, SWE_AA,
  CTL_ESC,        ALTERN_L2,                   ALTERN_R2, SWE_AE,
  OSM_SFT,        ALTERN_L3, QK_REP,  TT(_NUM), ALTERN_R3, SWE_OE,
  KC_LALT, KC_LGUI, THUMB_L2,  THUMB_L1, THUMB_R1, THUMB_R2, RGUI_T(KC_PGDN), RALT_T(KC_PGUP)
 ),
 [_GAME] = LAYOUT_wrapper(
   KC_ESC,  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_F9,
   KC_TAB,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, SWE_AA,
  KC_LCTL, KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, SWE_AE,
  KC_LSFT, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V, QK_REP,  TT(_NUM),    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SWE_OE,
                             KC_LALT, KC_LGUI, THUMB_L2,  THUMB_L1, THUMB_R1, THUMB_R2, RGUI_T(KC_PGDN), RALT_T(KC_PGUP)
 ),
 [_NAV] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, L_NAV_L1,                   L_NAV_R1, _______,
  _______, L_NAV_L2,                   L_NAV_R2, _______,
  _______, L_NAV_L3, _______, _______, L_NAV_R3, _______,
                             _______, _______, _______, _______, KC_TAB, _______, _______, _______
 ),
 [_NUM] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, L_NUM_L1,                   L_NUM_R1, _______,
  _______, L_NUM_L2,                   L_NUM_R2, _______,
  _______, L_NUM_L3, _______, _______, L_NUM_R3, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
 ),
 [_SYM] = LAYOUT_wrapper(
  _______, L_SYM_L0,                   L_SYM_R0, _______,
  _______, L_SYM_L1,                   L_SYM_R1, _______,
  _______, L_SYM_L2,                   L_SYM_R2, _______,
  _______, L_SYM_L3, _______, _______, L_SYM_R3, _______,
                             _______, _______, _______, _______,  _______, _______, _______, _______
 ),
 [_ADJUST] = LAYOUT(
  DF_QWER,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______,                   RGB_TOG, RGB_MOD, RGB_M_P, RGB_M_B, _______,  KC_INS,
  _______, _______, _______, _______, _______, _______,                   RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
                             _______, _______, _______, _______, _______, _______, _______, _______
 )
};

void oled_render_keylog_r2g(void);
void oled_render_logo_r2g(void);

bool oled_task_user() {
     if (is_keyboard_master()) {
         const int dlayer = get_highest_layer(default_layer_state);
         const int layer = get_highest_layer(layer_state);
         switch (dlayer) {
             case _ALTERN: oled_write_ln_P(PSTR("ALT!!!"), false); break;
             case _QWERTY: oled_write_ln_P(PSTR("QWERTY"), false); break;
             case _GAME: oled_write_ln_P(PSTR("*U H C*"), false); break;
         }
         switch (layer) {
             case _NAV: oled_write_ln_P(PSTR("ARROWS"), false); break;
             case _NUM: oled_write_ln_P(PSTR("123456"), false); break;
             case _SYM: oled_write_ln_P(PSTR("SYMBOL"), false); break;
             case _ADJUST: oled_write_ln_P(PSTR("ADJUST"), false); break;
         }
         oled_render_keylog_r2g();
     } else {
         oled_render_logo_r2g();
     }
     return false;
}

bool rgb_matrix_indicators_user() {
     const int dlayer = get_highest_layer(default_layer_state);
     const int layer = get_highest_layer(layer_state);
     if (dlayer == _ALTERN) {
         rgb_matrix_set_color(g_led_config.matrix_co[2][1], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][2], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][3], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][4], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][10], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][11], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][12], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][13], RGB_GOLD);
     } if (dlayer == _GAME) {
         rgb_matrix_set_color_all(RGB_OFF);
         rgb_matrix_set_color(g_led_config.matrix_co[1][3], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][2], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][3], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][4], RGB_GOLD);
     }
     if (layer > 0) {
         rgb_matrix_set_color_all(RGB_OFF);

         for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
             for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                 uint8_t index = g_led_config.matrix_co[row][col];
                 if (index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                     rgb_matrix_set_color(index, RGB_PURPLE);
                 }
             }
         }
     }
     return false;
}

