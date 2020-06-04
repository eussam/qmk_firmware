#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 20

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR

// PF: control plus fin de l'auto shift (cf rules.mk)
// #define AUTO_SHIFT_TIMEOUT 150 //default 175 (pour la plupart des personnes, une valeur entre 135 et 150 suffit)
#define AUTO_SHIFT_TIMEOUT 175 //default 175 (pour la plupart des personnes, une valeur entre 135 et 150 suffit)
// #define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC
