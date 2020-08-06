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

/* ----- Layer Definitons ----- */

#define DEFAULT_LAYER       0
#define CAPS_LOCK_LAYER     1 // Accessed with caps lock
#define SMART_ALT_LAYER     2 // Alternative ALT functions
#define SMART_ALT_DEF_LAYER 3 // Define what smart alt does

/* ----- Layer Key Definitions ----- */

#define AC_TL0 ACTION_LAYER_TAP_KEY(CAPS_LOCK_LAYER, KC_LGUI) // FN0 will trigger ACTION_LAYER_TAP_KEY action and switch to CAPS_LOCK_LAYER while held, or send KC_LGUI when pressed

/* ----- Macro Key Defintions ----- */

#define AC_M0 ACTION_MACRO(0) // M0 will trigger macro 0

/* ----- Action Function Definitions ----- */

enum function_id {
    SMART_ALT,
    SMART_ALT_KEYS,
    SMART_ALT_TRANS
};

#define AC_SALT ACTION_FUNCTION(SMART_ALT)       // AC_SALT (Smart ALT) key does action SMART_ALT
#define AC_SAKY ACTION_FUNCTION(SMART_ALT_KEYS)  // AC_SAKY (Smart Alt KeYs) does action SMART_ALT_KEYS
#define AC_SATR ACTION_FUNCTION(SMART_ALT_TRANS) // AC_SATR (Smart Alt TRansparent) does action SMART_ALT_TRANS

/* ----- Keymaps ----- */

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
    ESC,      F1 ,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,          PSCR,NLCK,M0  ,         VOLD,VOLU,MUTE,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, JYEN,BSPC,     INS, HOME,PGUP,    BSPC,PSLS,PAST,PMNS,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,     BSLS,     DEL, END, PGDN,    P7,  P8,  P9,  PPLS,
    TL0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     NUHS,ENT,                         P4,  P5,  P6,  PCMM,
    LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RO,  RSFT,          UP,           P1,  P2,  P3,  PENT,
    LCTL,LGUI,SALT,MHEN,          SPC,           HENK,KANA,RALT,RGUI,APP, LGUI,     LEFT,DOWN,RGHT,         P0,  PDOT, PEQL
    ),
    /**
     * Layer 1 - Caps Lock layer
     */
    UNIMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,CALC,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,VOLD,MUTE,VOLU,TRNS,TRNS,TRNS,UP  ,TRNS,HOME,TRNS,TRNS ,    TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,MPRV,MPLY,MNXT,TRNS,TRNS,LEFT,DOWN,RGHT,END ,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
    ),
    /**
     * Layer 2 - Smart alt layer
     * SATR is transparent
     * SAKY does what it is defined to do in layer 3
     */
    UNIMAP(
              SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,
    SATR,     SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,          SATR,SATR,SATR,         SATR,SATR,SATR,
    SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,     SATR,SATR,SATR,    SATR,SATR,SATR,SATR,
    SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR ,    SATR,     SATR,SATR,SATR,    SATR,SATR,SATR,SATR,
    SAKY,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,     SATR,SATR,                        SATR,SATR,SATR,SATR,
    SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,SATR,     SATR,SATR,          SATR,         SATR,SATR,SATR,SATR,
    SATR,SATR,SATR,SATR,          SATR,          SATR,SATR,SATR,SATR,SATR,SATR,     SATR,SATR,SATR,         SATR,SATR,SATR
    ),
    /**
     * Layer 3 - Smart alt definition layer
     * What smart alt actually does
     */
    UNIMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS ,    TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
    ),
    /**
     * Don't delete, I'm here to be copied!
     */
    UNIMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS ,    TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,                        TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,          TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,          TRNS,          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS
    )
};

// const action_t PROGMEM fn_actions[] = {
//     [3] = ACTION_FUNCTION(SMART_CTRL)
// };

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
            case 0:
                // Presses ctrl 
                return MACRO( D(LCTL), D(LSFT), T(ESC), U(LSFT), U(LCTL), END );
        }     
    }
    return MACRO_NONE;
};

/**
 * Smart alt implemented from https://github.com/tmk/tmk_core/blob/master/doc/keymap.md#243-implement-user-function. This will produce build warnings because some of the functions are not defined?
 * All I know is that the ones defined in action.h usually work, and they are documented here: https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros#advanced-macro-functions
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
    case SMART_ALT:
        if (record->event.pressed) { // I think this means that it's currently being pressed
            //add_weak_mods(MOD_BIT(KC_LALT)); // Registers alt mod
            register_mods(KC_LALT);
            layer_invert(SMART_ALT_LAYER); // Switch to smart alt layer
        } else {
            send_keyboard_report();// send previous event: D(KC_LALT)
            layer_invert(SMART_ALT_LAYER);
            del_weak_mods(MOD_BIT(KC_LALT));
            send_keyboard_report();
        }
        break;
    case SMART_ALT_KEYS: // Smart alt and a valid combo key was pressed, so we want to send whatever the combo key maps to
        if (record->event.pressed) {
            del_weak_mods(MOD_BIT(KC_LALT)); // Remove alt key
            uint8_t keycode = keymap_get_keycode(SMART_ALT_DEF_LAYER, record->event.key); // get the corresponding key on alt def layer, i.e. the one we want the combo to act as
            add_key(keycode); // Add it
            send_keyboard_report(); // Send them keys
        } else {
            uint8_t keycode = keymap_key_to_keycode(SMART_ALT_DEF_LAYER, record->event.key);
            del_key(keycode);
            send_keyboard_report();
        }
        break;
    case SMART_ALT_TRANS: // Smart alt and a smart alt transparent key was presssed, so we want to just send alt and whatever transparent key maps to
        if (record->event.pressed) {
            add_weak_mods(MOD_BIT(KC_LALT)); // Add alt key
            uint8_t keycode = keymap_key_to_keycode(DEFAULT_LAYER, record->event.key); // get the corresponding key on default layer
            add_key(keycode); // add that key
            send_keyboard_report(); // send them
        } else {
            uint8_t keycode = keymap_key_to_keycode(DEFAULT_LAYER, record->event.key);
            del_key(keycode);
            send_keyboard_report();
        }
        break;
    }
}

