#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FUNCTION 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define FUNCTION MO(_FUNCTION)

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

#define KC_STL LGUI(LSFT(KC_LBRC))      // Switch tab left
#define KC_STR LGUI(LSFT(KC_RBRC))      // Switch tab right

#define KC_SSL LCTL(KC_LEFT)            // Switch screen left
#define KC_SSR LCTL(KC_RIGHT)           // Switch screen right

#define KC_SU LCTL(KC_UP)		            // Show all screens
#define KC_SD LCTL(KC_DOWN)		          // Collapse screen
#define KC_SHDT LGUI(KC_F3)             // Show Desktop

#define KC_PB LGUI(KC_LBRC)             // Page back
#define KC_PF LGUI(KC_RBRC)             // Page forward

#define KC_SF LGUI(KC_GRV)              // Switch browser focus

#define KC_X0 MT(MOD_LCTL, KC_ESC)      // Toggle CTRL/Esc
#define KC_X4 MT(MOD_LSFT, KC_ENT)      // Toggle Shift/Enter

#define KC_SPLT LGUI(KC_SPC)            // Alt spotlight/alfred
#define KC_DEVT LGUI(LALT(KC_J))        // Toggle Dev Tools

#define KC_DW LALT(KC_BSPC)             // Delete word
#define KC_UNSC LSFT(KC_MINS)           // Underscore


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R,  KC_T  , KC_Y   , KC_U , KC_I   , KC_O   , KC_P   , KC_MINS, \
    KC_X0   , KC_A   , KC_S   , KC_D   , KC_F,  KC_G  , KC_H   , KC_J , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
    KC_LSPO , KC_Z   , KC_X   , KC_C   , KC_V,  KC_B  , KC_N   , KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_X4  , \
    FUNCTION, KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_BSPC, RAISE, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT  \
  ),

  [_LOWER] = LAYOUT_ortho_4x12( \
    KC_TILD, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8,  KC_9  , KC_0   , KC_EQL   , \
    KC_SPLT, KC_CAPP, KC_SHDT, KC_SSL , KC_SSR , KC_LBRC, KC_RBRC, KC_4   , KC_5,  KC_6  , KC_PLUS, KC_BSLS  , \
    _______, KC_PB  , KC_PF  , KC_SU  , KC_SD  , KC_LCBR, KC_RCBR, KC_1   , KC_2,  KC_3  , KC_MINS, KC_RETURN, \
    KC_DEVT, _______, _______, _______, _______, _______, KC_DW  , _______, KC_0,  KC_DOT, _______, KC_PENT    \
  ),

  [_RAISE] = LAYOUT_ortho_4x12( \
    KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS, \
    _______, KC_GRV , _______, KC_HOME, KC_PGUP, KC_MINS, KC_EQL , KC_SF  , _______, KC_STL , KC_STR , KC_PIPE, \
    _______, _______, _______, KC_END , KC_PGDN, KC_UNSC, KC_PLUS, _______, _______, KC_PB  , KC_PF  , KC_PENT, \
    KC_DEVT, _______, _______, _______, _______, KC_TAB , _______, _______, _______, _______, _______, _______  \
  ),

  [_FUNCTION] = LAYOUT_ortho_4x12( \
    KC_F11 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F12 , \
    KC_CAPS, _______, _______, KC_DEVT, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, KC_INS , KC_DEL , _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
  ),

  [_ADJUST] =  LAYOUT_ortho_4x12( \
    _______, QWERTY , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  )

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
