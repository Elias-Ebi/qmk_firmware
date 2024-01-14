/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_german.h"
#include "sendstring_german.h"


// define combo names
enum combos {
    COMBO_LCTL,
    COMBO_LGUI,
    COMBO_LALT,
    COMBO_LCTLGUI,
    // more here...
    COMBO_RCTL,
    COMBO_RGUI,
    COMBO_RALT,
    COMBO_RCTLGUI,

    COMBO_LCTL1,
    COMBO_LGUI1,
    COMBO_LALT1,
    COMBO_LCTLGUI1,

    COMBO_RCTL1,
    COMBO_RGUI1,
    COMBO_RALT1,
    COMBO_RCTLGUI1,

    COMBO_LCTL2,
    COMBO_LGUI2,
    COMBO_LALT2,
    COMBO_LCTLGUI2,

    COMBO_RCTL2,
    COMBO_RGUI2,
    COMBO_RALT2,
    COMBO_RCTLGUI2,

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM fa_combo[] = {KC_F, KC_A, COMBO_END};
const uint16_t PROGMEM fds_combo[] = {KC_F, KC_D, KC_S, COMBO_END};
// more here...
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM joe_combo[] = {KC_J, KC_SCLN, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};

//layer 2
const uint16_t PROGMEM du_combo[] = {KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM dl_combo[] = {KC_DOWN, KC_LEFT, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_DOWN, KC_F12, COMBO_END};
const uint16_t PROGMEM dul_combo[] = {KC_DOWN, KC_UP, KC_LEFT, COMBO_END};

const uint16_t PROGMEM fofi_combo[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM fosi_combo[] = {KC_4, KC_6, COMBO_END};
const uint16_t PROGMEM fopa_combo[] = {KC_4, KC_PAST, COMBO_END};
const uint16_t PROGMEM fofisi_combo[] = {KC_4, KC_5, KC_6, COMBO_END};

//layer 1
const uint16_t PROGMEM ll_combo[] = {DE_LPRN, DE_LCBR, COMBO_END};
const uint16_t PROGMEM ls_combo[] = {DE_LPRN, DE_SLSH, COMBO_END};
const uint16_t PROGMEM lla_combo[] = {DE_LPRN, DE_LABK, COMBO_END};
const uint16_t PROGMEM lls_combo[] = {DE_LPRN, DE_LCBR, DE_SLSH, COMBO_END};

const uint16_t PROGMEM rr_combo[] = {DE_RPRN, DE_RCBR, COMBO_END};
const uint16_t PROGMEM rb_combo[] = {DE_RPRN, DE_BSLS, COMBO_END};
const uint16_t PROGMEM rra_combo[] = {DE_RPRN, DE_RABK, COMBO_END};
const uint16_t PROGMEM rrb_combo[] = {DE_RPRN, DE_RCBR, DE_BSLS, COMBO_END};


// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_LCTL] = COMBO(fd_combo, KC_LCTL),
    [COMBO_LGUI] = COMBO(fs_combo, KC_LGUI),
    [COMBO_LALT] = COMBO(fa_combo, KC_LALT),
    [COMBO_LCTLGUI] = COMBO(fds_combo, LCTL(KC_LGUI)),
    // more here...
    [COMBO_RCTL] = COMBO(jk_combo, KC_LCTL),
    [COMBO_RGUI] = COMBO(jl_combo, KC_LGUI),
    [COMBO_RALT] = COMBO(joe_combo, KC_LALT),
    [COMBO_RCTLGUI] = COMBO(jkl_combo, LCTL(KC_LGUI)),

    //layer 2
    [COMBO_LCTL2] = COMBO(du_combo, KC_LCTL),
    [COMBO_LGUI2] = COMBO(dl_combo, KC_LGUI),
    [COMBO_LALT2] = COMBO(df_combo, KC_LALT),
    [COMBO_LCTLGUI2] = COMBO(dul_combo, LCTL(KC_LGUI)),

    [COMBO_RCTL2] = COMBO(fofi_combo, KC_LCTL),
    [COMBO_RGUI2] = COMBO(fosi_combo, KC_LGUI),
    [COMBO_RALT2] = COMBO(fopa_combo, KC_LALT),
    [COMBO_RCTLGUI2] = COMBO(fofisi_combo, LCTL(KC_LGUI)),

    //layer 1
    [COMBO_LCTL1] = COMBO(ll_combo, KC_LCTL),
    [COMBO_LGUI1] = COMBO(ls_combo, KC_LGUI),
    [COMBO_LALT1] = COMBO(lla_combo, KC_LALT),
    [COMBO_LCTLGUI1] = COMBO(lls_combo, LCTL(KC_LGUI)),

    [COMBO_RCTL1] = COMBO(rr_combo, KC_LCTL),
    [COMBO_RGUI1] = COMBO(rb_combo, KC_LGUI),
    [COMBO_RALT1] = COMBO(rra_combo, KC_LALT),
    [COMBO_RCTLGUI1] = COMBO(rrb_combo, LCTL(KC_LGUI))

};

enum custom_keycodes {
    KUBECTL=SAFE_RANGE,
    AUTOFORM,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case AUTOFORM:
            if(record-> event.pressed) {
                SEND_STRING(SS_LCTL(SS_LALT("l")));
            } else {
                //nothing on release
            }
            break;
        case KUBECTL:
            if (record->event.pressed) { 
                SEND_STRING("kubectl ");
            }
            break;
    }
    return true; 
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  XXXXXXX,  KC_Q,   KC_W,    KC_E,   KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  XXXXXXX,    KC_A,     KC_S,      KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   DE_EURO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  DE_SS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_TAB,  LSFT_T(KC_DEL) ,  LT(MO(1),KC_SPC),     LT(MO(2),KC_ENT), RSFT_T(KC_BSPC), KC_ESC
                                      //`--------------------------'  `--------------------------'

  ),
//coding block (wip) --> weg mit dem osm 
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       DE_CIRC, DE_QUOT, DE_DQUO, DE_SECT,  DE_DLR, DE_AMPR,                       DE_DEG, DE_PERC, DE_ACUT, DE_GRV, KC_EXLM, DE_QUES,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, DE_LABK, DE_SLSH, DE_LCBR, DE_LPRN, DE_LBRC,                      DE_RBRC, DE_RPRN, DE_RCBR, DE_BSLS, DE_RABK, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       AS_TOGG, DE_MICR,  DE_AT, DE_HASH,  DE_PIPE, KUBECTL,                      AUTOFORM, DE_TILD, XXXXXXX, XXXXXXX, KC_CALC, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______,  KC_SPC,     LT(MO(3),KC_ENT),   _______, _______
                                      //`--------------------------'  `--------------------------'

  ),

//numpad block 
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_PMNS,  KC_7,    KC_8,   KC_9,    KC_PSLS, DE_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  KC_LEFT,  KC_UP, KC_DOWN, KC_RIGHT,                      KC_PPLS,  KC_4,   KC_5,   KC_6,    KC_PAST, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F7, KC_F8, KC_F9,  KC_F10,   KC_F11, KC_F12,                             KC_0,    KC_1,   KC_2,    KC_3,    KC_COMM, KC_DOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                _______, _______,  LT(MO(3),KC_SPC),     KC_ENT, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

   //mouse layer
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                     KC_WH_D, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              _______,   _______,  KC_SPC,                       KC_ENT, _______, _______
                                    	//`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}*/
#endif // OLED_ENABLE
