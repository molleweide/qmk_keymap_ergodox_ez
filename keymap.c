#include QMK_KEYBOARD_H

//#ifdef CONSOLE_ENABLE
//  uprintf("xxx: %u, yyy: %u\n\n", xxx, yyy);
//#endif

#include <math.h>
#include "pointing_device.h"

//#define KC_MAC_UNDO LGUI(KC_Z)
//#define KC_MAC_CUT LGUI(KC_X)
//#define KC_MAC_COPY LGUI(KC_C)
//#define KC_MAC_PASTE LGUI(KC_V)
//#define KC_PC_UNDO LCTL(KC_Z)
//#define KC_PC_CUT LCTL(KC_X)
//#define KC_PC_COPY LCTL(KC_C)
//#define KC_PC_PASTE LCTL(KC_V)
//#define ES_LESS_MAC KC_GRAVE
//#define ES_GRTR_MAC LSFT(KC_GRAVE)
//#define ES_BSLS_MAC ALGR(KC_6)
//#define NO_PIPE_ALT KC_GRAVE
//#define NO_BSLS_ALT KC_EQUAL

//////////////////////////////////////
// my custom keynames
////////////////////////////////////////

#define KC_SPC      KC_SPACE
#define KC_BSPC     KC_BSPACE
#define KC_ENT      KC_ENTER
#define KC_SLSH     KC_SLASH
#define KC_BSLSH    KC_BSLASH
#define KC_SCOL     KC_SCOLON
#define KC_COM      KC_COMMA

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

#define KC_MACC0    KC_MS_ACCEL0
#define KC_MACC1    KC_MS_ACCEL1
#define KC_MACC2    KC_MS_ACCEL2

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

// tap dance functions rename
#define TD_LMV      ACTION_TAP_DANCE_LAYER_MOVE


enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  MOVE_U,
  MOVE_D,
  MOVE_L,
  MOVE_R,
  MOVE_OFF,
  MGRID,
  PFREEZE,
  SET_MS_STATE,
};

enum layer_names {
    _BAS = 0,

    _LSY,
    _RNU,

    _LMS,
    _RMS,

    _FUN,

    _MS_TEST, // this is where I do my mouse testing
};

enum tapdance_keycodes {
    TD_MMODE,       // switch mouse mode
    //TD_ESC_LCO,    // esc or move to L mouse complement
    TD_QUOTE_RCO,  // esc or move to R mouse complement
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /**
     * BASE ----------------------------------------
     */

    [_BAS] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        TO(_MS_TEST),   KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           WEBUSB,         /**/            xxxxxxxx,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRNS,
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRNS,        /**/            KC_TRNS,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLSH,
        KC_ESC,         CTL_T(KC_A),    SFT_T(KC_S),    ALT_T(KC_D),    CMD_T(KC_F),    KC_G,           /**/            /**/            /**/            KC_H,           CMD_T(KC_J),    ALT_T(KC_K),    SFT_T(KC_L),    CTL_T(KC_SCOL), KC_QUOTE,
        xxxxxxxx,       LT(_RMS,KC_Z),  LT(_RNU,KC_X),  LT(_FUN,KC_C),  KC_V,           KC_B,           KC_TRNS,        /**/            KC_TRNS,        KC_N,           KC_M,           LT(_FUN,KC_COM),LT(_LSY,KC_DOT),LT(_LMS,KC_SLSH),xxxxxxxx,
        KC_GRAVE,       CTL_T(KC_LEFT), KC_DOWN,        KC_UP,          KC_RGHT,        /*-------------*/               /**/            /*-------------*/               KC_LEFT,        KC_DOWN,        KC_UP,          CTL_T(KC_RGHT), xxxxxxxx,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
                                                                        /***************/               xxxxxxxx,       /**/            xxxxxxxx,       /***************/
                                                                        LSFT_T(KC_SPC), KC_BSPC,        KC_TRNS,        /**/            KC_TRNS,        KC_TAB,         RSFT_T(KC_ENT)),

    /**
     * SYMBOLS / NUMBERS ---------------------------
     */

    [_LSY] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        ________,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       TO(_BAS),
        ________,       KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
        ________,       KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                       /**/                            ________,       ________,       ________,       ________,       ________,       ________,
        KC_AMPR,        KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        ________,       /**/            ________,       ________,       ________,       ________,       ________,       ________,       ________,
        ________,       ________,       ________,       ________,       ________,       /***************/               /**/            /***************/               ________,       ________,       ________,       ________,       ________,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        ________,       ________,       /**/            ________,      ________,
                                                                                                        ________,       /**/            ________,
                                                                        ________,       ________,       ________,       /**/            ________,      ________,        ________),

    [_RNU] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       /**/            oooooooo,       KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         TO(_BAS),
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       /**/            oooooooo,       oooooooo,       KC_7,           KC_8,           KC_9,           KC_EQUAL,       KC_F12,
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       /**/            /**/            /**/            KC_0,           KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_KP_SLASH,
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       /**/            oooooooo,       KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_MINUS,       KC_UNDS,
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,                                       /**/                                            KC_LPRN,        oooooooo,       oooooooo,       KC_RPRN,        oooooooo,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        oooooooo,       oooooooo,       /**/            oooooooo,       oooooooo,
                                                                                                        oooooooo,       /**/            oooooooo,
                                                                        oooooooo,       oooooooo,       oooooooo,       /**/            oooooooo,       oooooooo,       oooooooo),

    /**
     * MOUSE_LEFT_AND_RIGHT ------------------------------------------- MOUSE_LEFT_AND_RIGHT ------------------------------------------ MOUSE_LEFT_AND_RIGHT ---------------------------------------------------------- MOUSE_LEFT_AND_RIGHT -----------
     */

    [_LMS] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       KC_AU_M,        oooooooo,       /**/            oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       TO(_BAS),
        oooooooo,       KC_MWHL,        KC_MWHD,        KC_MWHU,        KC_MWHR,        oooooooo,       KC_AU_U,        /**/            oooooooo,       KC_RGUI,        KC_RALT,        KC_RSHIFT,      KC_RCTRL,       oooooooo,       oooooooo,
        oooooooo,       KC_ML,          KC_MD,          KC_MU,          KC_MR,          oooooooo,       /**/            /**/            /**/            oooooooo,       KC_MACC2,       KC_MACC1,       KC_MACC0,       oooooooo,       oooooooo,
        oooooooo,       KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        oooooooo,       KC_AU_D,        /**/            oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,
        oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,                                       /**/                                            oooooooo,       oooooooo,       oooooooo,       oooooooo,       oooooooo,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        oooooooo,       oooooooo,       /**/            oooooooo,       oooooooo,
                                                                                                        oooooooo,       /**/            oooooooo,
                                                                        KC_MS_BTN3,     KC_MS_BTN4,     KC_MS_BTN5,     /**/            oooooooo,       KC_MS_BTN2,     KC_MS_BTN1),

    [_RMS] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_AU_M,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_AU_U,        KC_MS_WH_UP,    KC_TRNS,        KC_MS_UP,       KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_MACC0,       KC_MACC1,       KC_MACC2,       KC_TRNS,                        /**/                            KC_TRNS,        KC_ML,          KC_MD,          KC_MU,          KC_MR,          KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_AU_D,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        /**/                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,        /**/            KC_TRNS,
                                                                        KC_MS_BTN1,     KC_MS_BTN2,     KC_TRNS,        /**/            KC_MS_BTN5,     KC_MS_BTN4,     KC_MS_BTN3),


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
                                                                                        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
                                                                        /***************/               xxxxxxxx,       /**/            xxxxxxxx,       /***************/
                                                                        KC_LALT,        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       KC_RALT),


    /**
     * MOUSE TESTING
     */

    [_MS_TEST] = LAYOUT_ergodox_pretty(//---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       TO(_BAS),
        xxxxxxxx,       MGRID,          MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        KC_ESC,         MGRID,          MGRID,          MGRID,          MGRID,          MGRID,          /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        TD(TD_MMODE),   MGRID,          MGRID,          MGRID,          MGRID,          MGRID,          xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       /**/            /**/            /**/            /**/            /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,       xxxxxxxx,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        xxxxxxxx,       xxxxxxxx,       /**/            xxxxxxxx,       xxxxxxxx,
                                                                        /***************/               xxxxxxxx,       /**/            xxxxxxxx,       /***************/
                                                                        KC_MS_BTN1,     KC_MS_BTN2,     MOVE_OFF,       /**/            xxxxxxxx,       xxxxxxxx,       xxxxxxxx),
};

// VARIABLES ----------------------------------------
rgblight_config_t rgblight_config;
bool disable_layer_color = 0;



void reset_pointer(void) {
#ifdef CONSOLE_ENABLE
    uprintf("reset pointer\n");
#endif
}

uint8_t someVar = 1;
void dance_mousemode_finished (qk_tap_dance_state_t *state, void *user_data) {
    someVar  = state->count;
    reset_pointer();
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MMODE] = ACTION_TAP_DANCE_FN (dance_mousemode_finished),
};



// DISCRETE MOUSE ---------------------------------------------------------------
//  - reset state
//  - mouse hook
//  - regular mouse button
//  - create 3-step
#define PI 3.14159265
uint8_t mouseState = 0; // 0 = set magnitude; 1 = set direction; 2 = enter layer
int mag = 0;
double rad = PI / 180;

void set_mag_deg(int m, int d){
  if (mouseState == 0 || mouseState == 2) {
    mag = m; mouseState = 1;
  } else {
    report_mouse_t report = pointing_device_get_report();
    report.x = round(mag * cos(d * rad));
    report.y = round(mag * sin(d * rad));
    pointing_device_set_report(report);
    pointing_device_send();
    mouseState = 0;
  }
}

void mouse_keys(keyrecord_t *record) { /////////////////////////////////////////////////
  if (record->event.pressed) { // key pressed
    if (record->event.key.col == 3) {
      switch (record->event.key.row) {
        case 1: set_mag_deg(5,  0); break;
        case 2: set_mag_deg(10, 30); break;
        case 3: set_mag_deg(15, 60); break;
        case 4: set_mag_deg(20, 90); break;
      }
    }
    if (record->event.key.col == 2) {
      switch (record->event.key.row) {
        case 1: set_mag_deg(25, 120); break;
        case 2: set_mag_deg(30, 150); break;
        case 3: set_mag_deg(35, 180); break;
        case 4: set_mag_deg(40, 210); break;
      }
    }
    if (record->event.key.col == 1) {
      switch (record->event.key.row) {
        case 1: set_mag_deg(45, 240); break;
        case 2: set_mag_deg(50, 270); break;
        case 3: set_mag_deg(55, 300); break;
        case 4: set_mag_deg(60, 330); break;
      }
    }
  }
} /////////////////////////////////////////////////////////////////////////////////////////////////////



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
            mouse_keys(record);
            break;
    }
    return true;
}


//uint8_t moveDirection = 0;
//uint8_t cursorTimeout = 10;
//uint16_t lastCursor = 0;
//void pointing_device_task(void) {
//    report_mouse_t report = pointing_device_get_report();
//    if (timer_elapsed(lastCursor) > cursorTimeout && moveToggle) {
//        lastCursor = timer_read();
//        switch (moveDirection) {
//            case 0:
//                report.x = -contMagnitude; // replace the integer with contMagnitude
//                break;
//            case 1:
//                report.y = contMagnitude;
//                break;
//            case 2:
//                report.y = -contMagnitude;
//                break;
//            case 3:
//                report.x = contMagnitude;
//                break;
//        }
//    }
//    pointing_device_set_report(report);
//    pointing_device_send();
//}

uint32_t layer_state_set_user(uint32_t state) {

  // todo
  //
  //  - reset >>> mouseState = 2
  //  - in set_mag_deg
  //    add new check for 2 when coming back

    uint8_t layer = biton32(state);

    if (layer == _MS_TEST) {
      mouseState = 2;
    }

#ifdef CONSOLE_ENABLE
  uprintf("_MS_TEST: %u, layer: %u, ms: %u \n\n", _MS_TEST, layer, mouseState);
#endif

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

// why do I have this function here???
void keyboard_post_init_user(void) {
    // Customise these values to desired behave
    // debug_enable=true; // keyboard becomes very slow when using this or next setting; why??
    // debug_matrix=true; // this makes keyb very slow!!!
    // debug_keyboard=true;
    // debug_mouse=true;

    layer_state_set_user(layer_state);
}















