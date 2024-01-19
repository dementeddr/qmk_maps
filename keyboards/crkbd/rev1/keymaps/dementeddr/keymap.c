/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "version.h"

enum custom_layers {
    BASE, // default layer
    SYMB, // symbols
    NAVI, // navigation
    MOUS, // mouse buttons
    FUNC, // function keys
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BACKSLASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_ESC, LSFT_T(KC_A), LALT_T(KC_S),    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    RALT_T(KC_L), RSFT_T(KC_SCLN), LGUI_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   LCTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,              KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH),  KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                     MO(1), KC_BACKSPACE, LT(3,KC_TAB), KC_ENT, LT(2,KC_SPC)   MO(4),
                                      //`--------------------------'  `--------------------------'
  ),

    [SYMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GRAVE, KC_EXLM,  KC_AT,  KC_LCBR, KC_RCBR, KC_PIPE,                     KC_ASTR,    KC_7,    KC_8,    KC_9,    KC_MINS, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_ESC, LSFT_T(KC_HASH), LALT_T(KC_DLR), KC_LPRN, KC_RPRN, KC_AMPR,        KC_EQL,  KC_4,    KC_5,    KC_6,    RSFT_T(KC_BSLS), KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, LCTL_T(KC_PERC), KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,              KC_PLUS, KC_1,    KC_2,    KC_3,   RCTL_T(KC_DOT), KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_NO,  KC_BACKSPACE, KC_TAB,  KC_ENT,  KC_SPC,  KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    [NAVI] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_DEL,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_ESC,  KC_LSFT, KC_LALT, KC_RGUI, KC_NO,   KC_NO,                        LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, RCTL(KC_RGHT),  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LCTL,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_PGDN, KC_PGUP, KC_NO,  RCTL(KC_B), KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_NO, KC_BACKSPACE, KC_TAB,  KC_ENT,  KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    [MOUS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      VRSN,   KC_NO,   KC_NO,   KC_NO,   RGB_SLD, KC_VOLU,                      KC_NO,   KC_WH_L, KC_MS_U, KC_WH_R, KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, KC_LSFT, KC_LALT, KC_RGUI,  KC_NO,   KC_VOLD,                     KC_NO,   KC_MS_R, KC_MS_D, KC_MS_L, KC_ACL2, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LCTL, KC_NO,  KC_NO,   KC_NO,   KC_MUTE,                      KC_NO,   KC_WH_D, KC_WH_U, KC_NO,   KC_RCTL, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,  KC_NO,   KC_NO,      KC_BTN1, KC_BTN2, KC_BTN3
                                      //`--------------------------'  `--------------------------'
  ),
    
    [FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     QK_CAPS_WORD_TOGGLE, KC_LSFT, KC_LALT, KC_GUI, KC_NO,  KC_NO,          CS_LAMBDA, KC_F4, KC_F5,   KC_F6,   KC_F11, QK_CAPS_WORD_TOGGLE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_NO, KC_BACKSPACE, KC_TAB,  KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LSFT_T(KC_HASH):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_HASH);
            return false;
        }
        break;

    case LCTL_T(KC_PERC):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_PERC);
            return false;
        }
        break;

    case CS_LAMBDA:
        if (record->event.pressed) {
            SEND_STRING(" => ");
        }
        break;

    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;

    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

