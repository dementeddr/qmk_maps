#include QMK_KEYBOARD_H
#include "version.h"


enum custom_layers {
    BASE,   // default layer
    SYMB,   // symbols
    NAVI,   // navigation
    MOUS,   // mouse keys
    FUNC,   // function keys
};


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
  RGB_SLD,
  CS_LAMBDA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ergodox(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_ESC, LSFT_T(KC_A), LALT_T(KC_S), KC_D, KC_F, KC_G, KC_LCTL, LCTL_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MO(1), KC_NO, KC_NO, KC_NO, KC_BSPC, LT(3,KC_TAB), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, KC_H, KC_J, KC_K, RALT_T(KC_L), RSFT_T(KC_SCLN), LGUI_T(KC_QUOT), KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, RCTL_T(KC_SLSH), KC_NO, MO(4), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, LT(2,KC_SPC)),
    [SYMB] = LAYOUT_ergodox(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_NO, KC_TRNS, LSFT_T(KC_HASH), KC_DLR, KC_LPRN, KC_RPRN, KC_AMPR, KC_NO, LCTL_T(KC_PERC), KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ASTR, KC_7, KC_8, KC_9, KC_MINS, KC_NO, KC_EQL, KC_4, KC_5, KC_6, RSFT_T(KC_BSLS), KC_UNDS, KC_NO, KC_PLUS, KC_1, KC_2, KC_3, RCTL_T(KC_DOT), KC_NO, KC_0, KC_NO, KC_NO, KC_NO, TG(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS),
    [NAVI] = LAYOUT_ergodox(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_LSFT, KC_LALT, KC_RGUI, KC_NO, KC_NO, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_UP, KC_END, KC_DEL, KC_NO, LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, RCTL(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_NO,  RCTL(KC_B), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS),
    [MOUS] = LAYOUT_ergodox(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_U, KC_NO, KC_VOLU, KC_NO, KC_TRNS, KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_BTN3, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_D, KC_BTN1, KC_BTN2, KC_RALT, KC_RSFT, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_R, KC_ACL2, KC_RCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS),
    [FUNC] = LAYOUT_ergodox(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_LSFT, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DB_TOGG, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, CS_LAMBDA, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
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

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = get_highest_layer(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

}
