/*
   Set any config.h overrides for your specific keymap here.
   See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file

   Key repeat rate is determined by OS, not qmk.
   */
#define ORYX_CONFIGURATOR
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 40

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 4

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 1

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 80

#define FIRMWARE_VERSION u8"N4mKd/60MqD"

#define PERMISSIVE_HOLD // should make using mod tap more comfortable for fast typing.

#define TAPPING_TERM 200

// right hand upper left corner
//#define BOOTMAGIC_LITE_COLUMN 0 // col is row
//#define BOOTMAGIC_LITE_ROW 1    // row is col




////////////////////////////////////////
// my custom keynames
////////////////////////////////////////

#define ________    KC_TRANSPARENT // Fillers to make layering more clear
#define oooooooo    KC_TRANSPARENT
#define xxxxxxxx    KC_NO

// #define KC_SPC      KC_SPACE
// #define KC_BSPC     KC_BSPACE
// #define KC_ENT    KC_ENTERER
// #define KC_SLSH     KC_SLASH
// #define KC_BSLSH    KC_BSLASH
// #define KC_SCOL     KC_SCOLON
// #define KC_COM      KC_COMMAMA
//
// media keys
//#define KC_YPP      KC_MEDIA_PLAY_PAUSE
//#define KC_YST      KC_MEDIA_STOP
//#define KC_YNT      KC_MEDIA_NEXT_TRACK
//#define KC_YPT      KC_MEDIA_PREV_TRACK
//#define KC_YFF      KC_MEDIA_FAST_FORWARD
//#define KC_YRW      KC_MEDIA_REWIND
//#define KC_YEJ      KC_MEDIA_EJECT
//#define KC_YSE      KC_MEDIA_SELECT







// ////////////////////////////////////////
// // config.k from satan
// ////////////////////////////////////////
//
// // #ifndef CONFIG_USER_H
// // #define CONFIG_USER_H
//
// // #include "../../config.h"
//
// /*
//  * MIDI options
//  */
//
// /* Prevent use of disabled MIDI features in the keymap */
 #define MIDI_ENABLE_STRICT 1
//
// /* enable basic MIDI features:
//    - MIDI notes can be sent when in Music mode is on
// */
// #define MIDI_BASIC
//
// /* enable advanced MIDI features:
//    - MIDI notes can be added to the keymap
//    - Octave shift and transpose
//    - Virtual sustain, portamento, and modulation wheel
//    - etc.
// */
 #define MIDI_ADVANCED
//
// /* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
 #define MIDI_TONE_KEYCODE_OCTAVES 2

