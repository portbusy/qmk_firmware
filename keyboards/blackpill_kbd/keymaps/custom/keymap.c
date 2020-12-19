/* Copyright 2015-2017 Jack Humbert
 * Copyright 2020 Daniel Reibl <janos.daniel.reibl@protonmail.com>
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
#include <print.h>

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    SAVE_EEP,
    KC_ACC,
    KC_SEC,
    KC_GOOGLE,
    KC_SPOTIFY,
    KC_WHATSAPP,
    KC_TELEGRAM,
    KC_QMK_TLBX
};



enum preonic_layers {
    _QWERTY,
    _SECOND,
    _RGB,
    _LOWER,
    _RAISE,
    _ACCENTED
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    BACKLIT
};



#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x15(
    KC_GESC,     KC_1,     KC_2,     KC_3,    KC_4,        KC_5,    KC_6,   KC_7,      KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_PGUP, 
    KC_TAB,      KC_Q,     KC_W,     KC_E,    KC_R,        KC_T,    KC_Y,   KC_U,      KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,  KC_PGDN, 
    KC_ACC,      KC_A,     KC_S,     KC_D,    KC_F,        KC_G,    KC_H,   KC_J,      KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_BSLS,  KC_ENT,   KC_HOME, 
    KC_LSFT,  KC_ENT,  KC_Z,     KC_X,    KC_C,        KC_V,    KC_B,   KC_N,      KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END, 
    KC_LCTL,     KC_LGUI,  KC_LALT,  KC_SEC,  MO(_LOWER),  KC_SPC,  KC_NO,  MO(_RGB),  KC_SPC,  KC_RGUI,  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_SECOND] = LAYOUT_ortho_5x15(
    KC_NO,   KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, 
    KC_NO,   KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_F11, KC_F12, KC_P7, KC_P8, KC_P9, KC_PPLS, 
    KC_CALC, KC_MYCM, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PCMM, 
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PEQL, 
    KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P0, KC_PDOT, KC_PENT),
/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------| 1
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_RGB] = LAYOUT_ortho_5x15(
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, 
    KC_F1, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | BTN1 | BTN2 |      | MS_L | MS_D | MS_U | MS_R |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x15(
    RESET, DEBUG, EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, 
    KC_NO, KC_QMK_TLBX, KC_WHATSAPP, KC_NO, KC_NO, KC_TELEGRAM, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_D, 
    KC_NO, KC_NO, KC_SPOTIFY, KC_NO, KC_NO, KC_GOOGLE, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN4, KC_BTN1, KC_MS_U, KC_BTN2, 
    KC_PWR, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R),

/*

.3 Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x15(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_2, KC_0, KC_MINS, KC_EQL, KC_DEL, KC_PGUP,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_PGDN,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_BSLS, KC_ENT, KC_ENT, KC_HOME,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT, KC_RSFT, KC_UP, KC_END,
    KC_LCTL, KC_LGUI, KC_LALT, MO(0), MO(0), MO(0), KC_SPC, KC_SPC, KC_RALT, KC_RGUI, MO(0), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Reset |Debug |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Mu mod|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | NKRO | Swap |Un swp|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ACCENTED] = LAYOUT_ortho_5x15(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_LBRACKET, KC_NO, KC_NO, KC_NO, KC_BSLASH, KC_EQUAL, KC_SCOLON, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_ACC, KC_QUOTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LSFT, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_NO,
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RGUI, KC_RALT, KC_RCTL, KC_NO, KC_NO, KC_NO
),

};
static uint8_t sleepmode_before_mode = -1;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (rgb_matrix_get_suspend_state() && !(keycode==KC_LGUI)) {
        rgb_matrix_set_suspend_state(false);
    }
    switch (keycode) {
        case KC_QMK_TLBX:
            if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "qmk_toolbox" SS_DELAY(50) SS_TAP(X_ENT));
            }
            break;
        case KC_GOOGLE:
            if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "google" SS_DELAY(50) SS_TAP(X_ENT));
            }
            break;
        case KC_TELEGRAM:
            if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "telegram" SS_DELAY(50) SS_TAP(X_ENT));
            }
            break;
        case KC_SPOTIFY:
            if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "spotify" SS_DELAY(50) SS_TAP(X_ENT));
            }
            break;
        case KC_WHATSAPP:
            if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "whatsapp" SS_DELAY(50) SS_TAP(X_ENT));
            }
            break;
        case KC_ACC:
            if (record->event.pressed) {
                        sleepmode_before_mode = rgb_matrix_get_mode();
                        // rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect);
                        SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_LALT) SS_UP(X_LSFT));
                        layer_on(_ACCENTED);
            } else {
                rgb_matrix_mode(sleepmode_before_mode);
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_LALT) SS_UP(X_LSFT));
                layer_off(_ACCENTED);
            }
            break;
        case KC_SEC:
            if (record->event.pressed) {
                        sleepmode_before_mode = rgb_matrix_get_mode();
                        //rgb_matrix_mode(RGB_MATRIX_CUSTOM_SECOND);
                        layer_on(_SECOND);
            } else {
                //rgb_matrix_mode(sleepmode_before_mode);
                layer_off(_SECOND);
            }
            break;
        case (KC_L):
            if (get_mods() & MOD_BIT(KC_LGUI)) {
                if (record->event.pressed) {
                    
                } else {
                    rgb_matrix_set_suspend_state(true);
                }
            }
            break;
        }
    return true;
};



void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void rgb_matrix_indicators_kb(void)
{
	if (!g_suspend_state && rgb_matrix_config.enable) {
        int val = (rgb_matrix_get_val()*0.8);
        switch (get_highest_layer(layer_state)) {
            //case _qwerty:
            //    rgb_matrix_set_color(26, 0xFF, 0x00, 0x00);
            //    break;
            case _SECOND:
                rgb_matrix_set_color(1, val, val, val);
                rgb_matrix_set_color(2, val, val, val);
                rgb_matrix_set_color(3, val, val, val);
                rgb_matrix_set_color(4, val, val, val);
                rgb_matrix_set_color(5, val, val, val);
                rgb_matrix_set_color(6, val, val, val);
                rgb_matrix_set_color(7, val, val, val);
                rgb_matrix_set_color(8, val, val, val);
                rgb_matrix_set_color(9, val, val, val);
                rgb_matrix_set_color(10, val, val, val);
                rgb_matrix_set_color(19, val, val, val);
                
                rgb_matrix_set_color(20, 0, val*1.5, 0);
                rgb_matrix_set_color(21, 0, val*1.5, 0);
                rgb_matrix_set_color(22, 0, val*1.5, 0);
                rgb_matrix_set_color(23, 0, val*1.5, 0);
                rgb_matrix_set_color(24, 0, val*1.5, 0);
                rgb_matrix_set_color(25, 0, val*1.5, 0);
                rgb_matrix_set_color(26, 0, val*1.5, 0);
                rgb_matrix_set_color(27, 0, val*1.5, 0);

                rgb_matrix_set_color(11, val, 0, val);
                rgb_matrix_set_color(12, val, 0, val);
                rgb_matrix_set_color(13, val, 0, val);
                rgb_matrix_set_color(14, val, 0, val);
                rgb_matrix_set_color(15, val, 0, val);
                rgb_matrix_set_color(16, val, 0, val);
                rgb_matrix_set_color(17, val, 0, val);
                rgb_matrix_set_color(18, val, 0, val);
                rgb_matrix_set_color(41, val, 0, val);
                rgb_matrix_set_color(42, val, 0, val);
                rgb_matrix_set_color(43, val, 0, val);
                rgb_matrix_set_color(44, val, 0, val);
                rgb_matrix_set_color(45, val, 0, val);
                rgb_matrix_set_color(46, val, 0, val);
                rgb_matrix_set_color(47, val, 0, val);
                rgb_matrix_set_color(48, val, 0, val);
                rgb_matrix_set_color(72, val, 0, val);
                rgb_matrix_set_color(73, val, 0, val);
                rgb_matrix_set_color(74, val, 0, val);
                break;
            case _ACCENTED:
                rgb_matrix_set_color(20, val, val, val);
                rgb_matrix_set_color(21, val, val, val);
                rgb_matrix_set_color(22, val, val, val);
                rgb_matrix_set_color(26, val, val, val);
                rgb_matrix_set_color(31, val, val, val);
                break;
            case _LOWER:
                rgb_matrix_set_color(0, val*1.5, 0, 0);
                rgb_matrix_set_color(1, 0, 0, val*1.5);
                rgb_matrix_set_color(2, 0, val*1.5, 0);

        }
    }
}
