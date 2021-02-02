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

#define PI 3.14159265 // why here ???

#define MIDI_ENABLE_STRICT 1 // Prevent use of disabled MIDI features in the keymap
#define MIDI_BASIC
#define MIDI_ADVANCED
#define MIDI_TONE_KEYCODE_OCTAVES 6

