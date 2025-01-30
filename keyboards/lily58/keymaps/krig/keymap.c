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
#include "features/swapper.h"
#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__)

#define THUMB_ROW() ALT_T(KC_LEFT), GUI_T(KC_RGHT), THUMB_L2,  THUMB_L1, THUMB_R1, THUMB_R2, RGUI_T(KC_DOWN), ALGR_T(KC_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY] = LAYOUT_wrapper(
   KC_GRV,         NUMROW_L,                    NUMROW_R, GUI_SPC,
   KC_TAB,        QWERTY_L1,                   QWERTY_R1, SWE_AA,
  CTL_ESC,        QWERTY_L2,                   QWERTY_R2, SWE_AE,
  OSM_SFT,        QWERTY_L3, QK_REP,  QK_AREP, QWERTY_R3, SWE_OE,
  THUMB_ROW()
 ),
 [_GAME] = LAYOUT_wrapper(
   KC_ESC,  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_F9,
   KC_TAB,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, SWE_AA,
  KC_LCTL, KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, SWE_AE,
  KC_LSFT, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V, KC_G,  KC_T,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SWE_OE,
  THUMB_ROW()
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
 [_ADJUST] = LAYOUT_wrapper(
  RGB_TOG, L_ADJ34_L1,                   L_ADJ34_R1,  KC_F11,
  RGB_MOD, L_ADJ34_L1,                   L_ADJ34_R1,  KC_INS,
  RGB_VAI, L_ADJ34_L2,                   L_ADJ34_R2, _______,
  RGB_VAD, L_ADJ34_L3, _______, _______, L_ADJ34_R3, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
 )
};

bool oled_task_user() {
     if (is_keyboard_master()) {
         const int dlayer = get_highest_layer(default_layer_state);
         switch (dlayer) {
             case _QWERTY: oled_write_ln_P(PSTR("QWERTY"), false); break;
             case _GAME: oled_write_ln_P(PSTR("*U H C*"), false); break;
         }
     } else {
         const int layer = get_highest_layer(layer_state);
         switch (layer) {
             case _NAV: oled_write_ln_P(PSTR("ARROWS"), false); break;
             case _NUM: oled_write_ln_P(PSTR("123456"), false); break;
             case _SYM: oled_write_ln_P(PSTR("SYMBOL"), false); break;
             case _ADJUST: oled_write_ln_P(PSTR("ADJUST"), false); break;
         }
     }
     return false;
}

bool rgb_matrix_indicators_user() {
     // cols = 6
     // rows = 10
     const int dlayer = get_highest_layer(default_layer_state);
     const int layer = get_highest_layer(layer_state);
     if (dlayer == _GAME) {
         rgb_matrix_set_color_all(RGB_OFF);
         rgb_matrix_set_color(g_led_config.matrix_co[1][3], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][2], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][3], RGB_GOLD);
         rgb_matrix_set_color(g_led_config.matrix_co[2][4], RGB_GOLD);
     }
     if (layer > 0) {
         rgb_matrix_set_color_all(RGB_OFF);

         if (layer == _NAV) {
             for (int i = 0; i < MATRIX_COLS; ++i)
                 rgb_matrix_set_color(g_led_config.matrix_co[2][i], RGB_AZURE);
         } else if (layer == _NUM) {
            rgb_matrix_set_color(g_led_config.matrix_co[6][2], RGB_YELLOW);
            rgb_matrix_set_color(g_led_config.matrix_co[6][3], RGB_YELLOW);
            rgb_matrix_set_color(g_led_config.matrix_co[6][4], RGB_YELLOW);
            rgb_matrix_set_color(g_led_config.matrix_co[7][2], RGB_YELLOW);
            rgb_matrix_set_color(g_led_config.matrix_co[7][3], RGB_YELLOW);
            rgb_matrix_set_color(g_led_config.matrix_co[7][4], RGB_YELLOW);
            rgb_matrix_set_color(g_led_config.matrix_co[7][5], RGB_YELLOW);
            rgb_matrix_set_color(g_led_config.matrix_co[8][2], RGB_YELLOW);
            rgb_matrix_set_color(g_led_config.matrix_co[8][3], RGB_YELLOW);
            rgb_matrix_set_color(g_led_config.matrix_co[8][4], RGB_YELLOW);
         } else if (layer == _SYM) {
             for (int i = 0; i < MATRIX_COLS; ++i)
                 rgb_matrix_set_color(g_led_config.matrix_co[7][i], RGB_AZURE);
         } else if (layer == _ADJUST) {
             for (int i = 0; i < MATRIX_COLS; ++i) {
                 rgb_matrix_set_color(g_led_config.matrix_co[0][i], RGB_AZURE);
                 rgb_matrix_set_color(g_led_config.matrix_co[5][i], RGB_AZURE);
             }
         }
     }
     return false;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    process_record_swapper(keycode, record);
    return true;
}
