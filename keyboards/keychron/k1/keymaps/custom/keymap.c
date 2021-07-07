  
/*
Copyright 2020 Dimitris Mantzouranis
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


/* TODO:
 * Caps lock LED
 * Cycle button + F-keys change layer
 * F-keys LED is layer
 * RALT, RGUI -> Eisu, kana
 * Column 16 lights
 * Ctrl RGB location
 */


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE = 0,
    _FL = 1,
    _COLEMAK = 2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*				+--------------------------------------------------------------------------+----------------+
				| ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|????|PAUS|
				+--------------------------------------------------------------------------+------|----|----|
 				|  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |SCRL|PGUP|
 				+--------------------------------------------------------------------------+------|----|----|
 				|  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | |DEL |END |PGDN|
 				+--------------------------------------------------------------------------+------|----|----|
 				| CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN  |                |
 				+--------------------------------------------------------------------------+      |----|    |
 				| LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |    |
 				+--------------------------------------------------------------------------+------|----|----|
 				|LCTRL| LGUI| LALT |            SPACE            | RALT| RGUI | FN | RCTRL | |LFT |DWN |RGT |
 				+--------------------------------------------------------------------------+----------------+
*/ 				
    /*  Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15         16    */
    [0] = {     {   KC_CAPS,    KC_F1,     KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_NO,     KC_PSCR,     TG(2),   RGB_MODE_FORWARD},
                {   KC_GRV,     KC_1,      KC_2,      KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,   KC_INS,    KC_HOME,   KC_PGUP},
                {   KC_TAB,     KC_Q,      KC_W,      KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_DEL,    KC_END,    KC_PGDN},
                {   KC_ESC,     KC_A,      KC_S,      KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_NO,     KC_NO},
                {   KC_LSFT,    KC_NO,     KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,   KC_NO,     KC_RSFT,   KC_NO,     KC_UP,     KC_NO},
                {   KC_LCTL,    KC_LGUI,   KC_LALT,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,   KC_NO,   KC_NO,   KC_NO,     KC_RALT,   KC_RGUI,   MO(1),     KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT}
            },

/*				+--------------------------------------------------------------------------+-------------------+
				|     |SLCK|PAUS|    |BRLR|BRIN|MPRV| PLY|MNXT|MUTE|VLDN|VLUP|    |   |PSCR|    |    | SLP| TOG|
				+--------------------------------------------------------------------------+----|----|----|----+				
 				|     |    |    |    |    |    |    |    |    |    |    |    |    |        |    |    |    | HUE|
 				+--------------------------------------------------------------------------+----|----|----|----+
 				|       |    |    |    |    |    |    |    |    |    |    |    |    |      |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----| SPD+
 				|         |    |    |    |    |    |    |    |    |    |    |    |         |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----|----+
 				|          |    |    |    |    |    |    |    |    |    |    |        |    |    |    |    |    |
 				+--------------------------------------------------------------------------+----|----|----| SAT+
 				|     | LALT|  LGUI|                             |     |   |     |    |    |    |    |    |    |
 				+--------------------------------------------------------------------------+-------------------+
*/ 				
    /*  Row:       0          1         2         3         4         5         6         7         8         9          10           11         12         13         14         15         16        */
    [1] =   {   {     RESET,  KC_SLCK,  KC_PAUS,   KC_APP,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC__MUTE,  KC__VOLDOWN, KC__VOLUP,    KC_NO,  KC_PSCR,  _______,  RGB_TOG },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,   _______,  _______,  _______,  RGB_M_P,  RGB_HUI },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,   _______,  _______,  _______,  RGB_SAI,  RGB_SPI },
                {   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,     KC_NO,  _______,    KC_NO,    KC_NO,    KC_NO },
                {   _______,    KC_NO,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,     _______,     KC_NO,  _______,    KC_NO,  KC_VOLU,    KC_NO },
                {   _______,  KC_LALT,  KC_LGUI,    KC_NO,    KC_NO,    KC_NO,  _______,    KC_NO,    KC_NO,    KC_NO,   _______,     _______,   _______,  _______,  RGB_MODE_REVERSE,  KC_VOLD,    RGB_MODE_FORWARD }
              },

/*  Row:          0        1        2        3        4        5        6        7        8        9        10       11       12       13       14       15       16    */
    [2] =   {   {  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
                {  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
                {  _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, _______, _______, _______, _______, _______ },
                {  _______,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, _______, _______, _______, _______, _______ },
                {  _______,   KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, _______, _______, _______, _______, _______, _______, _______ },
                {  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
            }
};


// void rgb_matrix_indicators_user(void) {
//     // rgb_matrix_set_color(0, 255, 255, 255);
// }

// // Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
// const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {68, 1, HSV_RED}
// );

// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_GREEN}
// );

// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {2, 1, HSV_GREEN}
// );

// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {3, 1, HSV_GREEN}
// );

// const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_capslock_layer,
//     my_layer1_layer,    // Overrides caps lock layer
//     my_layer2_layer,    // Overrides other layers
//     my_layer3_layer     // Overrides other layers
// );

// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(1, layer_state_cmp(state, _BASE));
//     return state;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(1, layer_state_cmp(state, 0));
//     rgblight_set_layer_state(2, layer_state_cmp(state, 2));
//     // rgblight_set_layer_state(3, layer_state_cmp(state, 3));
//     return state;
// }

void dip_switch_update_user(uint8_t index, bool active){
  switch(index){
    case 0:
      if(active){ //BT mode
// do stuff
      }
      else{ //Cable mode
// do stuff
      }
      break;
    case 1:
      if(active){ // Win/Android mode
// do stuff
      }
      else{ // Mac/iOS mode
      // TODO: Remap to PS4 mode here
// do stuff
      }
      break;
  }
}
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=false;
  debug_matrix=false;
  rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
  //debug_keyboard=true;
  //debug_mouse=true;

  // rgblight_layers = rgb_layers;
}

void rgb_matrix_indicators_user(void) {
    // rgb_matrix_se_color(1, 0, 255, 0);
    // rgb_matrix_set_color(2, 0, 255, 0);
    // rgb_matrix_set_color(3, 0, 255, 0);
    // rgb_matrix_set_color(4, 0, 255, 0);
}
