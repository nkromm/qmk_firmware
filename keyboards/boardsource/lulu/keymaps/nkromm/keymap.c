// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "transactions.h"

enum lulu_layers {
    _COLEMAK,
    _QWERTY,
    _RAISE,
    _ADJUST,
    _GAMING,
};

enum lulu_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  RAISE,
  ADJUST,
  GAMING,
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
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   ←  |   ↓  |   ↑  |   →  | Bksp |
 * |------+------+------+------+------+------|                    +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |  ;   |  \   |
 * |------+------+------+------+------+------|                    -------+------+------+------+------+------|
 * |  '   |  M_A |  M_R |  M_S |  M_T |   G  |-------.    ,-------|   M  |  M_N |  M_E |  M_I |  M_O |  -   |
 * |------+------+------+------+------+------| Media |    |  RGB  |------+------+------+------+------+------|
 * |  `   |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |  /   |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | ADJUST |  [   |  ]   | / Space /       \ Enter\  |  (   |  )   | ADJUST |
 *                 |        |      |      |/       /         \      \ |      |      |        |
 *                 `----------------------'-------'           '------''----------------------'
 */

 [_COLEMAK] = LAYOUT(
  KC_ESC,  KC_EXLM,  KC_AT,  KC_HASH, KC_DLR,  KC_AMPR,                            KC_ASTR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_BSPC,
  KC_TAB,  KC_Q,     KC_W,   KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSLS,
  KC_QUOT, MOD_A,    MOD_R,  MOD_S,   MOD_T,   KC_G,                               KC_M,    MOD_N,   MOD_E,   MOD_I,   MOD_O,    KC_MINS,
  KC_GRV,  KC_Z,     KC_X,   KC_C,    KC_D,    KC_V,    KC_MPLY,         RGB_TOG,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_EQL,
                             ADJUST,  KC_LBRC, KC_RBRC, LT_RSSP,         LT_RSRT,  KC_LPRN, KC_RPRN, ADJUST
),

 [_QWERTY] = LAYOUT(
  KC_ESC,  KC_EXLM,  KC_AT,  KC_HASH, KC_DLR,  KC_AMPR,                            KC_ASTR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_BSPC,
  KC_TAB,  KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
  KC_QUOT, MOD_A,  MOD_S,  MOD_D,   MOD_F,   KC_G,                                 KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SCLN, KC_MINS,
  KC_GRV,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    KC_MPLY,           RGB_TOG,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_EQL,
                           ADJUST,  KC_LBRC, KC_RBRC, LT_RSSP,           LT_RSRT,  KC_LPRN, KC_RPRN, ADJUST
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  C-z |  C-x |  C-c |  C-v |   &  |                    |   *  | Home | PgDn | PgUp | End  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Del  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ins  |      |      |  C-s |      |      |-------.    ,-------|      |      |      |      |      | Ins  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------|    |-------|  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | XXXX | PSCR | CAPS | /       /       \      \  |      |      | XXXX |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_RAISE] = LAYOUT(
  KC_ESC,   LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_PERC,                          KC_CIRC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,
  KC_DEL,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_INS,   _______,    _______,    LCTL(KC_S), _______,    _______,                          _______, _______, _______, _______, _______, KC_INS,
  KC_F1,    KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,     _______,      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                    XXXXXXX,    KC_PSCR,    KC_CAPS,   _______,      _______, _______, _______, XXXXXXX
),

 [_ADJUST] = LAYOUT(
  QK_BOOT, XXXXXXX, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD,                   RGB_HUI, RGB_HUD, RGB_MOD, RGB_RMOD, XXXXXXX, QK_BOOT,
  COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX,  RGB_SAI, RGB_SAD,                   RGB_SAI, RGB_SAD, XXXXXXX, XXXXXXX,  XXXXXXX, COLEMAK,
  QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX,  RGB_VAI, RGB_VAD,                   RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX,  XXXXXXX, QWERTY,
  GAMING,  XXXXXXX, XXXXXXX, XXXXXXX,  RGB_SPI, RGB_SPD, XXXXXXX, XXXXXXX, RGB_SPI, RGB_SPD, XXXXXXX, XXXXXXX,  XXXXXXX, GAMING,
                             _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),

 [_GAMING] = LAYOUT(
  KC_ESC,  KC_1,  KC_2,  KC_3,    KC_4,     KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,  KC_Q,  KC_W,  KC_E,    KC_R,     KC_T,                                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
  KC_QUOT, KC_A,  KC_S,  KC_D,    KC_F,     KC_G,                                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_MINS,
  KC_GRV,  KC_Z,  KC_X , KC_C,    KC_V,     KC_B,    COLEMAK,              COLEMAK,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_EQL,
                         KC_LALT, KC_LCTL, KC_LSFT, KC_SPC,               LT_RSRT,  KC_LPRN, KC_RPRN, KC_CAPS
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


static bool watchdog_ping_done = false;
static uint32_t watchdog_timer = 0;

void watchdog_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) { watchdog_ping_done = true; }

void keyboard_post_init_kb(void) {
    keyboard_post_init_user();
    transaction_register_rpc(WATCHDOG_SYNC, watchdog_slave_handler);
    watchdog_timer = timer_read32();
}

void housekeeping_task_kb(void) {
    if (!watchdog_ping_done) {
        if (is_keyboard_master()) {
            if (timer_elapsed32(watchdog_timer) > 100) {
                uint8_t any_data = 1;
                if (transaction_rpc_send(WATCHDOG_SYNC, sizeof(any_data), &any_data)) {
                    watchdog_ping_done = true;  // successful ping
                } else {
                    dprint("Watchdog ping failed!\n");
                }
                watchdog_timer = timer_read32();
            }
        } else {
            if (timer_elapsed32(watchdog_timer) > SPLIT_USB_TIMEOUT + 1000) {
                mcu_reset();
            }
        }
    }
}
