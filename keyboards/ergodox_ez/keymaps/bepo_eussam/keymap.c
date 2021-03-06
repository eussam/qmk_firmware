#include QMK_KEYBOARD_H
#include "version.h"
// point de démarrage de ce fichier keymap est un export bépo depuis le configurateur graphique d'Ergodox-EZ

// #include "keymap_german.h"
// #include "keymap_nordic.h"
//PF: remplacement de keymap_french.h par keymap_french_osx.h
#include "keymap_french_osx.h"
// #include "keymap_spanish.h"
// #include "keymap_hungarian.h"

#define KC_MAC_UNDO LGUI(FR_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
// PF: sélectionner tout
#define KC_MAC_SELALL LGUI(FR_A)
#define KC_MAC_SAVE LGUI(KC_S)

// VSC Shortcuts
// https://code.visualstudio.com/shortcuts/keyboard-shortcuts-macos.pdf
#define VSC_LBC G(FR_SLSH) // line block comment
#define VSC_BC S(A(FR_A))  // block comment
#define VSC_DL G(S(KC_K))  // delete line
#define VSC_FORMAT S(A(KC_F))  // format document


// #define KC_PC_UNDO LCTL(KC_Z)
// #define KC_PC_CUT LCTL(KC_X)
// #define KC_PC_COPY LCTL(KC_C)
// #define KC_PC_PASTE LCTL(KC_V)

//PF: define pour visibilité
#define ___ KC_TRANSPARENT

#define BASE  0 // default layer
#define NAV   1
#define SYMBOL  2
#define NUMPAD  3
#define WINDOW  4
#define MOUSE  5


enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  EPRM,
  // PF: macros
  M_SIGNATURE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(
    // Left hand:  LT(3,KC_NO)   SFT_T(KC_U)

    /*=================================================================================-=======================*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/LT(NAV,KC_ESC),   FR_1,   /**/   FR_2,   /**/   FR_3,   /**/   FR_4,   /**/   FR_5,   /**/KC_MAC_UNDO,/**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*=========================================================================================================*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/  KC_B, LT(MOUSE,FR_EACU),/**/   KC_P,   /**/   KC_O,   /**/ FR_EGRV,  /**/KC_MAC_PASTE,/**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*==========================================================================================*/           /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/   FR_W,   /**/   FR_A,   /**/   KC_U,   /**/   KC_I,   /**/   KC_E,   /**/ FR_COMM,  /*===============*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*==========================================================================================*/           /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/MO(NUMPAD),/**/  FR_AGRV, /**/   KC_Y,   /**/   KC_X,   /**/  FR_DOT,  /**/ KC_K,     /**/KC_MAC_COPY,/**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*=========================================================================================================*/
      /**/         /**/           /**/           /**/           /**/           /**/
      /**/ KC_LGUI,/**/  KC_LALT, /**/  KC_LCTL, /**/  KC_LEFT, /**/ KC_RIGHT, /**/
      /**/         /**/           /**/           /**/           /**/           /**/
      /*========================================================================*/
                                                                                           /*========================================*/
                                                                                           /**/                /**/                /**/
                                                                                           /**/   KC_VOLD,    /**/    KC_VOLU,     /**/
                                                                                           /**/                /**/                /**/
                                                                       /*============================================================*/
                                                                       /**/                /**/                /**//*save main gauche*/
                                                                       /**/                /**/                /**/  KC_MAC_SAVE,  /**/
                                                                       /**/                /**/                /**/                /**/
                                                                       /**/                /**/                /*====================*/
                                                                       /**/                /**/                /**/                /**/
                                                                       /**/LT(NAV,KC_SPC), /**/LT(SYMBOL,KC_TAB),     KC_LSHIFT,   /**/
                                                                       /**/                /**/                /**/                /**/
                                                                       /*============================================================*/

    // Right hand

                /*=========================================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ KC_CAPS,  /**/   FR_6,   /**/   FR_7,   /**/   FR_8,   /**/   FR_9,   /**/   FR_0,   /**/ WEBUSB_PAIR,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*=========================================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/  _______, /**/ FR_CIRC,  /**/   KC_V,   /**/   KC_D,   /**/   KC_L,   /**/   KC_J,   /**/   FR_Z,   /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/           /*==========================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*===============*/ KC_C,     /**/   KC_T,   /**/   KC_S,   /**/   KC_R,   /**/   KC_N,   /**/   FR_M,   /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/           /*==========================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/  _______, /**/ FR_APOS,  /**/   FR_Q,   /**/   KC_G,   /**/   KC_H,   /**/   KC_F,   /**/ FR_CCED,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*=========================================================================================================*/
                                              /**/           /**/           /**/           /**/           /**/        /**/
                                              /**/   KC_UP,  /**/  KC_DOWN, /**/  KC_RCTL, /**/  KC_RALT, /**/KC_RGUI,/**/
                                              /**/           /**/           /**/           /**/           /**/        /**/
                                              /*========================================================================*/
    /*========================================*/
    /**/                /**/                /**/
    /**/    KC_MPLY,    /**/    KC_MNXT,    /**/
    /**/                /**/                /**/
    /*===========================================================*/
    /**/                /**/                /**/               /**/
    /**/    KC_MPRV,    /**/                /**/               /**/
    /**/                /**/                /**/               /**/
    /*====================*/                /**/               /**/
    /**/                /**/                /**/               /**/
    /**/   KC_RSHIFT,   /**/LT(SYMBOL,KC_BSPC), LT(NAV,KC_ENT)
    /**/                /**/                /**/               /**/
    /*===========================================================*/
  ),

  [NAV] = LAYOUT_ergodox(
    // Left hand

    /*=========================================================================================================*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/  G(KC_C), /**/  G(KC_V), /**/  KC_ENT,  /**/ KC_BSPC,  /**/  _______, /**/ G(KC_S),  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*=========================================================================================================*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/  G(KC_X), /**/  G(FR_Z), /**/  G(FR_A), /**/ _______,  /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*==========================================================================================*/           /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /*===============*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*==========================================================================================*/           /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*=========================================================================================================*/
        /**/       /**/           /**/           /**/           /**/           /**/
        /**/  ___, /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
        /**/       /**/           /**/           /**/           /**/           /**/
        /*=======================================================================*/
                                                                                           /*==============================*/
                                                                                           /**/           /**/           /**/
                                                                                           /**/ _______,  /**/ _______,  /**/
                                                                                           /**/           /**/           /**/
                                                                            /*=============================================*/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/           /**/           /**/ _______,  /**/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/           /**/           /*===============*/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/ _______,  /**/ _______,  /**/ _______,  /**/
                                                                            /**/           /**/           /**/           /**/
                                                                            /*=============================================*/



//  Right hand (RGUI(FR_AMP) => shortcut bar)
//  GUI(KC_J) => VSC window debug
//  => VSC delete line TOTO

                /*=========================================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/ _______,  /**/ _______,  /**/  VSC_DL,  /**/VSC_FORMAT,/**/ _______,  /**/KC_MAC_UNDO,/**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*=========================================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/RGUI(KC_J),/**/ KC_BSPACE,/**/  KC_UP,   /**/ KC_DELETE,/**/ XXXXXXX,  /**/KC_MAC_PASTE,/**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/           /*==========================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*===============*/G(FR_AMP), /**/ KC_LEFT,  /**/ KC_DOWN,  /**/ KC_RIGHT, /**/ KC_ENTER, /**/KC_MAC_COPY,/**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/           /*==========================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/  VSC_BC,  /**/ VSC_LBC,  /**/ C(FR_A),  /**/ KC_PGUP,  /**/ C(KC_E),  /**/ XXXXXXX,  /**/KC_MAC_CUT, /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*=========================================================================================================*/
                                              /**/           /**/           /**/           /**/           /**/       /**/
                                              /**/ XXXXXXX,  /**/KC_PGDOWN, /**/ XXXXXXX,  /**/ XXXXXXX,  /**/KC_MAC_SELALL, /**/
                                              /**/           /**/           /**/           /**/           /**/       /**/
                                              /*=======================================================================*/
    /*==============================*/
    /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/
    /*=============================================*/
    /**/           /**/           /**/           /**/
    /**/ _______,  /**/           /**/           /**/
    /**/           /**/           /**/           /**/
    /*===============*/           /**/           /**/
    /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______   /**/
    /**/           /**/           /**/           /**/
    /*=============================================*/
  ),

  [SYMBOL] = LAYOUT_ergodox(
    // Left hand

    /*=========================================================================================================*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*=========================================================================================================*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ FR_EXLM,  /**/  FR_AT,   /**/ FR_LCBR,  /**/ FR_RCBR,  /**/ FR_PERC,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*==========================================================================================*/           /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ FR_HASH,  /**/ FR_UNDS,  /**/ FR_LPRN,  /**/ FR_RPRN,  /**/ FR_AMP,   /*===============*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*==========================================================================================*/           /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/  FR_BSLS, /**/  FR_SLSH, /**/ FR_LBRC,  /**/  FR_RBRC, /**/ FR_TILD,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*=========================================================================================================*/
        /**/       /**/           /**/           /**/           /**/           /**/
        /**/  ___, /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
        /**/       /**/           /**/           /**/           /**/           /**/
        /*=======================================================================*/
                                                                                           /*==============================*/
                                                                                           /**/           /**/           /**/
                                                                                           /**/ _______,  /**/ _______,  /**/
                                                                                           /**/           /**/           /**/
                                                                            /*=============================================*/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/           /**/           /**/ _______,  /**/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/           /**/           /*===============*/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/ _______,  /**/ _______,  /**/ _______,  /**/
                                                                            /**/           /**/           /**/           /**/
                                                                            /*=============================================*/

    // Right hand

                /*=========================================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/  _______, /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*=========================================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/ FR_CIRC,  /**/ FR_PLUS,  /**/  FR_MINS, /**/  FR_GRV,  /**/  FR_SCLN, /**/ _______,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/           /*==========================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*===============*/ FR_PIPE,  /**/  FR_EQL,  /**/  FR_APOS, /**/  FR_COLN, /**/  FR_QUOT, /**/ _______,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/           /*==========================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/  FR_DLR,  /**/ FR_ASTR,  /**/  FR_LESS, /**/ FR_GRTR,  /**/ FR_QUES,  /**/ _______,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*=========================================================================================================*/
                                              /**/           /**/           /**/           /**/           /**/       /**/
                                              /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/  ___, /**/
                                              /**/           /**/           /**/           /**/           /**/       /**/
                                              /*=======================================================================*/
    /*==============================*/
    /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/
    /*=============================================*/
    /**/           /**/           /**/           /**/
    /**/ _______,  /**/           /**/           /**/
    /**/           /**/           /**/           /**/
    /*===============*/           /**/           /**/
    /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______   /**/
    /**/           /**/           /**/           /**/
    /*=============================================*/
  ),


  [NUMPAD] = LAYOUT_ergodox(
    // Left hand

    /*=========================================================================================================*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*=========================================================================================================*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*==========================================================================================*/           /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /*===============*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*==========================================================================================*/           /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*=========================================================================================================*/
        /**/       /**/           /**/           /**/           /**/           /**/
        /**/  ___, /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
        /**/       /**/           /**/           /**/           /**/           /**/
        /*=======================================================================*/
                                                                                           /*==============================*/
                                                                                           /**/           /**/           /**/
                                                                                           /**/ _______,  /**/ _______,  /**/
                                                                                           /**/           /**/           /**/
                                                                            /*=============================================*/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/           /**/           /**/ _______,  /**/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/           /**/           /*===============*/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/ _______,  /**/ _______,  /**/ _______,  /**/
                                                                            /**/           /**/           /**/           /**/
                                                                            /*=============================================*/

    // Right hand

                /*=========================================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/ XXXXXXX,  /**/ KC_ESCAPE, LALT(KC_KP_MINUS),  FR_PERC, /**/KC_KP_SLASH,    _______,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*=========================================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/ XXXXXXX,  /**/ KC_KP_7,  /**/ KC_KP_8,  /**/ KC_KP_9,  /**/KC_KP_ASTERISK, _______,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/           /*==========================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*===============*/ KC_COLN,  /**/ KC_KP_4,  /**/ KC_KP_5,  /**/ KC_KP_6,  /**/KC_KP_MINUS,    FR_DOT,   /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/           /*==========================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/ FR_COMM,  /**/ KC_KP_1,  /**/ KC_KP_2,  /**/ KC_KP_3,  /**/KC_KP_PLUS,/**/ _______,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*=========================================================================================================*/
                                              /**/           /**/           /**/           /**/           /**/       /**/
                                              /**/  FR_0,    /**/   FR_0,   /**/  FR_DOT,  /**/KC_KP_ENTER,     ___, /**/
                                              /**/           /**/           /**/           /**/           /**/       /**/
                                              /*=======================================================================*/
    /*==============================*/
    /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/
    /*=============================================*/
    /**/           /**/           /**/           /**/
    /**/ _______,  /**/           /**/           /**/
    /**/           /**/           /**/           /**/
    /*===============*/           /**/           /**/
    /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______   /**/
    /**/           /**/           /**/           /**/
    /*=============================================*/
  ),


  [MOUSE] = LAYOUT_ergodox(
    // Left hand

    /*=========================================================================================================*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*=========================================================================================================*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/KC_MS_BTN2,/**/ _______,  /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*==========================================================================================*/           /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/KC_MS_BTN1,/**/ _______,  /*===============*/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*==========================================================================================*/           /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
    /*=========================================================================================================*/
        /**/       /**/           /**/           /**/           /**/           /**/
        /**/  ___, /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
        /**/       /**/           /**/           /**/           /**/           /**/
        /*=======================================================================*/
                                                                                           /*==============================*/
                                                                                           /**/           /**/           /**/
                                                                                           /**/ _______,  /**/ _______,  /**/
                                                                                           /**/           /**/           /**/
                                                                            /*=============================================*/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/           /**/           /**/ _______,  /**/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/           /**/           /*===============*/
                                                                            /**/           /**/           /**/           /**/
                                                                            /**/ _______,  /**/ _______,  /**/ _______, /**/
                                                                            /**/           /**/           /**/           /**/
                                                                            /*=============================================*/

    // Right hand

                /*=========================================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*=========================================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/ _______,  /**/ KC_WH_U,  /**/ KC_MS_U,  /**/ KC_WH_D,  /**/ _______,  /**/ _______,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/           /*==========================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*===============*/ _______,  /**/ KC_MS_L,  /**/ KC_MS_D,  /**/ KC_MS_R,  /**/ _______,  /**/ _______,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/           /*==========================================================================================*/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/
                /**/           /**/           /**/           /**/           /**/           /**/           /**/           /**/
                /*=========================================================================================================*/
                                              /**/           /**/           /**/           /**/           /**/       /**/
                                              /**/ _______,  /**/ _______,  /**/ _______,  /**/ _______,  /**/  ___, /**/
                                              /**/           /**/           /**/           /**/           /**/       /**/
                                              /*=======================================================================*/
    /*==============================*/
    /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/
    /**/           /**/           /**/
    /*=============================================*/
    /**/           /**/           /**/           /**/
    /**/ _______,  /**/           /**/           /**/
    /**/           /**/           /**/           /**/
    /*===============*/           /**/           /**/
    /**/           /**/           /**/           /**/
    /**/ _______,  /**/ _______,  /**/ _______   /**/
    /**/           /**/           /**/           /**/
    /*=============================================*/
  )



};


bool suspended = false;

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
    case M_SIGNATURE:
      if (record->event.pressed) {
        SEND_STRING("Q9K is the best thing ever!");
      }
      break;
//      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
