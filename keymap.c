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

//////////////////////////////////////
// my custom keynames
////////////////////////////////////////

#define ________ KC_TRANSPARENT

#define KC_SPC      KC_SPACE
#define KC_BSPC     KC_BSPACE
#define KC_ENT      KC_ENTER
#define KC_SLSH     KC_SLASH
#define KC_BSLSH    KC_BSLASH
#define KC_SCOL     KC_SCOLON

#define WEBUSB      WEBUSB_PAIR

// audio
#define KC_AU_M     KC_AUDIO_MUTE
#define KC_AU_U     KC_AUDIO_VOL_UP
#define KC_AU_D     KC_AUDIO_VOL_DOWN

// mouse keys
#define KC_MU      KC_MS_UP
#define KC_MD      KC_MS_DOWN
#define KC_ML      KC_MS_LEFT
#define KC_MR      KC_MS_RIGHT

#define KC_MWHU    KC_MS_WH_UP
#define KC_MWHD    KC_MS_WH_DOWN
#define KC_MWHL    KC_MS_WH_LEFT
#define KC_MWHR    KC_MS_WH_RIGHT

#define KC_MA0     KC_MS_ACCEL0
#define KC_MA1     KC_MS_ACCEL1
#define KC_MA2     KC_MS_ACCEL2

#define KC_MB1     KC_MS_BTN1
#define KC_MB2     KC_MS_BTN2
#define KC_MB3     KC_MS_BTN3
#define KC_MB4     KC_MS_BTN4
#define KC_MB5     KC_MS_BTN5

// media keys
#define KC_YPP      KC_MEDIA_PLAY_PAUSE
#define KC_YST      KC_MEDIA_STOP
#define KC_YNT      KC_MEDIA_NEXT_TRACK
#define KC_YPT      KC_MEDIA_PREV_TRACK
#define KC_YFF      KC_MEDIA_FAST_FORWARD
#define KC_YRW      KC_MEDIA_REWIND
#define KC_YEJ      KC_MEDIA_EJECT
#define KC_YSE      KC_MEDIA_SELECT

// layer shortcuts
#define _BASE 0
#define _LSYM 1
#define _LNUM 2


enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  MOVE_U,
  MOVE_D,
  MOVE_L,
  MOVE_R,
  MOVE_OFF,
  Mvim,
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

    // 00 | Base
    [0] = LAYOUT_ergodox_pretty(//------|---------------|---------------X---------------|---------------$---------------$---------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        TO(5),          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           WEBUSB,         /**/            TG(9),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRNS,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRNS,        /**/            KC_TRNS,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLSH,
        KC_ESCAPE,      CTL_T(KC_A),    SFT_T(KC_S),    ALT_T(KC_D),    CMD_T(KC_F),    KC_G,           /**/            /**/            /**/            KC_H,           GUI_T(KC_J),    ALT_T(KC_K),    SFT_T(KC_L),    CTL_T(KC_SCOL), KC_QUOTE,
        KC_LSPO,        LT(4,KC_Z),     LT(2,KC_X),     KC_C,           KC_V,           KC_B,           KC_TRNS,        /**/            KC_TRNS,        KC_N,           KC_M,           KC_COMMA,       LT(1,KC_DOT),   LT(3,KC_SLSH),  KC_RSPC,
        LT(1,KC_GRAVE), CTL_T(KC_LEFT),KC_DOWN,        KC_UP,          KC_RGHT,         /*--------------$**/            /**/            /*-------------*/               KC_LEFT,        KC_DOWN,        KC_UP,          CTL_T(KC_RGHT),MO(1),

        /*--------------|***************|***************|***************|***************|---------------$-----------------------------------------------$---------------|***************|***************|***************|***************/
                                                                        /**/            TG(1),          MO(1),          /**/            OSL(1),         TO(1),          /**/
                                                                        /**/                            TT(1),          /**/            LT(1,KC_NO),                    /**/
                                                                        LSFT_T(KC_SPC), KC_BSPC,        KC_TRNS,        /**/            KC_TRNS,        KC_TAB,         RSFT_T(KC_ENT)),
    // 01 | L Symbols
    [1] = LAYOUT_ergodox_pretty(//------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
        ________,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       TO(0),
        ________,       KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
        ________,       KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                       /**/                            ________,       ________,       ________,       ________,       ________,       ________,
        KC_AMPR,        KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
        ________,       ________,       ________,       ________,       ________,                                       /**/                                            ________,       ________,       ________,       ________,       ________,
        /*--------------|***************|***************|***************|***************|---------------$-----------------------------------------------$---------------|***************|***************|***************|***************/
                                                                                        ________,       ________,                       ________,      ________,
                                                                                                        ________,                       ________,
                                                                        ________,       ________,       ________,                       ________,      ________,        ________),

    // 02 | R Numbers
    [2] = LAYOUT_ergodox_pretty(//----------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /***********************/       KC_TRNS,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /***********************/       KC_TRNS,        KC_TRNS,        KC_7,           KC_8,           KC_9,           KC_KP_ASTERISK, KC_F12,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,   /***********************/                                            KC_0,           KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_KP_SLASH,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,  /***********************/             KC_TRNS,        KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_EQUAL,       KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS),
    // 03 | Mouse L
    [3] = LAYOUT_ergodox_pretty(//----------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_AU_M,  KC_TRNS,        /***********************/             KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_MWHD,        KC_MU,          KC_MWHU,        KC_TRNS,        KC_AU_U,/***********************/               KC_TRNS,        KC_RGUI,        KC_RALT,        KC_RSHIFT,      KC_RCTRL,       KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_MWHL,        KC_ML,          KC_MD,          KC_MR,          KC_MWHR,                 /***********************/                       KC_TRNS,        KC_MS_ACCEL2,   KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_AU_D,      /***********************/         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_MS_BTN3,     KC_MS_BTN4,     KC_MS_BTN5,     KC_TRNS,        KC_MS_BTN2,     KC_MS_BTN1
    ),

    // 04 | Mouse R         |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [4] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_AU_M,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_AU_U,        KC_MS_WH_UP,    KC_TRNS,        KC_MS_UP,       KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRNS,                                                                        KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_AU_D,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_MS_BTN1,     KC_MS_BTN2,     KC_TRNS,        KC_MS_BTN5,     KC_MS_BTN4,     KC_MS_BTN3
    ),

    // Layouts              |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [5] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(0),
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(15),         KC_TRNS,                                                                        KC_TRNS,        TO(6),          TO(7),          TO(8),          KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // dvorak               |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [6] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(0),
            KC_TRNS,        KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_TRNS,                                        KC_TRNS,        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_TRNS,
            KC_TRNS,        KC_A,           KC_O,           KC_E,           KC_U,           KC_I,                                                                           KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_TRNS,
            KC_TRNS,        KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,           KC_TRNS,                                        KC_TRNS,        KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // colemakDH            |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [7] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(0),
            KC_TRNS,        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRNS,                                        KC_TRNS,        KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_TRNS,
            KC_TRNS,        KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                                                                           KC_K,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TRNS,
            KC_TRNS,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_TRNS,                                        KC_TRNS,        KC_M,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLSH,       KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // workman              |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [8] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(0),
            KC_TRNS,        KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,           KC_TRNS,                                        KC_TRNS,        KC_J,           KC_F,           KC_U,           KC_P,           KC_SLSH,       KC_TRNS,
            KC_TRNS,        KC_A,           KC_S,           KC_H,           KC_T,           KC_G,                                                                           KC_Y,           KC_N,           KC_E,           KC_O,           KC_I,           KC_TRNS,
            KC_TRNS,        KC_Z,           KC_X,           KC_M,           KC_C,           KC_V,           KC_TRNS,                                        KC_TRNS,        KC_K,           KC_L,           KC_COMMA,       KC_DOT,         KC_SLSH,       KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // media                |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [9] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_0,           KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_AU_M,        KC_AU_D,        KC_YST,         KC_YPP,         KC_CALCULATOR,                                                                  KC_MY_COMPUTER, KC_WWW_SEARCH,  KC_WWW_HOME,    KC_WWW_REFRESH, KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_AU_U,        KC_YNT,         KC_YPT,         KC_YEJ,         KC_MAIL,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_WWW_FAVORITES,KC_TRNS,       KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_YFF,         KC_YRW,         KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // sys                  |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [10] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_PSCREEN,     LED_LEVEL,      KC_SYSTEM_POWER,KC_SYSTEM_SLEEP,KC_SYSTEM_WAKE, KC_TRNS,                                        KC_TRNS,        KC_BRIGHTNESS_UP,KC_BRIGHTNESS_DOWN,KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_PAUSE,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // FnDigits             |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [11] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_F11,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F15,         KC_TRNS,                                        KC_TRNS,       KC_F16,          KC_TRNS,        KC_F18,         KC_TRNS,        KC_F20,         KC_TRNS,
            KC_TRNS,        KC_F1,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F5,          KC_TRNS,                                        KC_TRNS,        KC_F6,          KC_TRNS,        KC_F8,          KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_1,           KC_2,           KC_3,           KC_4,           KC_KP_5,                                                                        KC_6,           KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_0,           KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F21,         KC_F22,         KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_F23,         KC_F24,         KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // nav                  |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [12] = LAYOUT_ergodox_pretty(
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_PGUP,        KC_PGDOWN,      KC_PSCREEN,     KC_INSERT,      KC_DELETE,      KC_TRNS,                                        KC_TRNS,        KC_APPLICATION, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_END,         KC_HOME,        KC_SCROLLLOCK,  KC_TRNS,        KC_TRNS,                                                                        KC_LEFT,        KC_UP,          KC_RIGHT,       KC_DOWN,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_BSPC,        KC_TAB,         KC_ENTER,       KC_ESCAPE,      KC_SPACE,       KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        TG(13),         TO(0),          KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // Layer....            |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [13] = LAYOUT_ergodox_pretty(
            KC_HYPR,        KC_MEH,         KC_TRNS,        LCTL(KC_LSHIFT),KC_RGUI,        KC_RCTRL,       KC_RCTRL,                                       KC_RALT,        KC_RSHIFT,      KC_LGUI,        KC_LCTRL,       KC_LALT,        KC_LSHIFT,      LSFT(KC_LGUI),
            KC_TRNS,        KC_TRNS,        KC_TRNS,        LCTL(KC_LALT),  KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                        KC_ESCAPE,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_LSPO,        KC_RSPC,        KC_TRNS,        KC_RALT,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_MAC_UNDO,    KC_TRNS,        KC_MAC_CUT,                                                                                                     KC_TRNS,        KC_RGUI,        KC_LALT,        KC_TRNS,KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        TO(0),
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // Layer....            |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [14] = LAYOUT_ergodox_pretty(
            KC_MS_UP,       KC_MS_DOWN,     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_MS_BTN2,     KC_MS_BTN1,     KC_MS_RIGHT,    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_MS_WH_UP,    KC_MS_WH_LEFT,  KC_TRNS,                                        KC_TRNS,        KC_MS_BTN3,     KC_MS_BTN4,     KC_MS_BTN5,     KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        DYN_REC_START1, KC_TRNS,        KC_TRNS,        KC_MS_WH_DOWN,  KC_MS_WH_RIGHT,                                                                 KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
            KC_TRNS,        KC_TRNS,        KC_MS_ACCEL0,   KC_TRNS,        KC_TRNS,                                                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                                                            KC_TRNS,        KC_TRNS,
                                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    // Mouse testing        |---------------|---------------|---------------|---------------|---------------$---------------$---------------$---------------$---------------|---------------|---------------|---------------|---------------|---------------
    [15] = LAYOUT_ergodox_pretty(
            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          TO(0),
            KC_NO,          Mvim,           Mvim,           Mvim,           Mvim,           Mvim,           KC_NO,          /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
            KC_NO,          Mvim,           Mvim,           Mvim,           Mvim,           Mvim,           /**/            /**/            /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
            KC_NO,          Mvim,           Mvim,           Mvim,           Mvim,           Mvim,           KC_NO,          /**/            /**/            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
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
void handle_mvim_grid_event(keyrecord_t *record/*uint8_t col, uint8_t row*/) {
    // decide what to do based on state
#ifdef CONSOLE_ENABLE
            uprintf("MVIM | col: %u, row: %u, pressed: %u\n", record->event.key.col, record->event.key.row, record->event.pressed);
#endif

    if (!stateMove) {
        set_direction();
    } else {
        set_move();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif
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
        case Mvim:
            // I want to log column, and rows here to make sure i understand how it works
            // pass key coordinates to pointer route
            handle_mvim_grid_event(record);
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

//  find what it is that is not working; console true/ debug enable/ or matrix=true?
void keyboard_post_init_user(void) {
    // Customise these values to desired behave
    // debug_enable=true; // keyboard becomes very slow when using this or next setting; why??
    // debug_matrix=true; // this makes keyb very slow!!!
    // debug_keyboard=true;
    // debug_mouse=true;

    layer_state_set_user(layer_state);
}















