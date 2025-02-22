/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
};

#define ADJUST MO(_ADJUST)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
        KC_PGUP, KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,
        KC_PGDN, KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,     KC_QUOT,
                 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ADJUST,
                 KC_LGUI,          KC_LALT,     LOWER,        KC_SPC,      RAISE,        KC_ENT,      KC_RALT,               KC_RCTL
    ),

	[_LOWER] = LAYOUT(
        _______, _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_GRV,  KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,      _______,
                 _______, _______, _______, _______, _______, KC_TILD, _______, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
                 _______,          _______,     _______,      _______,     _______,      _______, _______,                   _______
    ),

	[_RAISE] = LAYOUT(
        _______, _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,       _______,
                 _______, _______, _______, _______, _______, _______, KC_HOME, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, _______, _______,
                 _______,          _______,     _______,      _______,     _______,      _______, _______,                   _______
    ),

	[_ADJUST] = LAYOUT(
        QK_BOOT, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                 _______,          _______,     _______,      _______,     _______,      _______, _______,                   _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
