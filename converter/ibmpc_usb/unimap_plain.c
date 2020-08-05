/*
Copyright 2016 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "unimap_trans.h"

#define DEFAULT_LAYER 0
#define CAPS_LOCK_LAYER 1 // Accessed with caps lock
#define CONTROL_LAYER 2 // Alternative control functions

#define AC_FN0 ACTION_LAYER_TAP_KEY(CAPS_LOCK_LAYER, KC_LGUI) // FN0 will trigger ACTION_LAYER_TAP_KEY action and switch to CAPS_LOCK_LAYER while held, or send KC_LGUI when pressed

#define AC_M0 ACTION_MACRO(0) // M0 will trigger macro 0

enum function_id {
    SMART_CTRL
};

#define AC_SCTL ACTION_FUNCTION(SMART_CTRL)

#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    /** 
     * Layer 0
     *         ,-----------------------------------------------.
     *         |F13|F14|F15|F16|F17|F18|F19|F20|F21|F22|F23|F24|
     * ,---.   |-----------------------------------------------|     ,-----------.     ,-----------.
     * |Esc|   |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|     |PrS|ScL|Pau|     |VDn|VUp|Mut|
     * `---'   `-----------------------------------------------'     `-----------'     `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
     * |-----------------------------------------------------------| |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
     * |-----------------------------------------------------------| `-----------' |---------------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| ^a|Retn|               |  4|  5|  6|KP,|
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=|
     * |-----------------------------------------------------------| ,-----------. |---------------|
     * |Ctl|Gui|Alt|MHEN|     Space      |HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  #|  0|  .|Ent|
     * `-----------------------------------------------------------' `-----------' `---------------'
     */
    UNIMAP(
              F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
    ESC,      M0 ,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,NLCK,PAUS,         VOLD,VOLU,MUTE,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, JYEN,BSPC,     INS, HOME,PGUP,    BSPC,PSLS,PAST,PMNS,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     BSLS,     DEL, END, PGDN,    P7,  P8,  P9,  PPLS,
    FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     NUHS,ENT,                         P4,  P5,  P6,  PCMM,
    LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RO,  RSFT,          UP,           P1,  P2,  P3,  PENT,
    SCTL,LGUI,LALT,MHEN,          SPC,           HENK,KANA,RALT,RGUI,FN0, RCTL,     LEFT,DOWN,RGHT,         P0,  PDOT, PEQL
    ),
    /**
     * Layer 1 - Caps Lock layer
     */
    UNIMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,VOLU,TRNS,TRNS,TRNS,UP  ,TRNS,TRNS,TRNS,TRNS ,    TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,MPRV,MPLY,MNXT,VOLD,TRNS,TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
    ),
    /**
     * Layer 2 - Smart CTRL Layer
     */
    UNIMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,VOLU,TRNS,TRNS,TRNS,UP  ,TRNS,TRNS,TRNS,TRNS ,    TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    CAPS,MPRV,MPLY,MNXT,VOLD,TRNS,TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,          PGUP,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     HOME,PGDN,END,          TRNS,TRNS,TRNS
    )
};

// const action_t PROGMEM fn_actions[] = {
//     [3] = ACTION_FUNCTION(SMART_CTRL)
// };

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
            case 0:
                return MACRO( I(0), T(H), T(E), T(L), T(L), T(O), END );
            case 1:
                return MACRO( D(LALT), D(TAB), END );
        }     
    }
    return MACRO_NONE;
};

//trying to implement smartalt from https://github.com/tmk/tmk_keyboard/wiki/Keymap-examples and https://github.com/chenzhihuai1990/tmk_keyboard/blob/master/keyboard/hhkb/keymap_smartalt.c
// Look at implement user function here: https://github.com/tmk/tmk_core/blob/master/doc/keymap.md#243-implement-user-function and try to work out how to code this custom function


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
    case SMART_CTRL:
        if (record->event.pressed) {
                add_weak_mods(MOD_BIT(KC_LCTL));
                layer_invert(CONTROL_LAYER);
            }else
            {
                send_keyboard_report();// send previous event: D(KC_LCTL)
                layer_invert(CONTROL_LAYER);
                del_weak_mods(MOD_BIT(KC_LCTL));
                send_keyboard_report();
            }
            break;
    }
}

