#include QMK_KEYBOARD_H

#include <math.h>
#include "pointing_device.h"
#define PI 3.14159265

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  MGRID,
  MREPEAT,
  MREPEAT_REV,
  MRESET,
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

enum tapdance_keycodes {
  TD_MMODE,       // switch mouse mode
  TD_ESC_LCO,    // esc or move to L mouse complement
  TD_QUOTE_RCO,  // esc or move to R mouse complement
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /**
   * BASE ----------------------------------------
   */

  [_BASE] = LAYOUT_ergodox_pretty(//--|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      TO(_TEST),      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           WEBUSB_PAIR,    /**/            xxxxxxxx,       KC_6,           KC_7,           KC_8,             KC_9,             KC_0,             xxxxxxxx,
      KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC__VOLUP,      /**/            KC_MS_WH_UP,    KC_Y,           KC_U,           KC_I,             KC_O,             KC_P,             KC_BSLASH,
      KC_ESC, /*****/ CTL_T(KC_A),    SFT_T(KC_S),    ALT_T(KC_D),    CMD_T(KC_F),    KC_G,           /**/            /**/            /**/            KC_H,           CMD_T(KC_J),    ALT_T(KC_K),      SFT_T(KC_L),      CTL_T(KC_SCOLON), KC_QUOTE,
      KC_MINUS,       LT(_MOVE,KC_Z), LT(_SYMB,KC_X), LT(_FUN,KC_C),  KC_V,           KC_B,           KC__VOLDOWN,    /**/            KC_MS_WH_DOWN,  KC_N,           KC_M,           LT(_FUN,KC_COMMA),LT(_SYMB,KC_DOT), KC_SLASH ,        KC_UNDS,
      xxxxxxxx,       CTL_T(KC_LEFT), xxxxxxxx,        KC_ESC,         TO(_POINT),     /*-------------*/               /**/            /*-------------*/               TO(_POINT),     KC_QUOTE,        xxxxxxxx,         CTL_T(KC_RGHT),   xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ KC__MUTE,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,       /***************/
      /*-----------------------------------------------------------*/ LSFT_T(KC_SPACE),KC_BSPACE,     KC_TRNS,        /**/            KC_TRNS,        KC_TAB,         RSFT_T(KC_ENTER)),

  /**
   * SYMBOLS / NUMBERS ---------------------------
   */

  [_SYMB] = LAYOUT_ergodox_pretty(//---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      ________,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ________,       /**/            xxxxxxxx,       KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         TO(_BASE),
      ________,       KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        ________,       /**/            xxxxxxxx,       KC_QUOTE,       KC_7,           KC_8,           KC_9,           KC_EQUAL,       KC_F12,
      ________,       KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                       /**/            /**/            KC_0,           KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_KP_SLASH,
      KC_AMPR,        KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        ________,       /**/            xxxxxxxx,       KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_MINUS,       KC_UNDS,
      ________,       ________,       ________,       ________,       ________,       /***************/               /**/            /***************/               KC_LPRN,        KC_COMMA,       KC_DOT,         CTL_T(KC_RPRN),        oooooooo,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ ________,       ________,       /**/            ________,      ________,
      /*-------------------------------------------------------------------------------------------*/ ________,       /**/            ________,
      /*-----------------------------------------------------------*/ ________,       ________,       ________,       /**/            ________,      ________,        ________),


  /**
   * MOUSE_LEFT_AND_RIGHT ------------------------------------------- MOUSE_LEFT_AND_RIGHT ------------------------------------------ MOUSE_LEFT_AND_RIGHT ---------------------------------------------------------- MOUSE_LEFT_AND_RIGHT -----------
   */

   [_MOVE] = LAYOUT_ergodox_pretty(//---|-----------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
    ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
    ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
    ________,       ________,        ________,       ________,      ________,       ________,       /**/            /**/            /**/            KC_LEFT,        KC_DOWN,       KC_UP,       KC_RIGHT,       ________,       ________,
    ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
    ________,       ________,        ________,       ________,      ________,       /*-------------*/               /**/            /*-------------*/               ________,       ________,       ________,       ________,       ________,
    //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
    /*---------------------------------------------------------------------------*/ ________,       ________,       /**/            ________,       ________,
    /*-------------------------------------------------------------------------------------------*/ ________,       /**/            ________,       /***************/
    /*-----------------------------------------------------------*/ ________,       ________,       ________,       /**/            ________,       ________,         ________),



  // TODO
  // move new mouse into here
  [_POINT] = LAYOUT_ergodox_pretty(//-|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       MGRID,          MGRID,          MGRID,          MGRID,          TO(_BASE),
      xxxxxxxx,       PDIR9,          PDIR10,         PDIR11,         PDIR12,         KC_MS_BTN5,     xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       PVEL12,         PVEL10,         PVEL11,         PVEL12,         xxxxxxxx,
      xxxxxxxx,       PDIR5,          PDIR6,          PDIR7,          PDIR8,          TO(_BASE),      /**/            /**/            /**/            TO(_BASE),      PVEL5,          PVEL6,          PVEL7,          PVEL8,          xxxxxxxx,
      xxxxxxxx,       PDIR1,          PDIR2,          PDIR3,          PDIR4,          KC_MS_BTN3,     xxxxxxxx,       /**/            KC_MS_BTN4,     KC_MS_BTN5,     PVEL1,          PVEL2,          PVEL3,          PVEL4,          xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       KC_MS_BTN1,                                     /**/                                            KC_MS_BTN2,     xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,
      /*-----------------------------------------------------------*/ oooooooo,       oooooooo,       oooooooo,       /**/            oooooooo,       oooooooo,      oooooooo),


  /**
   * FUNCTION_LAYER ------------------------------------------------ FUNCTION_LAYER ----------------------------------------------- FUCNTION_LAYER --------------------------------------------------------------- FUNCTION_LAYER ----------------
   */

  [_FUN] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(0),
      xxxxxxxx,       KC_F9,          KC_F10,         KC_F11,         KC_F12,         xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_F21,         KC_F22,         KC_F23,         KC_F24,         xxxxxxxx,
      xxxxxxxx,       KC_F5,          KC_F6,          KC_F7,          CMD_T(KC_F8),   xxxxxxxx,       /**/            /**/            /**/            xxxxxxxx,       CMD_T(KC_F17),  KC_F18,         KC_F19,         KC_F20,         xxxxxxxx,
      xxxxxxxx,       CTL_T(KC_F1),   SFT_T(KC_F2),   KC_F3,          KC_F4,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_F13,         KC_F14,         SFT_T(KC_F15),  CTL_T(KC_F16),  xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(0),
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,
      /*-----------------------------------------------------------*/ KC_LALT,        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_RALT),


#if defined(MIDI_ENABLE) && defined(MIDI_ADVANCED)
  [_MIDI] = LAYOUT_ergodox_pretty(//---|--------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       /**/            /**/            /**/            ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       ________,       ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
      ________,       ________,        ________,       ________,      ________,       /*-------------*/               /**/            /*-------------*/               ________,       ________,       ________,       ________,       ________,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ ________,       ________,       /**/            ________,       ________,
      /*-------------------------------------------------------------------------------------------*/ ________,       /**/            ________,       /***************/
      /*-----------------------------------------------------------*/ ________,       ________,       ________,       /**/            ________,       ________,         ________),
#endif

  /**
   * MOUSE TESTING
   */

  [_TEST] = LAYOUT_ergodox_pretty(//------------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            RESET,          xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BASE),
      xxxxxxxx,       PDIR9,          PDIR10,         PDIR11,         PDIR12,         xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       PVEL12,         PVEL10,         PVEL11,         PVEL12,           xxxxxxxx,
      KC_ESC,         PDIR5,          PDIR6,          PDIR7,          PDIR8,          xxxxxxxx,       /**/            /**/            /**/            xxxxxxxx,       PVEL5,          PVEL6,          PVEL7,          PVEL8,           xxxxxxxx,
      xxxxxxxx,       PDIR1,          PDIR2,          PDIR3,          PDIR4,          xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       PVEL1,          PVEL2,          PVEL3,          PVEL4,           xxxxxxxx,
      xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
      //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
      /*---------------------------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
      /*-------------------------------------------------------------------------------------------*/ xxxxxxxx,       /**/            xxxxxxxx,
      /*-----------------------------------------------------------*/ xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx),
};

// VARIABLES ----------------------------------------
rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

// 0  continuous L/R dir/vel
// 1  sequential mode
int pmode = 0; // pointer mode // use enum here as well, as I do w/layer name integers


// pmode 0
int last_pressed_dir_key = 0;
int last_pressed_vel_key = 0;
int last_pressed_pointer_key = 0;
uint16_t timestamp_prev_move_cont = 0;
uint8_t cont_move_step_time_interval = 15; // millisec update interval

// pmode 1
int stateMouseSequence = 0; // 0 = enter; 1 = mag; 2 = set dirA; 3 = set dirB

// pmode 1
int magA = 0;
int magB = 0;
int dirA = 0; // rename to sequential
int dirB = 0; // ...

int dirStepsTot = 0;
float angleStep = 2.5; // only perstains to sequential mode??
float rad = PI / 180;
float shift = - PI / 3;

int currMag = 0;
int currX = 0;
int currY = 0;

int prevMag = 0;
int prevX = 0;
int prevY = 0;

/* void dance_mousemode_finished (qk_tap_dance_state_t *state, void *user_data) { */
/*     mouseMode = state->count; */
/*     reset_pointer(); */
/* } */
/*  */
/* void dance_esc_lco (qk_tap_dance_state_t *state, void *user_data) { */
/*     if (state->count == 1) { */
/*         register_code (KC_ESC); */
/*         unregister_code (KC_ESC); */
/*     } else { */
/*         // set layer left compl */
/*         layer_move(_LCO); */
/*     } */
/* } */
/* void dance_quote_rco (qk_tap_dance_state_t *state, void *user_data) { */
/*     if (state->count == 1) { */
/*         register_code (KC_QUOTE); */
/*         unregister_code (KC_QUOTE); */
/*     } else { */
/*         // set layer right comp */
/*         layer_move(_RCO); */
/*     } */
/* } */
/*  */
/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*     [TD_MMODE] = ACTION_TAP_DANCE_FN (dance_mousemode_finished), */
/*     [TD_ESC_LCO]   = ACTION_TAP_DANCE_FN (dance_esc_lco), */
/*     [TD_QUOTE_RCO] = ACTION_TAP_DANCE_FN (dance_quote_rco), */
/* }; */

void set_mag_curr(void){
  currMag = ((magA * magB) < 128) ? (magA * magB) : 127;
  /* #ifdef CONSOLE_ENABLE */
  /*   uprintf("currMag: %u\n\n", currMag); */
  /* #endif */
}




/*
 *
 * radians
 * apply clock shift
 */
void set_dir_curr(int twelve_stepts){
  if (pmode == 0 ) {
    float trig = (twelve_stepts-1) * 30 * rad; // 12 * degrees * rad
    currX = round(currMag * cos(trig + shift));
    currY = round(currMag * sin(trig + shift));
  }

  if (pmode == 1) {
    dirStepsTot = 12 * (dirA-1) + (dirB-1);
    float trig = dirStepsTot * angleStep * rad;
    currX = round(currMag * cos(trig + shift));
    currY = round(currMag * sin(trig + shift));
  }
  /* #ifdef CONSOLE_ENABLE */
  /*   uprintf("currX: %u, currY: %u\n\n", currX, currY); */
  /* #endif */
}
void update_pointer(void){
  report_mouse_t report = pointing_device_get_report();
  report.x = currX;
  report.y = currY;
  pointing_device_set_report(report);
  pointing_device_send();
  prevMag = currMag;
  prevX = currX;
  prevY = currY;
}
void repeat_last_move(int rev) {
  report_mouse_t report = pointing_device_get_report();
  if (rev) {
    report.x = prevX;
    report.y = prevY;
  } else {
    report.x = -prevX;
    report.y = -prevY;
  }
  pointing_device_set_report(report);
  pointing_device_send();
  stateMouseSequence = 1;
}


/*
 *  why is the arg called gridStep?
 *
 *  it doesnt really make sense the name now that ri have a different mouse mode
 *
 *  ˚
 */
void set_move_components(int gridStep) {
  // cont mode
  if (pmode == 0) {
    set_dir_curr(gridStep);
  }
  // discrete mode sequences
  // wrap in mode==?
  if (pmode == 1) {
    if ( stateMouseSequence == 0 || stateMouseSequence == 1 ) {
      magA = gridStep;
      stateMouseSequence = 2;
    } else if ( stateMouseSequence == 2 ) {
      magB = gridStep;
      set_mag_curr();
      stateMouseSequence = 3;
    } else if ( stateMouseSequence == 3 ) {
      dirA = gridStep;
      stateMouseSequence = 4;
    } else if ( stateMouseSequence == 4 ) {
      dirB = gridStep;
      set_dir_curr(gridStep);
      update_pointer();
      stateMouseSequence = 1;
    }
  }
}


/*
 *  todo
 *
 *    MGRID should actually be handled as a grid function.
 *
 */

void handle_mgrid(uint16_t keycode, keyrecord_t *record) { /////////////////////////////////////////////////
  // this is simple but it should work i think
  /* if (pmode == 0){ */
  /*   #<{(| if ( keycode inside PDIR1...12 ) {} |)}># */
  /*   if (record->event.pressed) { */
  /*     // receive pdir value here */
  /*     set_move_components(keycode); // should be mapped enum to degree value */
  /*  */
  /*     last_pressed_dir_key = keycode; */
  /*     // TODO */
  /*     //    set move components from here. what arguments? */
  /*   } else { */
  /*     if (last_pressed_dir_key == keycode) { */
  /*       last_pressed_dir_key = 0; */
  /*     } */
  /*   } */
  /*   #<{(| if ( keycode inside PVEL1...12 ) {} |)}># */
  /*  */
  /*  */
  /* } */


  // old / vim sequential mode

  if (record->event.pressed && pmode == 1) {
    if (record->event.key.col == 1) {
      switch (record->event.key.row) {
        case 1: set_move_components(9);  break;
        case 2: set_move_components(10); break;
        case 3: set_move_components(11); break;
        case 4: set_move_components(12); break;
      }
    } else if (record->event.key.col == 2) {
      switch (record->event.key.row) {
        case 1: set_move_components(5); break;
        case 2: set_move_components(6); break;
        case 3: set_move_components(7); break;
        case 4: set_move_components(8); break;
      }
    } else if (record->event.key.col == 3) {
      switch (record->event.key.row) {
        case 1: set_move_components(1); break;
        case 2: set_move_components(2); break;
        case 3: set_move_components(3); break;
        case 4: set_move_components(4); break;
      }
    }
  }
}
void handle_right_hand(uint16_t keycode, keyrecord_t *record) { /////////////////////////////////////////////////
  // TODO
  //
  //  - set current magnitude

  /* if (pmode == 0) { */
  /*   if (record->event.pressed) { */
  /*     // set curr */
  /*     currMag = keycode; */
  /*  */
  /*     last_pressed_vel_key = keycode; */
  /*   } else { */
  /*     if (last_pressed_vel_key == keycode) { */
  /*       last_pressed_vel_key = 0; */
  /*     } */
  /*   } */
  /* } */

  /* void handle_mvim_grid_event(keyrecord_t *record) { */
  /*     switch (mouseMode) { */
  /*         case 1: */
  /*             mouse_mode_basic(record); */
  /*             // set continuous mode */
  /*             break; */
  /*         case 2: */
  /*             mouse_mode_basic_discrete(record); */
  /*             // set discrete mode */
  /*             break; */
  /*     } */
}

void handle_pointer_keycodes(uint16_t keycode, keyrecord_t *record){
  if (pmode == 0){
    int pk = keycode - PDIR1 + 1; // pointer key normalized
    if ( 1 <= pk && pk <= 12 ) { // DIRECTION -----------------------------------------
      if (record->event.pressed) {

#ifdef CONSOLE_ENABLE
        uprintf("keycode: %u\n\n", pk);
#endif
        set_move_components(pk); // should be mapped enum to degree value
        last_pressed_dir_key = keycode;

        // release -------------------------------
      } else {
        if (last_pressed_dir_key == keycode) {
          last_pressed_dir_key = 0;
        }
      }

    }
    if ( 13 <= pk && pk <= 24 ) { // VELOCITY ------------------------------------------
      if (record->event.pressed) {
        // mag is unsigned right???
#ifdef CONSOLE_ENABLE
        uprintf("keycode: %u\n\n", pk);
#endif
        currMag = pk - 12; // last num is sensitivity scalar
        last_pressed_vel_key = keycode;

      } else {
        if (last_pressed_vel_key == keycode) {
          last_pressed_vel_key = 0;
        }
      }
    }

    last_pressed_pointer_key = keycode;
  }
}

/*
 *
 * loop that updates the pointer. runs all the time.
 * only it true will the pointer update.
 *
 */
void pointing_device_task(void) {
  report_mouse_t report = pointing_device_get_report();

  if (timer_elapsed(timestamp_prev_move_cont) > cont_move_step_time_interval
      && last_pressed_dir_key > 0
      && last_pressed_vel_key > 0
     ) {
    timestamp_prev_move_cont = timer_read();
    report.x = currX;
    report.y =  currY;
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
    case MGRID:
      handle_mgrid(keycode, record);
      break;
    case MRESET:
      stateMouseSequence = 0;
      break;
    case MREPEAT:
      if (record->event.pressed) {
        repeat_last_move(1);
      }
      break;
    case MREPEAT_REV:
      if (record->event.pressed) {
        repeat_last_move(0);
      }
      break;


      // pointer handling --------------------------------------

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
        stateMouseSequence = 0;
        rgblight_sethsv_noeeprom(10,90,40);
        break;
      case _FUN:
        rgblight_sethsv_noeeprom(70,0,50);
        break;
      case _TEST:
        stateMouseSequence = 0;
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
