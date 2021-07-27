#pragma once

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 210

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD

// Auto Shift and Retro Shift (Auto Shift for Tap Hold).
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define RETRO_SHIFT 500

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// attempt to fix a problem that the keyboard was not starting on system startup
// According to this https://github.com/qmk/qmk_firmware/issues/18511 if we use the
// settings below and the fix from develop the problem will be addressed (at least partially)
// I will wait until the fix gets merged into master.
// #define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000

// other settings I tried that didn't help
// #define USB_SUSPEND_WAKEUP_DELAY 15000
// #define NO_USB_STARTUP_CHECK
// #define EE_HANDS

#define SPLIT_TRANSACTION_IDS_KB WATCHDOG_SYNC
