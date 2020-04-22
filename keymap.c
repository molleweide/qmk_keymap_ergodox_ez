#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"

#include "pointing_device.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL


// my custom keynames
// #define KC_TRNSx   KC_TRNS
#define KC_SPC      KC_SPACE
#define KC_ENT      KC_ENTER
#define WEBUP       WEBUSB_PAIR

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  MOVE_U,
  MOVE_D,
  MOVE_L,
  MOVE_R,
  MOVE_OFF,
  M11,
  M12,
  M13,
  M14,
  M15,
  M21,
  M22,
  M23,
  M24,
  M25,
  M31,
  M32,
  M33,
  M34,
  M35,
  M41,
  M42,
  M43,
  M44,
  M45,
  M51,
  M52,
  M53,
  M54,
  M55,
  PFREEZE,
  SET_MS_STATE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // 00 | Base            |---------------|---------------|---------------X---------------|---------------$---------------$---------------$---------------$---------------|---------------X---------------|---------------|---------------|---------------
    [0] = LAYOUT_ergodox_pretty(
            TO(5),          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           WEBUSB_PAIR,    /***********************/       TG(9),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRNS,
            KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRNS,        /***********************/       KC_TRNS,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
            KC_ESCAPE,      LT(4,KC_A),     LSFT_T(KC_S),   LALT_T(KC_D),   LGUI_T(KC_F),   KC_G,                           /***********************/                       KC_H,           RGUI_T(KC_J),   RALT_T(KC_K),   RSFT_T(KC_L),   LT(3,KC_SCOLON),KC_QUOTE,
            KC_LSPO,        RCTL_T(KC_Z),   LT(2,KC_X),     KC_C,           KC_V,           KC_B,           KC_TRNS,        /***********************/       KC_TRNS,        KC_N,           KC_M,           KC_COMMA,       LT(1,KC_DOT),   RCTL_T(KC_SLASH),KC_RSPC,
            LT(1,KC_GRAVE), KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       /*******************************************************************************|******/        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       MO(1),
            /*              |***************|***************|***************|***************| *****/        TG(1),          MO(1),          OSL(1),         TO(1),          /***************|***************|***************|***************|                       */
            /*              |***************|***************|***************|***************|***************########*/      TT(1),          LT(1,KC_NO),  /*########********########********|***************|***************|***************|                       */
            /*              |***************|***************|***************|********/      LSFT_T(KC_SPC), KC_BSPACE,      KC_TRNS,        KC_TRNS,        KC_TAB,         RSFT_T(KC_ENT)  /***************|***************|***************|                       */
    ),


    // 01 | L Symbols       |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [1] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRNS,         /***********************/      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(0),
            KC_TRNS,        KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRNS,        /***********************/       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                                                                       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_AMPR,        KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                                                                                    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS, KC_TRNS,
                                                                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // 02 | R Numbers       |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [2] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /***********************/       KC_TRNS, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /***********************/       KC_TRNS, KC_TRNS, KC_7,           KC_8,           KC_9,           KC_KP_ASTERISK, KC_F12,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,   /***********************/                    KC_0,           KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_KP_SLASH,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  /***********************/                               KC_TRNS, KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_EQUAL,       KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // 03 | Mouse L         |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [3] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_AUDIO_MUTE,  KC_TRNS,        /***********************/       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_MS_WH_DOWN,  KC_MS_UP,       KC_MS_WH_UP,    KC_TRNS,        KC_AUDIO_VOL_UP,/***********************/       KC_TRNS,        KC_RGUI,        KC_RALT,        KC_RSHIFT,      KC_RCTRL,       KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_MS_WH_LEFT,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT,                 /***********************/                       KC_TRNS, KC_MS_ACCEL2,   KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_AUDIO_VOL_DOWN,      /***********************/                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                            KC_TRNS, KC_TRNS,
                                                                                            KC_MS_BTN3,     KC_MS_BTN4,     KC_MS_BTN5,     KC_TRNS, KC_MS_BTN2,     KC_MS_BTN1
    ),

    // 04 | Mouse R         |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [4] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_AUDIO_MUTE,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_AUDIO_VOL_UP,KC_MS_WH_UP,    KC_TRNS, KC_MS_UP,       KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRNS,                                                                 KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_AUDIO_VOL_DOWN,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                            KC_TRNS, KC_TRNS,
                                                                                            KC_MS_BTN1,     KC_MS_BTN2,     KC_TRNS, KC_MS_BTN5,     KC_MS_BTN4,     KC_MS_BTN3
    ),

    // Layouts              |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [5] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(15),         KC_TRNS,                                                                 KC_TRNS, TO(6),          TO(7),          TO(8),          KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // dvorak               |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [6] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
            KC_TRNS,        KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_TRNS,                                 KC_TRNS, KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_TRNS,
            KC_TRNS,        KC_A,           KC_O,           KC_E,           KC_U,           KC_I,                                                                           KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_TRNS,
            KC_TRNS,        KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,           KC_TRNS,                                 KC_TRNS, KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // colemakDH            |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [7] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
            KC_TRNS,        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRNS,                                 KC_TRNS, KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_TRNS,
            KC_TRNS,        KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                                                           KC_K,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TRNS,
            KC_TRNS,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_TRNS,                                 KC_TRNS, KC_M,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                            KC_TRNS, KC_TRNS,
                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // workman              |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [8] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
            KC_TRNS,        KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,           KC_TRNS,                                 KC_TRNS, KC_J,           KC_F,           KC_U,           KC_P,           KC_SLASH,       KC_TRNS,
            KC_TRNS,        KC_A,           KC_S,           KC_H,           KC_T,           KC_G,                                                                           KC_Y,           KC_N,           KC_E,           KC_O,           KC_I,           KC_TRNS,
            KC_TRNS,        KC_Z,           KC_X,           KC_M,           KC_C,           KC_V,           KC_TRNS,                                 KC_TRNS, KC_K,           KC_L,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                            KC_TRNS, KC_TRNS,
                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // media                |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [9] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_0,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_CALCULATOR,                                                                  KC_MY_COMPUTER, KC_WWW_SEARCH,  KC_WWW_HOME,    KC_WWW_REFRESH, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PREV_TRACK,KC_MEDIA_EJECT, KC_MAIL,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WWW_FAVORITES,KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_MEDIA_FAST_FORWARD,KC_MEDIA_REWIND,KC_TRNS,
                                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                            KC_TRNS, KC_TRNS,
                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // sys                  |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [10] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_PSCREEN,     LED_LEVEL,      KC_SYSTEM_POWER,KC_SYSTEM_SLEEP,KC_SYSTEM_WAKE, KC_TRNS,                                 KC_TRNS, KC_BRIGHTNESS_UP,KC_BRIGHTNESS_DOWN,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_PAUSE,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // FnDigits             |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [11] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_F11,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F15,         KC_TRNS,                                 KC_TRNS, KC_F16,         KC_TRNS, KC_F18,         KC_TRNS, KC_F20,         KC_TRNS,
            KC_TRNS,        KC_F1,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F5,          KC_TRNS,                                 KC_TRNS, KC_F6,          KC_TRNS, KC_F8,          KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_1,           KC_2,           KC_3,           KC_4,           KC_KP_5,                                                                        KC_6,           KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_0,           KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F21,         KC_F22,         KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_F23,         KC_F24,         KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // nav                  |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [12] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_PGUP,        KC_PGDOWN,      KC_PSCREEN,     KC_INSERT,      KC_DELETE,      KC_TRNS,                                 KC_TRNS, KC_APPLICATION, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_END,         KC_HOME,        KC_SCROLLLOCK,  KC_TRNS,        KC_TRNS,                                                                 KC_LEFT,        KC_UP,          KC_RIGHT,       KC_DOWN,        KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_BSPACE,      KC_TAB,         KC_ENTER,       KC_ESCAPE,      KC_SPACE,       KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS,        TG(13),         TO(0),          KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // Layer....            |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [13] = LAYOUT_ergodox_pretty(
            KC_HYPR,        KC_MEH,         KC_TRNS,        LCTL(KC_LSHIFT),KC_RGUI,        KC_RCTRL,       KC_RCTRL,                                       KC_RALT,        KC_RSHIFT,      KC_LGUI,        KC_LCTRL,       KC_LALT,        KC_LSHIFT,      LSFT(KC_LGUI),
            KC_TRNS,        KC_TRNS,        KC_TRNS,        LCTL(KC_LALT),  KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                 KC_ESCAPE,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_LSPO,        KC_RSPC,        KC_TRNS,        KC_RALT,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_MAC_UNDO,    KC_TRNS,        KC_MAC_CUT,                                                                                                     KC_TRNS, KC_RGUI,        KC_LALT,        LALT(LSFT(RCTL(KC_LGUI))),KC_TRNS,
                                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                            KC_TRNS, TO(0),
                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Layer....            |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [14] = LAYOUT_ergodox_pretty(
            KC_MS_UP,       KC_MS_DOWN,     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                 KC_TRNS, KC_MS_BTN2,     KC_MS_BTN1,     KC_MS_RIGHT,    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MS_WH_UP,    KC_MS_WH_LEFT,  KC_TRNS,                                 KC_TRNS, KC_MS_BTN3,     KC_MS_BTN4,     KC_MS_BTN5,     KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        DYN_REC_START1, KC_TRNS,        KC_TRNS,        KC_MS_WH_DOWN,  KC_MS_WH_RIGHT,                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_MS_ACCEL0,   KC_TRNS, KC_TRNS,                                                                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                                                                            KC_TRNS, KC_TRNS,
                                                                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Mouse testing        |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [15] = LAYOUT_ergodox_pretty(
            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(0),
            KC_NO,          M11,            M12,            M13,            M14,            M15,            KC_NO,          /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
            KC_NO,          M21,            M22,            M23,            M24,            M25,            /**/            /**/            /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
            KC_NO,          M31,            M32,            M33,            M34,            M35,            KC_NO,          /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          /**/            /**/            /**/            /**/            /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
            /**/            /**/            /**/            /**/            /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,           /**/            /**/            /**/            /**/            /**/            /**/
            /**/            /**/            /**/            /**/            /**/            /**/            /**/            KC_NO,          KC_NO,          /**/            /**/            /**/            /**/            /**/            /**/            /**/
            /**/            /**/            /**/            /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO           /**/            /**/            /**/            /**/            /**/
    ),
};


rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

// # VARIABLES 
// 
//     pointerState        // dirReceiver; moveReceiver
//     specSettings        // if true, then I can change mode/settings
//     
//     directionAngle 
//     directionInputArr   // 1-3
//     directionMode       // hardcoded; free angle
// 
//     moveMode            // hardcoded steps; specify freely
//     moveInputLength     // 1-3
//     moveStepping        // continuous; discrete
//     moveFreeze
// 
//     keepDir
//     keepMove

//    clickMode           // regular; hook
bool suspended = false;
bool moveToggle = false;
bool moveState = false;
uint8_t moveDirection = 0;
uint8_t cursorTimeout = 10;
uint16_t lastCursor = 0;
uint8_t stateMove = 0;

void pointer_click(void) {
    // regular || hook
}

void reset_pointer(void) {
    // reset all variables and stop movement
}

void set_pointer_mode(void) {
    // 
    reset_pointer();
}

void set_direction(void) {
    // change state 
}
void set_move(void) {
    // change state
}
void computer_direction(void){
    // 
}
void compute_move_magnitude(void) {
    //
}
void pointer_mode_router(void) {
    // decide what to do based on state
    if (!stateMove) {
        set_direction();
    } else {
        set_move();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case TOGGLE_LAYER_COLOR:
            if (record->event.pressed) {
                disable_layer_color ^= 1;
            }
            return false;
        case MOVE_OFF:
            if (record->event.pressed) {
                moveToggle = false;
            }
            break;
        case MOVE_U:
            if(record->event.pressed) {
                moveDirection = 0;
                moveToggle = true;
            }
            break;
        case MOVE_D:
            if(record->event.pressed) {
                moveDirection = 2;
                moveToggle = true;
            }
            break;
        case MOVE_L:
            if(record->event.pressed) {
                moveDirection = 3;
                moveToggle = true;
            }
            break;
        case MOVE_R:
            if(record->event.pressed) {
                moveDirection = 1;
                moveToggle = true;
            }
            break;
        case M11:
        case M12:
        case M13:
        case M14:
        case M15:
        case M21:
        case M22:
        case M23:
        case M24:
        case M25:
        case M31:
        case M32:
        case M33:
        case M34:
        case M35:
        case M41:
        case M42:
        case M43:
        case M44:
        case M45:
        case M51:
        case M52:
        case M53:
        case M54:
        case M55:
            pointer_mode_router();
        case PFREEZE:
            reset_pointer();
        case SET_MS_STATE:
            set_pointer_mode();
    }
    return true;
}

void pointing_device_task(void) {
    report_mouse_t report = pointing_device_get_report(); 
    if (timer_elapsed(lastCursor) > cursorTimeout && moveToggle) {
        lastCursor = timer_read();
        switch (moveDirection) {
            case 0:
                report.y = -5;
                break;
            case 2:
                report.y = 5;
                break;
            case 3:
                report.x = -5;
                break;
            case 1:
                report.x = 5;
                break;
        }  
    }
    pointing_device_set_report(report);
    pointing_device_send();
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
    switch (layer) {
        case 0:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(0,252,255);
            }
            break;
        case 1:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(7,255,147);
            }
            break;
        case 2:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(7,255,147);
            }
            break;
        case 3:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(92,179,121);
            }
            break;
        case 4:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(92,179,121);
            }
            break;
        case 5:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(45,255,255);
            }
            break;
        case 6:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(142,255,143);
            }
            break;
        case 7:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(217,255,133);
            }
            break;
        case 8:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(255,255,201);
            }
            break;
        case 9:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(210,255,255);
            }
            break;
        case 10:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(1,0,114);
            }
            break;
        case 11:
            if(!disable_layer_color) {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(1);
                rgblight_sethsv_noeeprom(43,255,154);
            }
            break;
        default:
            if(!disable_layer_color) {
                rgblight_config.raw = eeconfig_read_rgblight();
                if(rgblight_config.enable == true) {
                    rgblight_enable();
                    rgblight_mode(rgblight_config.mode);
                    rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
                }
                else {
                    rgblight_disable();
                }
            }
            break;
    }
    return state;

};

void keyboard_post_init_user(void) {
    layer_state_set_user(layer_state);
}








