#include QMK_KEYBOARD_H

enum layer_number {
    _COLEMAK,
    _GAME,
    _G_LOW,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK
 * .-----------------------------------------.                    .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |SHIFT |   A  |   R  |   S  |   T  |   D  |-------.    .-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | CTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |  /   |  \   |
 * '-----------------------------------------/      /      \      \-----------------------------------------'
 *                    | ALT  | DEL  |LOWER |/SPACE /        \ENTER \|RAISE | BSPC | GUI  |
 *                    '---------------------------'          '---------------------------'
 */
    [_COLEMAK] = LAYOUT(
    KC_ESC,    KC_1,  KC_2,  KC_3,     KC_4,    KC_5,                             KC_6,        KC_7,     KC_8,     KC_9,    KC_0,     KC_EQL,
    KC_TAB,    KC_Q,  KC_W,  KC_F,     KC_P,    KC_G,                             KC_J,        KC_L,     KC_U,     KC_Y,    KC_SCLN,  KC_MINS,
    KC_LSFT,   KC_A,  KC_R,  KC_S,     KC_T,    KC_D,                             KC_H,        KC_N,     KC_E,     KC_I,    KC_O,     KC_QUOT,
    KC_LCTRL,  KC_Z,  KC_X,  KC_C,     KC_V,    KC_B,        KC_LBRC,   KC_RBRC,  KC_K,        KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_BSLS,
                             KC_LALT,  KC_DEL,  MO(_LOWER),  KC_SPACE,  KC_ENT,   MO(_RAISE),  KC_BSPC,  KC_RGUI
    ),

/* GAME
 * .-----------------------------------------.                    .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |SHIFT |   A  |   S  |   D  |   F  |   G  |-------.    .-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | CTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * '-----------------------------------------/      /      \      \-----------------------------------------'
 *                    | ALT  | DEL  |G_LOW |/SPACE /        \ENTER \|RAISE | BSPC | GUI  |
 *                    '---------------------------'          '---------------------------'
 */
    [_GAME] = LAYOUT(
    KC_ESC,    KC_1,  KC_2,  KC_3,     KC_4,    KC_5,                             KC_6,        KC_7,     KC_8,     KC_9,    KC_0,     KC_EQL,
    KC_TAB,    KC_Q,  KC_W,  KC_E,     KC_R,    KC_T,                             KC_Y,        KC_U,     KC_I,     KC_O,    KC_P,     KC_MINS,
    KC_LSFT,   KC_A,  KC_S,  KC_D,     KC_F,    KC_G,                             KC_H,        KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
    KC_LCTRL,  KC_Z,  KC_X,  KC_C,     KC_V,    KC_B,        KC_LBRC,   KC_RBRC,  KC_N,        KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_BSLS,
                             KC_LALT,  KC_DEL,  MO(_G_LOW),  KC_SPACE,  KC_ENT,   MO(_RAISE),  KC_BSPC,  KC_RGUI
    ),

/* G_LOWER
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |   6  |   7  |   8  |   9  |   0  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Y  |   U  |   I  |   O  |   P  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   H  |   J  |   K  |   L  |   ;  |-------.    .-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|   ~   |    |   `   |------+------+------+------+------+------|
 * |      |   N  |   M  |   ,  |   .  |   /  |-------|    |-------|      |  <-  |  ^   |  v   |  ->  |      |
 * '-----------------------------------------/      /      \      \-----------------------------------------'
 *                    |      |      |      |/      /        \      \|ADJUST|      |      |
 *                    '---------------------------'          '---------------------------'
 */
    [_G_LOW] = LAYOUT(
    _______,  KC_F1,  KC_F2, KC_F3,    KC_F4,    KC_F5,                        XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
    _______,  KC_Y,   KC_U,  KC_I,     KC_O,     KC_P,                         XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
    _______,  KC_H,   KC_J,  KC_K,     KC_L,     KC_SCLN,                      XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
    _______,  KC_N,   KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_TILD,  KC_GRV,   XXXXXXX,      KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT,  XXXXXXX,
                             _______,  _______,  _______,  _______,  _______,  MO(_ADJUST),  _______,  _______
    ),

/* LOWER
 * .-----------------------------------------.                    .-----------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | F12  |  F6  |  F7  |  F8  |  F9  | F10  |                    |      | HOME | END  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    .-------|   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|   ~   |    |   `   |------+------+------+------+------+------|
 * |      |      |      |VOL DN| MUTE |VOL UP|-------|    |-------|      |      |      |      |      |      |
 * '-----------------------------------------/      /      \      \-----------------------------------------'
 *                    |      |      |      |/      /        \      \|ADJUST|      |      |
 *                    '---------------------------'          '---------------------------'
 */
    [_LOWER] =  LAYOUT(
    KC_F11,   KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,                       XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_F12,   KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,                      XXXXXXX,      KC_HOME,  KC_END,   XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,  KC_PERC,                     KC_CIRC,      KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  KC_VOLD,  KC_MUTE, KC_VOLU, KC_TILD,  KC_GRV,   XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                  _______,  _______, _______, _______,  _______,  MO(_ADJUST),  _______,  _______
    ),

/* RAISE
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |-------.    .-------|  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  <-  |  ^   |  v   |  ->  |      |
 * '-----------------------------------------/      /      \      \-----------------------------------------'
 *                    |      |      |ADJUST|/      /        \      \|      |      |      |
 *                    '---------------------------'          '---------------------------'
 */
    [_RAISE] = LAYOUT(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                             KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT,  XXXXXXX,
                                  _______,  _______,  MO(_ADJUST),  _______,  _______,  _______,  _______,  _______
    ),

/* ADJUST
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | GAME |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    .-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|CAPLOCK|    |SCRLOK |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * '-----------------------------------------/      /      \      \-----------------------------------------'
 *                    |      |      |      |/      /        \      \|      |      |      |
 *                    '---------------------------'          '---------------------------'
 */
    [_ADJUST] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(_GAME),
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_CAPS,  KC_SCRL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    )
};

