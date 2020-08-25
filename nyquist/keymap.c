//  make keebio/nyquist/rev1:nyquist-grid-JERRIK:avrdude
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _GAMING 1
#define _LOWER 3
#define _RAISE 4
#define _FN3 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  LOWER,
  RAISE,
  FN3,
  ADJUST,
};

#define _______ KC_TRNS

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen
#define KC_STL LGUI(LSFT(KC_LBRC))      // Switch tab left
#define KC_STR LGUI(LSFT(KC_RBRC))      // Switch tab right
#define KC_SSL LCTL(KC_LEFT)            // Switch screen left
#define KC_SSR LCTL(KC_RIGHT)           // Switch screen right
#define KC_SU LCTL(KC_UP)		            // Show all screens
#define KC_SD LCTL(KC_DOWN)		          // Collapse screens
#define KC_PB LGUI(KC_LBRC)             // Page back
#define KC_PF LGUI(KC_RBRC)             // Page forward
#define KC_SF LGUI(KC_GRV)              // Switch browser focus
#define KC_X0 MT(MOD_LCTL, KC_ESC)      // Toggle CTRL/Esc
#define KC_SPLT LGUI(KC_SPC)            // Alt spotlight/alfred
#define KC_DEVT LGUI(LALT(KC_J))        // Toggle Dev Tools
#define KC_X3 LT(ADJUST, KC_GRV)
#define KC_X4 MT(MOD_LSFT, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_X0,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_X4 , \
  KC_X3,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_BSPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_GAMING] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, \
  KC_X0,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_X4 , \
  KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_BSPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_1   , KC_2 ,   KC_3   , KC_4  ,  KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL, \
  KC_SPLT,  KC_CAPP,KC_LEFT, KC_SSL , KC_SSR,  KC_LBRC, KC_RBRC,   KC_P4, KC_5   , KC_6   , KC_PLUS, KC_PIPE, \
  _______,  KC_PB ,  KC_PF ,  KC_SU , KC_SD , KC_LCBR, KC_RCBR,   KC_P1, KC_P2  , KC_P3  , KC_MINS, _______, \
  KC_DEVT, _______, _______, _______, _______, _______, KC_DEL,  _______, KC_P0  , KC_PDOT, KC_VOLU, KC_VOLD \
),

[_RAISE] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  KC_DEL,  KC_MPRV, KC_MNXT,  KC_VOLU, KC_PGUP, KC_HOME, KC_EQL,  KC_SF,   KC_UP,    KC_STL, KC_STR, KC_BSLS, \
  KC_MUTE, KC_MSTP, KC_MPLY,  KC_VOLD, KC_PGDN, KC_END, KC_PLUS, KC_LEFT ,KC_DOWN, KC_RIGHT, _______, _______, \
  KC_DEVT, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  GAMING , _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_gaming[][2]     = SONG(DVORAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_gaming);
        #endif
        persistent_default_layer_set(1UL<<_GAMING);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
