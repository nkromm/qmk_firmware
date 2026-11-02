// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Base layers must come before RAISE and ADJUST: a higher layer wins, so a
// base layer above them would hide them and leave no way back.
enum lulu_layers {
    _COLEMAK,
    _COLEMAK_GAMING,
    _GAMING,
    _RAISE,
    _ADJUST,
};

enum lulu_keycodes {
    COLEMAK = SAFE_RANGE,
    COLEMAK_GAMING,
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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK - DHm
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   &  |                    |   *  |   ←  |   ↓  |   ↑  |   →  | Bksp |
 * |------+------+------+------+------+------|                    +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |  ;   |  \   |
 * |------+------+------+------+------+------|                    -------+------+------+------+------+------|
 * |  '   |  M_A |  M_R |  M_S |  M_T |   G  |-------.    ,-------|   M  |  M_N |  M_E |  M_I |  M_O |  -   |
 * |------+------+------+------+------+------|Adjust |    |Adjust |------+------+------+------+------+------|
 * |  `   |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |  /   |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 |  Alt   |  [   |  ]   | / Space /       \ Enter\  |  (   |  )   |  Alt   |
 *                 |        |      |      |/       /         \      \ |      |      |        |
 *                 `----------------------'-------'           '------''----------------------'
 */

 [_COLEMAK] = LAYOUT(
  KC_ESC,         KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_AMPR,                   KC_ASTR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_BSPC,
  KC_TAB,         KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSLS,
  KC_QUOT,        MOD_A,      MOD_R,      MOD_S,      MOD_T,      KC_G,                      KC_M,    MOD_N,   MOD_E,   MOD_I,   MOD_O,    KC_MINS,
  KC_GRV,         KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,    ADJUST,  ADJUST,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_EQL,
                              KC_LALT,    KC_LBRC,    KC_RBRC,    LT_RSSP,                   LT_RSRT, KC_LPRN, KC_RPRN, KC_RALT
),

/* COLEMAK_GAMING: Colemak with plain 1-5 and no home-row mods on the left, plain modifiers on the left thumbs
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   *  |   ←  |   ↓  |   ↑  |   →  | Bksp |
 * |------+------+------+------+------+------|                    +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |  ;   |  \   |
 * |------+------+------+------+------+------|                    -------+------+------+------+------+------|
 * |  '   |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |  M_N |  M_E |  M_I |  M_O |  -   |
 * |------+------+------+------+------+------|Adjust |    |Adjust |------+------+------+------+------+------|
 * |  `   |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |  /   |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 |  Alt   | Ctrl | Shift| / Space /       \ Enter\  |  (   |  )   |        |
 *                 |        |      |      |/       /         \      \ |      |      |        |
 *                 `----------------------'-------'           '------''----------------------'
 */
 [_COLEMAK_GAMING] = LAYOUT(
  KC_ESC,         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                      KC_ASTR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_BSPC,
  KC_TAB,         KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_BSLS,
  KC_QUOT,        KC_A,       KC_R,       KC_S,       KC_T,       KC_G,                      KC_M,    MOD_N,   MOD_E,   MOD_I,   MOD_O,    KC_MINS,
  KC_GRV,         KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,    ADJUST,  ADJUST,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_EQL,
                              KC_LALT,    KC_LCTL,    KC_LSFT,    KC_SPC,                    LT_RSRT, KC_LPRN, KC_RPRN, XXXXXXX
),

/* GAMING: COLEMAK_GAMING in QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   *  |   ←  |   ↓  |   ↑  |   →  | Bksp |
 * |------+------+------+------+------+------|                    +------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    -------+------+------+------+------+------|
 * |  '   |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |  M_J |  M_K |  M_L |  M_; |  -   |
 * |------+------+------+------+------+------|Adjust |    |Adjust |------+------+------+------+------+------|
 * |  `   |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |  /   |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 |  Alt   | Ctrl | Shift| / Space /       \ Enter\  |  (   |  )   |        |
 *                 |        |      |      |/       /         \      \ |      |      |        |
 *                 `----------------------'-------'           '------''----------------------'
 */
 [_GAMING] = LAYOUT(
  KC_ESC,         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                      KC_ASTR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_BSPC,
  KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
  KC_QUOT,        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                      KC_H,    MOD_J,   MOD_K,   MOD_L,   MOD_SCLN, KC_MINS,
  KC_GRV,         KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,    ADJUST,  ADJUST,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_EQL,
                              KC_LALT,    KC_LCTL,    KC_LSFT,    KC_SPC,                    LT_RSRT, KC_LPRN, KC_RPRN, XXXXXXX
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  C-z |  C-x |  C-c |  C-v |   %  |                    |   ^  | Home | PgDn | PgUp | End  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Del  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ins  |      |      |      |      |      |-------.    ,-------| NumL | ScrL | Pause| KP - | Menu | Ins  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------|    |-------|  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | XXXX | PSCR | CAPS | /       /       \      \  |AltGr | RCtl | RGui |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_RAISE] = LAYOUT(
  KC_ESC,         LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_PERC,                   KC_CIRC, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_BSPC,
  KC_DEL,         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL,
  KC_INS,         _______,    _______,    _______,    _______,    _______,                   KC_NUM,  KC_SCRL, KC_PAUS, KC_PMNS, KC_APP,   KC_INS,
  KC_F1,          KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,   _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,
                              XXXXXXX,    KC_PSCR,    KC_CAPS,    _______,                   _______, KC_RALT, KC_RCTL, KC_RGUI
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Boot |      | RGB  | Hue+ | Hue- |      |                    |      | Vol- | Vol+ |      |      | Boot |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Colemk|      | Mode+| Sat+ | Sat- |      |                    |      | Prev | Next |      |      |Colemk|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CmkGam|      | Mode-| Bri+ | Bri- |      |-------.    ,-------|      | Play | Mute |      |      |CmkGam|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |Gaming|      |      | Spd+ | Spd- |      |-------|    |-------|      |      |      |      |      |Gaming|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */
 [_ADJUST] = LAYOUT(
  QK_BOOT,        XXXXXXX,    RM_TOGG,    RM_HUEU,    RM_HUED,    XXXXXXX,                   XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,  QK_BOOT,
  COLEMAK,        XXXXXXX,    RM_NEXT,    RM_SATU,    RM_SATD,    XXXXXXX,                   XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,  COLEMAK,
  COLEMAK_GAMING, XXXXXXX,    RM_PREV,    RM_VALU,    RM_VALD,    XXXXXXX,                   XXXXXXX, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX,  COLEMAK_GAMING,
  GAMING,         XXXXXXX,    XXXXXXX,    RM_SPDU,    RM_SPDD,    XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  GAMING,
                              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};
// Which hand each key belongs to, for CHORDAL_HOLD. Thumb keys and the keys above
// them are '*' so Space/Enter (Raise) and Adjust also work with keys on the same hand.
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L',                'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L',                'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L',                'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', '*',      '*', 'R', 'R', 'R', 'R', 'R', 'R',
                 '*', '*', '*', '*',      '*', '*', '*', '*'
);
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case COLEMAK_GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_GAMING);
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
    }
    return true;
}
