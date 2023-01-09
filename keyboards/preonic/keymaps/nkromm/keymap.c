/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
    _COLEMAK,
    _QWERTY,
    _GAMING,
    _RAISE,
    _ADJUST,
};

enum preonic_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAMING,
  RAISE,
  ADJUST,
};

#define MOD_A LGUI_T(KC_A)
#define MOD_R LALT_T(KC_R)
#define MOD_S LCTL_T(KC_S)
#define MOD_T LSFT_T(KC_T)
#define MOD_D LCTL_T(KC_D)
#define MOD_F LSFT_T(KC_F)

#define MOD_N RSFT_T(KC_N)
#define MOD_E RCTL_T(KC_E)
#define MOD_I LALT_T(KC_I)
#define MOD_O RGUI_T(KC_O)
#define MOD_J RSFT_T(KC_J)
#define MOD_K RCTL_T(KC_K)
#define MOD_L LALT_T(KC_L)
#define MOD_SCLN RGUI_T(KC_SCLN)

#define LT_RSSP LT(_RAISE, KC_SPACE)
#define LT_RSRT LT(_RAISE, KC_ENTER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* COLEMAK - DHm
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   ←  |   ↓  |   ↑  |   →  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  '   |  M_A |  M_R |  M_S |  M_T |   G  |   M  |  M_N |  M_E |  M_I |  M_O |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  `   |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Adju |      |  [   |   ]  |   M_Space   |   M_Enter   |   (  |   )  |      | Adju |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_2x2u(
  KC_ESC,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_LEFT, KC_DOWN,  KC_UP,    KC_RGHT,  KC_BSPC,
  KC_TAB,  KC_Q,     KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,     KC_Y,     KC_SCLN,  KC_BSLS,
  KC_QUOT, MOD_A,    MOD_R,   MOD_S,   MOD_T,   KC_G,    KC_M,    MOD_N,   MOD_E,    MOD_I,    MOD_O,    KC_MINS,
  KC_GRV,  KC_Z,     KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_EQL,
  ADJUST,  _______,  KC_LBRC, KC_RBRC,        LT_RSSP,    LT_RSRT,         KC_LPRN,  KC_RPRN,  _______,  ADJUST
),

[_QWERTY] = LAYOUT_preonic_2x2u(
  KC_ESC,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_LEFT, KC_DOWN,  KC_UP,    KC_RGHT,  KC_BSPC,
  KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
  KC_QUOT, MOD_A,    MOD_S,   MOD_D,   MOD_F,   KC_G,    KC_H,    MOD_J,   MOD_K,    MOD_L,    MOD_SCLN, KC_MINS,
  KC_GRV,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_EQL,
  ADJUST,  _______,  KC_LBRC, KC_RBRC,        LT_RSSP,    LT_RSRT,         KC_LPRN,  KC_RPRN,  _______,  ADJUST
),

[_GAMING] = LAYOUT_preonic_2x2u(
  KC_ESC,  KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
  KC_QUOT, KC_A,    KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SCLN, KC_MINS,
  KC_GRV,  KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_EQL,
  ADJUST,  RAISE,   KC_LCTL, KC_LSFT,      KC_SPC,       LT_RSRT,         KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  C-z |  C-x |  C-c |  C-v |   &  |   *  | Home | PgDn | PgUp | End  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ins  |      |      |  C-s |      |      |      |      |      |      |      | Ins  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |      | PSCR | CAPS |             |             |      |      |      | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_2x2u(
  KC_ESC,   LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_AMPR,  KC_ASTR,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_BSPC,
  KC_DEL,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
  KC_INS,   _______,    _______,    LCTL(KC_S), _______,    _______,  _______,  _______,  _______,  _______,  _______,  KC_INS,
  KC_F1,    KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
  XXXXXXX,  _______,    KC_PSCR,    KC_CAPS,              _______,      _______,          _______,  _______,  _______,  XXXXXXX
),

[_ADJUST] = LAYOUT_preonic_2x2u(
  QK_BOOT, XXXXXXX, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, MU_TOG,
  COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX,  RGB_SAI, RGB_SAD, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, MI_TOG,
  QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX,  RGB_VAI, RGB_VAD, XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, AU_TOG,
  GAMING,  XXXXXXX, XXXXXXX, XXXXXXX,  RGB_SPI, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
  _______, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case GAMING:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_GAMING);
          }
          return false;
          break;
        case ADJUST:
          if (record->event.pressed) {
            layer_on(_ADJUST);
          } else {
            layer_off(_ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
          } else {
            layer_off(_RAISE);
          }
          return false;
          break;

      }
    return true;
};

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

// bool encoder_update_user(uint8_t index, bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       register_code(KC_PGDN);
//       unregister_code(KC_PGDN);
//     } else {
//       register_code(KC_PGUP);
//       unregister_code(KC_PGUP);
//     }
//   }
//     return true;
// }

// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     } else {
//         if (muse_counter) {
//             stop_all_notes();
//             muse_counter = 0;
//         }
//     }
// #endif
// }

// bool music_mask_user(uint16_t keycode) {
//   switch (keycode) {
//     case RAISE:
//       return false;
//     default:
//       return true;
//   }
// }
