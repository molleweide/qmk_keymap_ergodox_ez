#include "variable_definitions.h"
// why does it output wrong dirs when

void update_pointer_xy(int dummy){
  float direction_in_radians = POINTER_CURR_DIR * 360/POINTER_DIR_COUNT * rad; // replace 30 by 360/POINTER_DIR_COUNT
  POINTER_X = round((POINTER_V+1) * cos(direction_in_radians + CLOCK_SHIFT));
  POINTER_Y = round((POINTER_V+1) * sin(direction_in_radians + CLOCK_SHIFT));
}

//   add and not = prev keycode!!!

void handle_pointer_keycodes(uint16_t keycode, keyrecord_t *record){
  int pk = keycode - PDIR1 + 1; // important !!! but does this work when I have non linear variuables??
  if ( 1 <= pk && pk <= POINTER_DIR_COUNT ) { // poin
    if (record->event.pressed) {
      POINTER_CURR_DIR = pk;
      last_pressed_dir_key = keycode;
      update_pointer_xy(1);
    } else {
      if (last_pressed_dir_key == keycode) {
        last_pressed_dir_key = 0;
      }
    }
  }
  if ( POINTER_DIR_COUNT < pk && pk <= POINTER_DIR_COUNT + POINTER_VEL_COUNT ) {
    if (record->event.pressed) {
      POINTER_V = pk - POINTER_DIR_COUNT;
      last_pressed_vel_key = keycode;
      update_pointer_xy(1);
    } else {
      if (last_pressed_vel_key == keycode) {
        last_pressed_vel_key = 0;
      }
    }
  }
}

void inner_thumbs(uint16_t keycode, keyrecord_t *record/*, check*/) {
  if (record->event.pressed) {

    // down second -----------------------------------
    if (INNER_THUMB_IS_DOWN) {
      if (IS_LAYER_ON(_BASE)) {
        layer_move(_POINT); LAYER_JUST_CHANGED = true; return;
      }
      if (IS_LAYER_ON(_POINT)) {
        layer_move(_BASE); LAYER_JUST_CHANGED = true; return;
      }

      // down first -----------------------------------
    } else {
      INNER_THUMB_IS_DOWN = true; LAYER_JUST_CHANGED = false;
    }

    // RELEASE //////////////////////////////////////////////////////

  } else {
    INNER_THUMB_IS_DOWN = false;
    if (IS_LAYER_ON(_BASE) && !LAYER_JUST_CHANGED) {
      if (keycode == BTL_INNER) {
        register_code(KC_SPACE); unregister_code(KC_SPACE); // I am not sure that I even need to unregister here???
      }
      if (keycode == BTR_INNER) {
        register_code(KC_ENTER); unregister_code(KC_ENTER);
      }
    }

  }
}

void outer_thumbs(uint16_t keycode, keyrecord_t *record/*, check*/) {
  if (record->event.pressed) {

    // down second -----------------------------------
    if (OUTER_THUMB_IS_DOWN) {
      if (IS_LAYER_ON(_BASE)) {
        layer_move(_MIDI); LAYER_JUST_CHANGED = true; return;
      }
      if (IS_LAYER_ON(_MIDI)) {
        layer_move(_BASE); LAYER_JUST_CHANGED = true; return;
      }

      // down first -----------------------------------
    } else {
      OUTER_THUMB_IS_DOWN = true; LAYER_JUST_CHANGED = false;
    }

    // RELEASE //////////////////////////////////////////////////////

  } else {
    OUTER_THUMB_IS_DOWN = false;
    if (IS_LAYER_ON(_BASE) && !LAYER_JUST_CHANGED) {
      if (keycode == BTL_OUTER) {
        register_code(KC_BSPACE); unregister_code(KC_BSPACE); // I am not sure that I even need to unregister here???
      }
      if (keycode == BTR_OUTER) {
        register_code(KC_TAB); unregister_code(KC_TAB);
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
