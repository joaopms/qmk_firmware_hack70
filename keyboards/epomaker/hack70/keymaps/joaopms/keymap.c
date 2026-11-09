/* Copyright 2026 Epomaker
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
#include "rdmctmzt_common.h"

// 8 layers max (DYNAMIC_KEYMAP_LAYER_COUNT): Raise/Adjust shared by Win and Mac.
enum layer_names {
    _BASE_W,
    _BASE_M,
    _FN_W,
    _FN_M,
    _LOWER_W,
    _LOWER_M,
    _RAISE,
    _ADJUST,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Windows base layer
    [_BASE_W] = LAYOUT(
        QK_GESC,       KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,  KC_NO,    KC_BSPC,
        KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_RBRC,  KC_NO,    KC_NO,    KC_DEL,
        MO(_FN_W),     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_NUHS,  KC_NO,    KC_ENT,
        OSM(MOD_LSFT), KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_QUOT,  KC_PGUP,  KC_UP,    KC_PGDN,
        KC_LCTL,       KC_LGUI,  KC_LALT,  MO(_LOWER_W),       KC_SPC,             KC_ENT,             MO(_RAISE), KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // Mac base layer
    [_BASE_M] = LAYOUT(
        QK_GESC,       KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,  KC_NO,    KC_BSPC,
        KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_RBRC,  KC_NO,    KC_NO,    KC_DEL,
        MO(_FN_M),     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,    KC_ENT,
        OSM(MOD_LSFT), KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_LBRC,  KC_PGUP,  KC_UP,    KC_PGDN,
        KC_LCTL,       KC_LALT,  KC_LGUI,  MO(_LOWER_M),       KC_SPC,             KC_ENT,             MO(_RAISE), KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // Windows Fn layer
    [_FN_W] = LAYOUT(
        KC_GRV,        MD_BLE1,  MD_BLE2,  MD_BLE3,  MD_24G,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RGB_RTOG,
        KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PSCR,  KC_SCRL,  KC_PAUS,  KC_NO,    RM_HUED,  RM_HUEU,  RM_NEXT,  KC_INS,
        KC_NO,         TO(_BASE_W), TO(_BASE_M), KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RM_SATD,  RM_SATU,  KC_NO,    KC_NO,
        OSM(MOD_LSFT), LG_MOD,   LG_HUI,   KC_NO,    KC_NO,    KC_NO,    SIX_N,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_RSFT,  KC_HOME,  RM_VALU,  KC_END,
        KC_LCTL,       KC_NO,    QK_WLO,   KC_LALT,            EE_CLR,             EE_CLR,             KC_RALT,  KC_APP,   QK_BAT,   RM_SPDD,  RM_VALD,  RM_SPDU
    ),
    // Mac Fn layer
    [_FN_M] = LAYOUT(
        KC_GRV,        MD_BLE1,  MD_BLE2,  MD_BLE3,  MD_24G,   KC_NO,    KC_NO,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_RTOG,
        KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RM_HUED,  RM_HUEU,  RM_NEXT,  KC_INS,
        KC_NO,         TO(_BASE_W), TO(_BASE_M), KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RM_SATD,  RM_SATU,  KC_NO,    KC_NO,
        OSM(MOD_LSFT), LG_MOD,   LG_HUI,   KC_NO,    KC_NO,    KC_NO,    SIX_N,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_RSFT,  KC_HOME,  RM_VALU,  KC_END,
        KC_LCTL,       KC_NO,    KC_LALT,  KC_LGUI,            EE_CLR,             EE_CLR,             KC_RGUI,  KC_APP,   QK_BAT,   RM_SPDD,  RM_VALD,  RM_SPDU
    ),
    // Windows Lower (PT-ISO symbols)
    [_LOWER_W] = LAYOUT(
        KC_NO,         KC_NO,      KC_NO,   KC_NO,      KC_NO,      KC_NO,   KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,
        KC_NO,         S(KC_1),    S(KC_2), S(KC_3),    ALGR(KC_2), S(KC_5), S(KC_6),   S(KC_GRV),  S(KC_0),    S(KC_MINS), KC_MINS,    KC_INS,   KC_NO,    KC_NO,    KC_NO,
        KC_NO,         S(KC_8),    S(KC_9), KC_NUBS,    S(KC_NUBS), KC_GRV,  S(KC_7),   ALGR(KC_8), ALGR(KC_9), ALGR(KC_7), ALGR(KC_0), KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,       ALGR(KC_E), S(KC_4), ALGR(KC_3), KC_NO,      KC_EQL,  S(KC_EQL), KC_LBRC,    S(KC_LBRC), KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,       KC_TRNS,    KC_TRNS, KC_TRNS,                KC_NO,              KC_NO,                  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_NO,    KC_NO,    KC_NO
    ),
    // Mac Lower (PT-ISO symbols)
    [_LOWER_M] = LAYOUT(
        KC_NO,         KC_NO,      KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,
        KC_NO,         S(KC_1),    S(KC_2), S(KC_3), ALGR(KC_2), S(KC_5), S(KC_6),    S(KC_BSLS), S(KC_0),    S(KC_MINS), KC_MINS,    KC_INS,   KC_NO,    KC_NO,    KC_NO,
        KC_NO,         S(KC_8),    S(KC_9), KC_GRV,  S(KC_GRV),  KC_BSLS, S(KC_7),    ALGR(KC_8), ALGR(KC_9), S(A(KC_8)), S(A(KC_9)), KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,       ALGR(KC_3), S(KC_4), A(KC_4), KC_NO,      A(KC_X), S(A(KC_X)), KC_EQL,     S(KC_EQL),  KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,       KC_TRNS,    KC_TRNS, KC_TRNS,             KC_NO,               KC_NO,                  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_NO,    KC_NO,    KC_NO
    ),
    // Raise (numbers + navigation)
    [_RAISE] = LAYOUT(
        KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,   KC_NO,    KC_NO,    KC_NO,
        KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_NO,              KC_NO,              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,    KC_NO
    ),
    // Adjust (Lower + Raise)
    [_ADJUST] = LAYOUT(
        KC_NO,         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_NO,
        KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_CAPS,       KC_SCRL,  KC_PAUS,  KC_NO,    KC_PSCR,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,       KC_NO,    KC_NO,    KC_NO,    KC_MPLY,  KC_MUTE,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,            DF(_BASE_W),        DF(_BASE_M),        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    EE_CLR,   QK_BOOT
    )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER_W, _RAISE, _ADJUST);
    return update_tri_layer_state(state, _LOWER_M, _RAISE, _ADJUST);
}
