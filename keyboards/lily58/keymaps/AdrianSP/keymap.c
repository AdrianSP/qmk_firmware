// Copyright 2021 Nicolas Druoton (druotoni)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "transactions.h"

// global
#include "gui_state.h"
#include "boot.h"
#include "navi_logo.h"

#include "draw_helper.h"
#include "fast_random.h"

// left side
#include "layer_frame.h"
#include "burst.h"

// right side
#include "ring.h"

// clang-format off
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
 *                    |      |      |      |/      /        \      \|      |      |      |
 *                    '---------------------------'          '---------------------------'
 */
    [_G_LOW] = LAYOUT(
    _______,  KC_6,  KC_7,  KC_8,     KC_9,     KC_0,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX, 
    _______,  KC_Y,  KC_U,  KC_I,     KC_O,     KC_P,                         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX, 
    _______,  KC_H,  KC_J,  KC_K,     KC_L,     KC_SCLN,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
    _______,  KC_N,  KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_TILD,  KC_GRV,   XXXXXXX,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT,  XXXXXXX, 
                            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______ 
    ),

/* LOWER
 * .-----------------------------------------.                    .-----------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | F12  |  F6  |  F7  |  F8  |  F9  | F10  |                    |      | HOME | END  |      |  =   |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    .-------|   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|   ~   |    |   `   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * '-----------------------------------------/      /      \      \-----------------------------------------'
 *                    |      |      |      |/      /        \      \|ADJUST|      |      |
 *                    '-------grep--------------------'          '---------------------------'
 */
    [_LOWER] =  LAYOUT(
    KC_F11,   KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_F12,   KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,                       XXXXXXX,  KC_HOME,  KC_END,  XXXXXXX,  KC_EQL,   KC_PLUS,
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,  KC_PERC,                      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_TILD,  KC_GRV,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                  _______,  _______, _______, _______,  _______,  _______,   _______,  _______
    ),

/* RAISE
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |-------.    .-------|  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------| GAME  |    |COLEMAK|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  <-  |  ^   |  v   |  ->  |      |
 * '-----------------------------------------/      /      \      \-----------------------------------------'
 *                    |      |      |ADJUST|/      /        \      \|      |      |      |
 *                    '---------------------------'          '---------------------------'
 */
    [_RAISE] = LAYOUT(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   TG(_GAME),
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX, 
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT,  XXXXXXX,
                                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    )
};
// clang-format on

// sync transport
typedef struct _sync_keycode_t {
    uint16_t keycode;
} sync_keycode_t;

// force rigth side to update
bool b_sync_need_send = false;

// last keycode typed
sync_keycode_t last_keycode;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // vertical orientation
    return OLED_ROTATION_270;
}

void render(gui_state_t t) {
    // logo
    render_logo(t);

#if IS_LEFT
    // left side
    render_layer_frame(t);
    render_gears();

    decay_scope();
    render_scope(t);
#endif

#if IS_RIGHT
    // right side
    render_circle(t);
#endif
}

void update(uint16_t keycode) {
#if IS_LEFT
    update_scope();
#endif

#if IS_RIGHT
    update_circle(keycode);
#endif
}

void reset(void) {
#if IS_LEFT
    reset_scope();
#endif

#if IS_RIGHT
    reset_ring();
#endif
}

void set_wackingup_mode_clean(void) {
    oled_clear();
    reset();
}

bool oled_task_user(void) {
    gui_state_t t = get_gui_state();

    // in sleep mode => turn display off
    if (t == _SLEEP) {
        oled_off();
        return false;
    }

    // not in sleep mode => screen is on
    oled_on();

#ifdef WITH_BOOT
    // in booting mode => display booting animation
    if (t == _BOOTING) {
        bool boot_finished = render_boot();
        if (boot_finished) {
            // end of the boot : wacking up
            set_wackingup_mode_clean();
            update_gui_state();
        }
        return false;
    }
#endif

    // in halting mode => display booting animation
    if (t == _HALTING) {
        render_halt();
        return false;
    }

    render(t);
    return false;
}

void process_key(uint16_t keycode) {
    // update screen with the new key
    update(keycode);

    gui_state_t t = get_gui_state();

    if (t == _IDLE) {
        // wake up animation
        reset();
    }

    if (t == _BOOTING || t == _HALTING) {
        // cancel booting or halting : waking_up
        set_wackingup_mode_clean();
    }

    if (t == _SLEEP) {
        // boot sequence
        set_wackingup_mode_clean();
        reset_boot();
    }

    update_gui_state();
}

void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const sync_keycode_t* m2s = (const sync_keycode_t*)in_data;
    // get the last char typed on left side and update the right side
    process_key(m2s->keycode);
}

void keyboard_post_init_user(void) {
    // callback for tranport sync data
    transaction_register_rpc(USER_SYNC_A, user_sync_a_slave_handler);
}

void housekeeping_task_user(void) {
    // only for master side
    if (!is_keyboard_master()) return;

    // only if a new char was typed
    if (!b_sync_need_send) return;

    // send the char to the slave side : sync is done
    if (transaction_rpc_send(USER_SYNC_A, sizeof(last_keycode), &last_keycode)) {
        b_sync_need_send = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        // master : store keycode to sent to the other side to be process_key
        last_keycode.keycode = keycode;
        b_sync_need_send     = true;

        // gui process the input
        process_key(keycode);
    }
    return true;
}

#if IS_LEFT
layer_state_t layer_state_set_user(layer_state_t state) {
    // update the frame with the layer name
    update_layer_frame(state);
    return state;
}
#endif
