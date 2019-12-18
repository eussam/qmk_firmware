/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 20

//PF: test phil => sans effet...j'ai modifié le scrolling speed dans les parms système (mis à zéro)
// #undef MOUSEKEY_WHEEL_MAX_SPEED
// #define MOUSEKEY_WHEEL_MAX_SPEED 1  // default : 8

// #undef MOUSEKEY_WHEEL_TIME_TO_MAX
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 100  // default : 40

// https://github.com/qmk/qmk_firmware/tree/master/keyboards/ergodox_ez
//
#ifndef QMK_KEYS_PER_SCAN
#define QMK_KEYS_PER_SCAN 4
#endif // !QMK_KEYS_PER_SCAN

//PF: fonction train du configurateur Ergodox EZ
//https://configure.ergodox-ez.com/ergodox-ez/layouts/NoDJA/latest/0
#define FIRMWARE_VERSION u8"NoDJA/latest"
