/* keymap.c - Keebio Iris Rev 8. - downbackdad keymap
 * 
 * Contains the primary configuration details for my custom QMK keymap on the
 * Keebio Iris Rev. 8.
 * 
 * Author: Kris Nelson
 * Created: 2026-01-30
 * URL: https://github.com/DownBackDad/qmk_userspace
 */

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

/******************************************************************************
 * Definition: Layers.
 ******************************************************************************/

enum layers {
  _GREPHATI, // Start of base layers.
  _GAMING, // End of base layers.
  _EXTEND,
  _SYMBOL,
  _FUNCTION
};

/******************************************************************************
 * Definition: Keycode aliases.
 ******************************************************************************/

// Default layer changes.
// Naming scheme: LC_XXXX
//   XXXX = Name (shortened) of layer that gets set as default (4 chars).
#define LC_GAME DF(_GAMING)
#define LC_GREP DF(_GREPHATI)

// Home row mods.
// Naming scheme: HM_XYYZ
//   X  = Whether the mod is the left or right one (one char).
//   YY = The type of mod (two chars).
//        AL = Alt/Meta
//        CT = Ctrl
//        GU = Gui/Win
//        SF = Shift
//   Z  = The letter the mod sits on (one char).
#define HM_LALR LALT_T(KC_R)
#define HM_LCTT LCTL_T(KC_T)
#define HM_LGUN LGUI_T(KC_N)
#define HM_LSFS LSFT_T(KC_S)
#define HM_RALI RALT_T(KC_I)
#define HM_RCTE RCTL_T(KC_E)
#define HM_RGUA RGUI_T(KC_A)
#define HM_RSFH RSFT_T(KC_H)

// Layer taps.
// Naming scheme: LT_XYZZ
//   X  = The letter the tap sits on (1 char). Use "T" for a thumb key.
//   Y  = The press character (one char).
//        0 = Magic key.
//        1 = Repeat key.
//        _ = Space or no press character.
//   ZZ = The hold layer (2 chars).
#define LT_T_FU MO(_FUNCTION)
#define LT_T_SY MO(_SYMBOL)
#define LT_T_EX LT(_EXTEND, KC_SPC)
#define LT_T0EX LT(_EXTEND, KC_0)
//#define LT_T1SY LT(_SYMBOL, KC_1)

/******************************************************************************
 * Definition: Combos.
 ******************************************************************************/

enum combos {
  GREPHATI_CAPSWORD,
  GREPHATI_ENTER,
};

const uint16_t PROGMEM grephati_capsword_combo[] = {HM_LSFS, HM_RSFH, COMBO_END};
const uint16_t PROGMEM grephati_enter_combo[] = {KC_P, HM_RCTE, COMBO_END};

combo_t key_combos[] = {
  [GREPHATI_CAPSWORD] = COMBO(grephati_capsword_combo, CW_TOGG),
  [GREPHATI_ENTER] = COMBO(grephati_enter_combo, KC_ENT),
};

/******************************************************************************
 * Definition: Chordal hold layout.
 ******************************************************************************/

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
                      'L', 'L', 'L', 'R', 'R', 'R');

/******************************************************************************
 * Definition: Keymaps.
 ******************************************************************************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_GREPHATI] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Z,    KC_L,    KC_D,    KC_W,    KC_B,                      KC_J,    KC_F,    KC_O,    KC_U,    KC_SCLN, KC_BSLS,
    KC_MINS, HM_LGUN, HM_LALR, HM_LCTT, HM_LSFS, KC_G,                      KC_Y,    HM_RSFH, HM_RCTE, HM_RALI, HM_RGUA, KC_QUOT,
    KC_LSFT, KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,    _______, _______, KC_K,    KC_P,    KC_SLSH, KC_COMM, KC_DOT,  KC_RSFT,
                                        LT_T_FU, LT_T_SY, LT_T0EX, LT_T_EX, LT_T_SY, LT_T_FU),
  [_GAMING] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                        KC_LALT, KC_LCTL, KC_SPC,  LT_T_EX, LT_T_SY, LT_T_FU),
  [_EXTEND] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ENT,                    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______,
                                        _______, QK_LLCK, KC_SPC,  KC_SPC,  QK_LLCK, _______),
  [_SYMBOL] = LAYOUT(
    KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LBRC, KC_RBRC, _______,                   _______, KC_PLUS, _______, _______, _______, _______,
    _______, _______, _______, KC_LCBR, KC_RCBR, _______,                   _______, KC_EQL,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, KC_SPC,  KC_SPC,  _______, _______),
  [_FUNCTION] = LAYOUT(
    LC_GREP, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    LC_GAME, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_F12,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
                                        _______, _______, KC_SPC,  KC_SPC,  _______, _______),
};

/******************************************************************************
 * Behaviour: Keycode custom processing.
 ******************************************************************************/

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
  case LT_T0EX: // Extend layer on hold, magic on tap.
    if (record->tap.count) {
      alt_repeat_key_invoke(&record->event);
      return false;
    }
  }
  
  return true;
}

/******************************************************************************
 * Behaviour: Magic.
 ******************************************************************************/

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  switch (biton16(default_layer_state)) {
  case _GREPHATI:
    switch (keycode) {
    case KC_MINS: return KC_MINS;
    }
  }
  
  return KC_NO; // Do nothing if no rules are matched.
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
  switch (keycode) {
  case LT_T0EX: return false;
  }
  
  return true;
}

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C
