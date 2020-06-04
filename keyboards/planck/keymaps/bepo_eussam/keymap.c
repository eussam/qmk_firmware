#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"

// #include "keymap_german.h"
// #include "keymap_nordic.h"
// #include "keymap_french.h"
// #include "keymap_spanish.h"
// #include "keymap_hungarian.h"
// #include "keymap_swedish.h"

#include "keymap_french_osx.h"

#define KC_MAC_UNDO LGUI(KC_U)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_U)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

// VSC Shortcuts
// https://code.visualstudio.com/shortcuts/keyboard-shortcuts-macos.pdf
#define VSC_LBC G(FR_SLSH) // line block comment
#define VSC_BC S(A(FR_A))  // block comment
#define VSC_DL G(S(KC_K))  // delete line
#define VSC_FORMAT S(A(KC_F))  // format document

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
  EPRM,
};

enum planck_layers {
  BASE,
  NAV,
  SYMBOL,
  NUMPAD,
  MOUSE
};


//PF: define pour visibilité
#define ___ KC_TRANSPARENT
#define XXX KC_NO

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


  /* EMPTY (à copier au besoin) 
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |      |      |      |    	 |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | GUI  |      |      |      |      |    Space    |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  [NUMPAD] = LAYOUT_planck_grid(
      ___, ___, ___, ___, ___, ___, ___, ___, ___,  ___, ___,  ___,
      ___, ___, ___, ___, ___, ___, ___, ___, ___,  ___, ___,  ___,
      ___, ___, ___, ___, ___, ___, ___, ___, ___,  ___, ___,  ___,
      ___, ___, ___, ___, ___, ___, ___, ___, ___,  ___, ___,  ___
  )
  */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE (bépo)
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |   B  |   é  |   P  |   O  |   è  |   ^  |   V  |   D  |   L  |   J  |  Z   |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  |   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |  M   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|   à  |   Y  |   X  |   .  |   K  |   '  |   Q  |   G  |   H  |   F  |  W   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | GUI  |  Alt | Ctrl |   ç  | Del  |    Space    | Enter|   ↑  |   ↓  |  ←   |  →   |
  * `-----------------------------------------------------------------------------------'
  */
  [BASE] = LAYOUT_planck_grid(
      KC_ESC,             KC_B,    LT(MOUSE,FR_EACU),    KC_P,               KC_O,            FR_EGRV,    FR_CIRC,    KC_V,    KC_D,               KC_L,    KC_J,    FR_Z,
      LT(NUMPAD,KC_TAB),  FR_A,    KC_U,                 KC_I,               KC_E,            FR_COMM,    KC_C,       KC_T,    KC_S,               KC_R,    KC_N,    FR_M,
      KC_LSFT,            FR_AGRV, KC_Y,                 KC_X,               FR_DOT,          KC_K,       FR_APOS,    FR_Q,    KC_G,               KC_H,    KC_F,    FR_W ,
      KC_LGUI,            KC_LCTL, KC_LALT,              LT(SYMBOL,FR_CCED), LT(NAV,KC_BSPC), KC_SPC,     KC_SPC,     KC_ENT,  LT(SYMBOL,KC_UP),   KC_DOWN, KC_LEFT, KC_RIGHT
  ),

  /* NAV 
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |      |      |      |      |      |      | Suppr|   ↑  |  Del |      | UNDO |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  |      |      |      |      |      |      |   ←  |   ↓  |   →  |      | PASTE|
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|      |      |      |      |      |      | C(A) | PG.U | C(E) |      | COPY |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | GUI  |  Alt | Ctrl |      |      |    Space    |      | PG.D |      |      | CUT  |
  * `-----------------------------------------------------------------------------------'
  */
  [NAV] = LAYOUT_planck_grid(
      ___, ___, ___, ___, ___, ___, ___, KC_BSPC, KC_UP,     KC_DEL,   XXX,    KC_MAC_UNDO,
      ___, ___, ___, ___, ___, ___, ___, KC_LEFT, KC_DOWN,   KC_RIGHT, XXX,    KC_MAC_PASTE,
      ___, ___, ___, ___, ___, ___, ___, C(FR_A), KC_PGUP,   C(KC_E),  XXX,    KC_MAC_COPY ,
      ___, ___, ___, ___, ___, ___, ___,  ___,    KC_PGDOWN, ___,      XXX,    KC_MAC_CUT
  ),

  /* SYMBOL 
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |  !   |   @  |  {   |   }	 |  %   |   ^  |   +  |   -  |   `  |  ;   |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  |  #   |   _  |  (   |   )  |  &   |   |  |   =  |   '  |   :  |  "   |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|  \   |   /  |  [   |   ]  |  ~   |   $  |   *  |   <  |   >  |  ?   |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | GUI  |      |      |  €   |   £  |    Space    |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [SYMBOL] = LAYOUT_planck_grid(
      ___, FR_EXLM, FR_AT,   FR_LCBR, FR_RCBR, FR_PERC, FR_CIRC, FR_PLUS, FR_MINS,  FR_GRV,  FR_SCLN,  ___,
      ___, FR_HASH, FR_UNDS, FR_LPRN, FR_RPRN, FR_AMP,  FR_PIPE, FR_EQL,  FR_APOS,  FR_COLN, FR_QUOT,  ___,
      ___, FR_BSLS, FR_SLSH, FR_LBRC, FR_RBRC, FR_TILD, FR_DLR,  FR_ASTR, FR_LESS,  FR_GRTR, FR_QUES,  ___,
      ___, ___,     ___,     ___,     ___,     ___,     ___,     ___,     ___,      ___,     ___,      ___
  ),

  /* NUMPAD 
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |      |      |      |    	 |      |      |   7  |   8  |  9   |  *   |  %   |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  |      |      |      |      |      |      |   4  |   5  |  6   |  -   |  .   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|      |      |      |      |      |      |   1  |   2  |  3   |  +   |  :   |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | GUI  |      |      |      |      |    Space    |   0  |   0  |  .   |  /   |  ,   |
  * `-----------------------------------------------------------------------------------'
  */
  [NUMPAD] = LAYOUT_planck_grid(
      ___, ___, ___, ___, ___, ___, ___, KC_KP_7, KC_KP_8,  KC_KP_9, KC_KP_ASTERISK, FR_PERC,
      ___, ___, ___, ___, ___, ___, ___, KC_KP_4, KC_KP_5,  KC_KP_6, KC_KP_MINUS,    FR_DOT,
      ___, ___, ___, ___, ___, ___, ___, KC_KP_1, KC_KP_2,  KC_KP_3, KC_KP_PLUS,     KC_COLN,
      ___, ___, ___, ___, ___, ___, ___, FR_0,    FR_0,     FR_DOT,  KC_KP_SLASH,    FR_COMM
  ),

  /* MOUSE 
  * ,-----------------------------------------------------------------------------------.
  * | Esc  |      |      |      |  M2  |      |      |  mWU |  mU  |  mWD |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Tab  |      |      |      |      |  M1  |      |   mL |  mD  |  mR  |      |      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | GUI  |      |      |      |      |    Space    |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [MOUSE] = LAYOUT_planck_grid(
      ___, ___, ___, KC_MS_BTN2, ___,        ___, ___, KC_WH_U, KC_MS_U,  KC_WH_D, ___,  ___,
      ___, ___, ___, ___,        KC_MS_BTN1, ___, ___, KC_MS_L, KC_MS_D,  KC_MS_R, ___,  ___,
      ___, ___, ___, ___,        ___,        ___, ___, ___,     ___,      ___,     ___,  ___,
      ___, ___, ___, ___,        ___,        ___, ___, ___,     ___,      ___,     ___,  ___
  )

};



/////////////////////////////////
// Gestion des couleurs
// Note: dernière rangé, seulement 11 keys, la touche espace n'est pas colorisée
/////////////////////////////////

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


// {0,255,255} => rouge plein

// pas de couleur
#define C_NO {0,0,0}
// touche principale home row pour repère
#define C_HOME_KEY {0,205,155}
// #define C_HOME_KEY {0,255,255}
// couleur utilisée dans le layer NAV
#define C_NAV {31,255,255}
// couleur utilisée dans le layer SYMBOL
#define C_SYM {141,255,233}
// couleur utilisée dans le layer NUMPAD
#define C_NUM {250,159,255}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {

    [BASE] = {
      C_NO, C_NO, C_NO, C_HOME_KEY, C_NO,  C_NO,   C_NO, C_NO, C_HOME_KEY, C_NO, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_NO,       C_NO,  C_NO,   C_NO, C_NO, C_NO,       C_NO, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_NO,       C_NO,  C_NO,   C_NO, C_NO, C_NO,       C_NO, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_NO,       C_NO,  /*xxx*/ C_NO, C_NO, C_NO,       C_NO, C_NO, C_NO
    },

    [NAV] = {
      C_NO, C_NO, C_NO, C_NO, C_NO,  C_NO,   C_NO, C_NO, C_NAV,  C_NO, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_NO, C_NO,  C_NO,   C_NO, C_NAV, C_NAV, C_NAV, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_NO, C_NO,  C_NO,   C_NO, C_NO, C_NO,   C_NO, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_NO, C_NO,  /*xxx*/ C_NO, C_NO, C_NO,   C_NO, C_NO, C_NO
    },

    [SYMBOL] = {
      C_NO, C_NO, C_NO, C_SYM, C_SYM,  C_NO,  C_NO, C_NO, C_NO, C_NO, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_SYM, C_SYM,  C_NO,  C_NO, C_NO, C_NO, C_NO, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_SYM, C_SYM,  C_NO,  C_NO, C_NO, C_NO, C_NO, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_NO,  C_NO,  /*xxx*/ C_NO, C_NO, C_NO, C_NO, C_NO, C_NO
    },

    [NUMPAD] = {
      C_NO, C_NO, C_NO, C_NO, C_NO,  C_NO,   C_NO, C_NUM, C_NUM, C_NUM, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_NO, C_NO,  C_NO,   C_NO, C_NUM, C_NUM, C_NUM, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_NO, C_NO,  C_NO,   C_NO, C_NUM, C_NUM, C_NUM, C_NO, C_NO, 
      C_NO, C_NO, C_NO, C_NO, C_NO,  /*xxx*/ C_NO, C_NO,  C_NO,  C_NO,  C_NO, C_NO
    }

};


void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case BASE:
      set_layer_color(BASE);
      break;
    case NAV:
      set_layer_color(NAV);
      break;
    case SYMBOL:
      set_layer_color(SYMBOL);
      break;
    case NUMPAD:
      set_layer_color(NUMPAD);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

// END
/////////////



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

// void encoder_update(bool clockwise) {
//     if (muse_mode) {
//         if (IS_LAYER_ON(_RAISE)) {
//             if (clockwise) {
//                 muse_offset++;
//             } else {
//                 muse_offset--;
//             }
//         } else {
//             if (clockwise) {
//                 muse_tempo+=1;
//             } else {
//                 muse_tempo-=1;
//             }
//         }
//     } else {
//         if (clockwise) {
//         #ifdef MOUSEKEY_ENABLE
//             register_code(KC_MS_WH_DOWN);
//             unregister_code(KC_MS_WH_DOWN);
//         #else
//             register_code(KC_PGDN);
//             unregister_code(KC_PGDN);
//         #endif
//         } else {
//         #ifdef MOUSEKEY_ENABLE
//             register_code(KC_MS_WH_UP);
//             unregister_code(KC_MS_WH_UP);
//         #else
//             register_code(KC_PGUP);
//             unregister_code(KC_PGUP);
//         #endif
//         }
//     }
// }

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

// bool music_mask_user(uint16_t keycode) {
//     switch (keycode) {
//     case RAISE:
//     case LOWER:
//         return false;
//     default:
//         return true;
//     }
// }
#endif

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }
