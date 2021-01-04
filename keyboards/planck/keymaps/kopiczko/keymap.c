// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

/*

    Useful functions:

        - clear_mods();
        - unregister_code(KC_LALT);
        - register_code(KC_LGUI);

 */

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum my_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _CTL_LA,
  _ADJUST,
};

enum my_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  CTL_LA,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___x___ KC_NO
#define KC_SHOT LGUI(S(KC_5)) // Screenshot working on macOS.
#define MY_SPC LT(_RAISE,KC_SPC)
#define A(kc) LALT(kc)
#define C(kc) LCTL(kc)
#define G(kc) LGUI(kc)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Esc  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Grave| Ctrl |      | Alt  | GUI  | Lower| Raise|  Spc | Alt  |      | Reset|      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,     KC_O,     KC_P,     KC_ESC  },
  {CTL_LA,   KC_A,     KC_S,     KC_D,     KC_F,    KC_G,   KC_H,   KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_ENT  },
  {KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT },
  {KC_GRV,   KC_LCTL,  ___x___,  KC_LALT,  KC_LGUI,  LOWER,  RAISE,  MY_SPC,  KC_RALT,  ___x___,  RESET,    ___x___ }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |   '  |   {  |   }  |      |      |   7  |   8  |   9  |   -  |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   \  |   "  |   (  |   )  |   ^  |   &  |   4  |   5  |   6  |   _  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   |  |   `  |   [  |   ]  |      |      |   1  |   2  |   3  |   *  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |      | Vol- | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  { KC_TILD,   ___x___,     KC_QUOT,     KC_LCBR,  KC_RCBR,  ___x___,  ___x___,  KC_7,  KC_8,     KC_9,     KC_MINS,  KC_PLUS },
  { KC_LCTRL,  KC_BSLS,     S(KC_QUOT),  KC_LPRN,  KC_RPRN,  KC_CIRC,  KC_AMPR,  KC_4,  KC_5,     KC_6,     KC_UNDS,  KC_EQL  },
  { ___x___,   S(KC_BSLS),  KC_GRV,      KC_LBRC,  KC_RBRC,  ___x___,  ___x___,  KC_1,  KC_2,     KC_3,     KC_ASTR,  KC_SLSH },
  { ___x___,   ___x___,     ___x___,     ___x___,  ___x___,  ___x___,  ___x___,  KC_0,  ___x___,  KC_VOLD,  KC_VOLU,  ___x___ }
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |ScShot|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Vol- | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  { KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_SHOT },
  { _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______ },
  { _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______ },
  { _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_VOLD,  KC_VOLU,  _______ }
},

/* CTL Layer
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |A+Bspc|  End |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   ]  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl | Home |   S  |   D  |   F  |   G  | Bspc |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  | GUI  |Lower |    Space    |Raise | Alt  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CTL_LA] = {
  {_______,  C(KC_Q),  A(KC_BSPC),  C(KC_E),  C(KC_R),  C(KC_T),    C(KC_Y),    C(KC_U),  C(KC_I),     C(KC_O),    C(KC_P),     C(KC_RBRC)  },
  {_______,  C(KC_A),  C(KC_S),     C(KC_D),  C(KC_F),  C(KC_G),    KC_BSPC,    C(KC_J),  C(KC_K),     C(KC_L),    C(KC_SCLN),  C(KC_ENT)   },
  {_______,  C(KC_Z),  C(KC_X),     C(KC_C),  C(KC_V),  C(KC_B),    C(KC_N),    C(KC_M),  C(KC_COMM),  C(KC_DOT),  C(KC_SLSH),  _______},
  {_______,  _______,  _______,     _______,  C(KC_LGUI),  C(KC_SPC),  C(KC_SPC),  C(KC_SPC),  C(KC_RALT),  ___x___,    ___x___,     ___x___     }
},


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______,  RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_DEL},
  {_______,  _______,  _______,  AU_ON,    AU_OFF,   AG_NORM,  AG_SWAP,  QWERTY,   _______,  _______,  _______,  _______},
  {_______,  MUV_DE,   MUV_IN,   MU_ON,    MU_OFF,   MI_ON,    MI_OFF,   _______,  _______,  _______,  _______,  _______},
  {_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______}
}


};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        clear_mods();
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
        clear_mods();
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case CTL_LA:
      if (record->event.pressed) {
        layer_on(_CTL_LA);
      } else {
        clear_mods();
        layer_off(_CTL_LA);
      }
      return false;
      break;
  }
  return true;
}
