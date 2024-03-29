 /* Custom AnnePro2 QMK Layout with Indicator Leds 
  *
  * AnnePro2 Keyboard layout
  *
  * BASE Layer: Resembles the standard Obins one, without TAP or Magic Key modifiers.
  *             FN1 and FN2 keys select Layer 1 and 2 respectively when held down
  *             Esc outputs tilde ('~') when pressed alongside the Shift button
  *
  * FN1 Layer: Mimics Obins' own TAP layer, with arrow keys (WASD) and Volume UP/DOWN
  *            and mute controls. FN2 key is still mapped to Layer 2
  *
  * FN2 Layer: Lighting and RGB Control keys are set up here
  *
  * */

#include QMK_KEYBOARD_H

enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
};

// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | esc~|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*/
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_60_ansi( // base layout
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(FN1), MO(FN2), KC_RCTL
),

/*
* Layer FN1
* ,-----------------------------------------------------------------------------------------.
* |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
* |-----------------------------------------------------------------------------------------+
* | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*
*/
[FN1] = LAYOUT_60_ansi(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
    _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, KC_INS, KC_DEL, _______,
    _______, _______, _______, _______, _______, _______, MO(FN2), _______
),

/*
* Layer FN2
* ,-----------------------------------------------------------------------------------------.
* |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |  F8 |LEDTG|LEDI+|LEDPV|LEDNX|    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
* |-----------------------------------------------------------------------------------------+
* | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*
*/
[FN2] = LAYOUT_60_ansi(
    _______, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_AP2_BT_UNPAIR, _______, _______, _______, KC_AP_RGB_MOD, KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI, _______,
    MO(FN2), _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, KC_DEL, _______,
    _______, _______, _______, _______, _______, MO(FN1), _______, _______
)
};

// clang-format on
const ap2_led_t layer_indicators[] = {
    {.p.red = 0xff, .p.green = 0xff, .p.blue = 0xff, .p.alpha = 0xff}, // BASE
    {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff}, // FN1
    {.p.red = 0x00, .p.green = 0xff, .p.blue = 0x00, .p.alpha = 0xff}, // FN2
};

void reset_color_to_default(ap2_led_t color) {
    ap2_led_reset_foreground_color();
    ap2_led_set_foreground_color(color.p.red, color.p.green, color.p.blue);
}

// post init function
void keyboard_post_init_user(void) {
    // enable led lighting
    ap2_led_enable();
    ap2_led_set_profile(0);

    // default set all leds to white
    reset_color_to_default(layer_indicators[BASE]);
}

layer_state_t layer_state_set_user(layer_state_t state) {
      switch (get_highest_layer(state)) {
        case FN1:
            // Set the leds to green
            ap2_led_mask_set_key(4, 6, layer_indicators[FN1]);
            break;
        case FN2:
            // Set the leds to blue
            ap2_led_mask_set_key(4, 6, layer_indicators[FN2]);
            break;
        default:
            reset_color_to_default(layer_indicators[BASE]);
            break;
    }
    return state;
}

// The function to handle the caps lock logic
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        // Set the caps-lock to red
        const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};

        ap2_led_mask_set_key(2, 0, color);
    } else {
        // Reset the capslock if there is no layer active
        if (!layer_state_is(FN1) && !layer_state_is(FN2)) {
            const ap2_led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
            ap2_led_mask_set_key(2, 0, color);
        }
    }

    return true;
}
