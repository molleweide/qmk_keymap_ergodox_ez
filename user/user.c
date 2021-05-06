/*
 * todo
 *
 *  add case if mode = _base && both thumb keys held down at the same time.
 *  tmuxThumb_L, tmuxThumb_R
 *
 * case thumbs
 *
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    /* case KC_ESC: */
    /*   POINTER_DIR_STATE = 0; */
    /*   if (record->event.pressed) { */
    /*     register_code(KC_ESC); */
    /*   } else { */
    /*     unregister_code(KC_ESC); */
    /*   } */
    /*   break; */
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;

    /* case BTL_INNER ... BTR_INNER: */
    /*   inner_thumbs(keycode, record#<{(|, INNER_THUMB_IS_DOWN, _POINT|)}>#); */

    case BTL_OUTER ... BTR_OUTER:
      outer_thumbs(keycode, record/*, INNER_THUMB_IS_DOWN, _POINT*/);

    case PDIR1 ... PVEL_LS:
      // first P direction ... last p velocity
      handle_pointer_keycodes(keycode, record);
      return false; // this shouldn't do anything
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
        rgblight_sethsv_noeeprom(0,252,100);
        break;
      case _SYMB:
        rgblight_sethsv_noeeprom(0,240,100);
        break;
      case _MOVE:
        rgblight_sethsv_noeeprom(90,230,40);
        break;
      case _POINT:
        rgblight_sethsv_noeeprom(150,10,20);
        break;
      case _FUN:
        rgblight_sethsv_noeeprom(170,230,20);
        break;
      case _MIDI:
        rgblight_sethsv_noeeprom(240,240,60);
        break;
      case _TEST:
        rgblight_sethsv_noeeprom(10,180,70);
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
