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



/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
 #define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/
#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
#define MIDI_TONE_KEYCODE_OCTAVES 3

