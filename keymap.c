#include QMK_KEYBOARD_H

#include <math.h>
#include "pointing_device.h"
#define PI 3.14159265

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  PDIR1,
  PDIR2,
  PDIR3,
  PDIR4,
  PDIR5,
  PDIR6,
  PDIR7,
  PDIR8,
  PDIR9,
  PDIR10,
  PDIR11,
  PDIR12,
  PVEL1,
  PVEL2,
  PVEL3,
  PVEL4,
  PVEL5,
  PVEL6,
  PVEL7,
  PVEL8,
  PVEL9,
  PVEL10,
  PVEL11,
  PVEL12,
};

enum layer_names {
  _BASE = 0,
  _SYMB,
  _MOVE,
  _POINT,
  _FUN,
  _MIDI,
  _TEST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ergodox_pretty(//--|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      TO(_TEST),      xxxxxxxx,        xxxxxxxx,       xxxxxxxx,      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC__VOLUP,      /**/            KC_MS_WH_UP,    KC_Y,           KC_U,           KC_I,             KC_O,             KC_P,             KC_BSLASH,
      KC_ESC, /*****/ CTL_T(KC_A),    SFT_T(KC_S),    ALT_T(KC_D),    CMD_T(KC_F),    KC_G,           /**/            /**/            /**/            KC_H,           CMD_T(KC_J),    ALT_T(KC_K),      SFT_T(KC_L),      CTL_T(KC_SCOLON), KC_QUOTE,
      KC_MINUS,       LT(_MOVE,KC_Z), LT(_SYMB,KC_X), LT(_FUN,KC_C),  KC_V,           KC_B,           KC__VOLDOWN,    /**/            KC_MS_WH_DOWN,  KC_N,           KC_M,           LT(_FUN,KC_COMMA),LT(_SYMB,KC_DOT), KC_SLASH ,        KC_UNDS,
      xxxxxxxx,       CTL_T(KC_LEFT), xxxxxxxx,        KC_ESC,         TO(_POINT),     /*-------------*/              /**/            /*-------------*/               TO(_POINT),     KC_QUOTE,        xxxxxxxx,         CTL_T(KC_RGHT),   xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ KC__MUTE,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,       /***************/
      /*-----------------------------------------------------------*/ LSFT_T(KC_SPACE),KC_BSPACE,     KC_TRNS,        /**/            KC_TRNS,        KC_TAB,         RSFT_T(KC_ENTER)),
  [_SYMB] = LAYOUT_ergodox_pretty(//---------------|---------------X---------------|---------------$------------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      ________,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ________,       /**/            xxxxxxxx,       KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         TO(_BASE),
      ________,       KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        ________,       /**/            xxxxxxxx,       KC_QUOTE,       KC_7,           KC_8,           KC_9,           KC_EQUAL,       KC_F12,
      ________,       KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                       /**/            /**/            KC_0,           KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_KP_SLASH,
      KC_AMPR,        KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        ________,       /**/            xxxxxxxx,       KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_MINUS,       KC_UNDS,
      ________,       ________,       ________,       ________,       ________,       /***************/               /**/            /***************/               KC_LPRN,        KC_COMMA,       KC_DOT,         CTL_T(KC_RPRN),        oooooooo,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ ________,       ________,       /**/            ________,      ________,
      /*-------------------------------------------------------------------------------------------*/ ________,       /**/            ________,
      /*-----------------------------------------------------------*/ ________,       ________,       ________,       /**/            ________,      ________,        ________),
  [_MOVE] = LAYOUT_ergodox_pretty(//---|-----------|---------------X---------------|---------------$------------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       /**/            /**/            /**/            KC_LEFT,        KC_DOWN,       KC_UP,       KC_RIGHT,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       /*-------------*/               /**/            /*-------------*/               ________,       ________,       ________,       ________,       ________,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ ________,       ________,       /**/            ________,       ________,
      /*-------------------------------------------------------------------------------------------*/ ________,       /**/            ________,       /***************/
      /*-----------------------------------------------------------*/ ________,       ________,       ________,       /**/            ________,       ________,         ________),
  [_POINT] = LAYOUT_ergodox_pretty(//-|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),
      xxxxxxxx,       xxxxxxxx,       PDIR9,          PDIR10,         PDIR11,         PDIR12,         xxxxxxxx,       /**/            xxxxxxxx,       PVEL12,         PVEL10,         PVEL11,         PVEL12,         xxxxxxxx,       xxxxxxxx,
      xxxxxxxx,       PDIR5,          PDIR6,          PDIR7,          PDIR8,          TO(_BASE),      /**/            /**/            /**/            TO(_BASE),      PVEL5,          PVEL6,          PVEL7,          PVEL8,          xxxxxxxx,
      xxxxxxxx,       PDIR1,          PDIR2,          PDIR3,          PDIR4,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       PVEL1,          PVEL2,          PVEL3,          PVEL4,          xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),      KC_MS_BTN1,                                     /**/                                            KC_MS_BTN2,     TO(_BASE),      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,
      /*-----------------------------------------------------------*/ KC_MS_BTN3,     KC_MS_BTN4,     xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_MS_BTN5),
  [_FUN] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),
      xxxxxxxx,       KC_F9,          KC_F10,         KC_F11,         KC_F12,         xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_F21,         KC_F22,         KC_F23,         KC_F24,         xxxxxxxx,
      xxxxxxxx,       KC_F5,          KC_F6,          KC_F7,          CMD_T(KC_F8),   xxxxxxxx,       /**/            /**/            /**/            xxxxxxxx,       CMD_T(KC_F17),  KC_F18,         KC_F19,         KC_F20,         xxxxxxxx,
      xxxxxxxx,       CTL_T(KC_F1),   SFT_T(KC_F2),   KC_F3,          KC_F4,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_F13,         KC_F14,         SFT_T(KC_F15),  CTL_T(KC_F16),  xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,
      /*-----------------------------------------------------------*/ KC_LALT,        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_RALT),
  [_MIDI] = LAYOUT_ergodox_pretty(//---|--------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       TO(_BASE),
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       /**/            /**/            /**/            ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       /*-------------*/               /**/            /*-------------*/               ________,       ________,       ________,       ________,       ________,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ ________,       ________,       /**/            ________,       ________,
      /*-------------------------------------------------------------------------------------------*/ ________,       /**/            ________,       /***************/
      /*-----------------------------------------------------------*/ ________,       ________,       ________,       /**/            ________,       ________,         ________),
  [_TEST] = LAYOUT_ergodox_pretty(//------------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       RESET,          xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,
      /*-----------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx),
};

// VARIABLES ----------------------------------------
rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

int last_pressed_dir_key = 0;
int last_pressed_vel_key = 0;
int POINTER_V = 0;
int POINTER_X = 0;
int POINTER_Y = 0;

float rad = PI / 180;
float CLOCK_SHIFT = - PI / 3;

int POINTER_UPDATE_INTERVAL = 15; // milliseconds
uint16_t TIMESTAMP_PREV_POINTER = 0; // change to regular int??????

// TODO
// how can I shift the valus so that U/D/L/R becomes as smooth as possible

void set_dir_curr(int steps){
  float direction_in_radians = (steps-1) * 30 * rad; // 12 * degrees * rad
  POINTER_X = round(POINTER_V * cos(direction_in_radians + CLOCK_SHIFT));
  POINTER_Y = round(POINTER_V * sin(direction_in_radians + CLOCK_SHIFT));
}

// TODO
//   add and not = prev keycode!!!

void handle_pointer_keycodes(uint16_t keycode, keyrecord_t *record){
  // normalize pointer
  int pk = keycode - PDIR1 + 1;
  if ( 1 <= pk && pk <= 12 ) {
    if (record->event.pressed) {

      set_dir_curr(pk); last_pressed_dir_key = keycode;

    } else {
      // release...
      if (last_pressed_dir_key == keycode) {
        last_pressed_dir_key = 0;
      }
    }
  }
  if ( 13 <= pk && pk <= 24 ) {
    if (record->event.pressed) {

      POINTER_V = pk - 12; last_pressed_vel_key = keycode;

    } else {
      // release...
      if (last_pressed_vel_key == keycode) {
        last_pressed_vel_key = 0;
      }
    }
  }
}

void pointing_device_task(void) {
  report_mouse_t report = pointing_device_get_report();

  if (timer_elapsed(TIMESTAMP_PREV_POINTER) > POINTER_UPDATE_INTERVAL
      && last_pressed_dir_key > 0
      && last_pressed_vel_key > 0
     ) {
    TIMESTAMP_PREV_POINTER = timer_read();
    report.x = POINTER_X;
    report.y =  POINTER_Y;
  }
  pointing_device_set_report(report);
  pointing_device_send();
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
    case PDIR1 ... PVEL12:
      handle_pointer_keycodes(keycode, record);
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  if(!disable_layer_color) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    switch (layer) {
      case _BASE:
        rgblight_sethsv_noeeprom(0,252,255);
        break;
      case _SYMB:
      case _POINT:
        rgblight_sethsv_noeeprom(10,90,40);
        break;
      case _FUN:
        rgblight_sethsv_noeeprom(70,0,50);
        break;
      case _TEST:
        rgblight_sethsv_noeeprom(100,150,100);
        break;
      default:
        rgblight_config.raw = eeconfig_read_rgblight();
        if(rgblight_config.enable == true) {
          rgblight_enable();
          rgblight_mode(rgblight_config.mode);
          rgblight_sethsv(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
        }
        else {
          rgblight_disable();
        }
        break;
    }
  }
  return state;
}

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}
