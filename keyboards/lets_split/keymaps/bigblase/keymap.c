#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "sendstring_french.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _AZERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAMES 3


enum custom_keycodes {
	AZERTY = SAFE_RANGE,
	QWERTY,
	SENT
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define GAMES DF(_GAMES)
#define AZERTY DF(_AZERTY)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Azerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | ^  ¨ |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  | €    |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   W  |   X  |   C  |   V  |   B  |   N  |   ,  |   ;  |   :  |   !  |°     | SEND HELP 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Gui  | Alt  | HYPER|Lwr ( | Space| Bksp |rse ) | _    | Mute | &    | Game |
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = LAYOUT_ortho_4x12( 
	KC_TAB,  FR_A,    FR_Z,     FR_E,     FR_R,                FR_T,   FR_Y,    FR_U,               FR_I,    FR_O,    KC_P,    FR_CIRC, \
	KC_ESC,  FR_Q,    FR_S,     FR_D,     FR_F,                FR_G,   FR_H,    FR_J,               FR_K,    FR_L,    FR_M,    FR_EURO, \
	KC_LSFT, FR_W,    FR_X,     FR_C,     FR_V,                FR_B,   FR_N,    FR_COMM,            FR_SCLN, FR_COLN, FR_EXLM, FR_DEG,  \
	KC_LCTL, KC_LGUI,  KC_LALT, KC_HYPR,  LT(LOWER, FR_LPRN),  KC_SPC, KC_BSPC, LT(RAISE, FR_RPRN), FR_UNDS, KC_MUTE, FR_AMPR, GAMES    \
), 
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |RESET | {    | }    |  é   | "    |  '   |      |  @   |  ç   |      |      |      |
 * |------+------+------|------+------+-------------+------+------+------+------+------|
 * |      | [    |  ]   |  è   |  |   |  `   | left | down |  up  | right|      |  $   |
 * |------+------+------|------+------+------|------+------+------+------+------+------|
 * |      |  <   |  >   |  à   |    ~ |      |      |      |      |   \  |      |      |
 * |------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |  #   |   %  |  ù   |      |      | del  |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
	RESET,   FR_LCBR, FR_RCBR, FR_EACU, FR_DQUO, FR_QUOT, XXXXXXX, FR_AT,   FR_CCED, XXXXXXX, XXXXXXX, XXXXXXX, \
	_______, FR_LBRC, FR_RBRC, FR_EGRV, FR_PIPE, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,FR_CIRC, FR_DLR,  \
	_______, FR_LABK, FR_RABK, FR_AGRV, FR_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_BSLS, XXXXXXX, XXXXXXX, \
	_______, FR_HASH, FR_PERC, FR_UGRV, _______, XXXXXXX, KC_DEL,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ²  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |RESET |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------|------+------+------+------+------+------|------|
 * |   %  |   +  |  -   |  *   |  /   |  =   |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|------|
 * |      |      |      |      |      |ent   |SENT  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_ortho_4x12( \
	FR_GRV,  FR_1,    FR_2,    FR_3,    FR_4,    FR_5,    FR_6,    FR_7,    FR_8,    FR_9,    FR_0,    RESET,  \
	KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
	_______, KC_PLUS, KC_PMNS, KC_PAST, KC_PSLS, KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
	_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  SENT,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
),


/* Games
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |DEFLT |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |LEDON |LEDCHG|LED+  |LED-  |      |
 * |------+------+------+------+------|------+------+------+------+------+------|------|
 * |      |      |      |      |      |      |      |VOLON |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|------|
 * |      |  1   |  2   |  3   |  4   | space|      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'_d_______________________88888_
 */

[_GAMES] = LAYOUT_ortho_4x12( \
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, AZERTY,  \
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
	_______, FR_1,    FR_2,    FR_3,    FR_4,    KC_SPC,  _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
)


};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case AZERTY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_AZERTY);
			}
			return false;

		case SENT:
			if (record->event.pressed) {
				SEND_STRING("sudo pacman -S ");
			}
			return false;
	}
  return true;
}
