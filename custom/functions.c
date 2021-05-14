#include "variable_definitions.h"

void update_pointer_xy(int dummy){
  //float direction_in_radians = POINTER_CURR_DIR * 360/POINTER_DIR_COUNT * rad; // replace 30 by 360/POINTER_DIR_COUNT

  float direction_in_radians = ((POINTER_DIR_QUADRANT-1) * 90 + (POINTER_CURR_DIR - 1)*360/16 - 90) * rad;

  POINTER_X = round((POINTER_V+1) * cos(direction_in_radians)); // + CLOCK_SHIFT
  POINTER_Y = round((POINTER_V+1) * sin(direction_in_radians)); // + CLOCK_SHIFT

}

//   add and not = prev keycode!????
void set_pointer_dir_state(int pk) {
  if (POINTER_DIR_STATE == 0) {
    POINTER_DIR_QUADRANT = pk;
    POINTER_DIR_STATE = 1;
  } else {
    update_pointer_xy(1);
    POINTER_DIR_STATE = 0;
    first_dir = false;
  }

}

/* TIMESTAMP_PREV_POINTER = timer_read(); */
void handle_pointer_keycodes(uint16_t keycode, keyrecord_t *record){
  int pk = keycode - PDIR1 + 1; // important !!! but does this work when I have non linear variuables??

  if ( 1 <= pk && pk <= POINTER_DIR_COUNT ) {

    if (record->event.pressed) { // ----------- PRESS
      POINTER_CURR_DIR = pk;
      if (last_pressed_dir_key == keycode) same_press_count++;
      set_pointer_dir_state(pk);
      last_pressed_dir_key = keycode;
      dir_is_down = true;

    } else { // dir release ------------------------------------- RELEASE

      if (last_pressed_dir_key == keycode) { // ---- SAME
        if (same_press_count > 0) {
          same_press_count--;
        } else {
          // refactor >> reset_pointer_dir
          /* last_pressed_dir_key = 0; */
          /* POINTER_DIR_STATE = 0; */
          /* first_dir = true; */


          dir_is_down = false;
          TIMESTAMP_RESET_DIR = timer_read();

        }
      }
    }
  }



  // HANDLE VELOCITY
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

// are all the return statements necessary?
//
// 1. left midi
// 2. right pointer
// 3. double >> back to base
void custom_thumb_switch(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if (OUTER_THUMB_IS_DOWN) {
      // DOWN SECOND -----------------------------------
      if (IS_LAYER_ON(_BASE)) {
        if (keycode == TSW_L) { layer_move(_POINT); LAYER_JUST_CHANGED = true; return; } // left point
        if (keycode == TSW_R) { layer_move(_MIDI); LAYER_JUST_CHANGED = true; return; } // right midi
      }
      if (IS_LAYER_ON(_MIDI)) {
        if (keycode == TSW_L) { layer_move(_POINT); LAYER_JUST_CHANGED = true; return; } // left point
      }
      if (IS_LAYER_ON(_POINT)) {
        if (keycode == TSW_R) { layer_move(_MIDI); LAYER_JUST_CHANGED = true; return; } // right midi
      }
    } else {
      // DOWN FIRST -----------------------------------
      OUTER_THUMB_IS_DOWN = true; LAYER_JUST_CHANGED = false;
    }

  } else {
    // RELEASE //////////////////////////////////////////////////////
    OUTER_THUMB_IS_DOWN = false;

    if (IS_LAYER_ON(_BASE) && !LAYER_JUST_CHANGED) {
      if (keycode == TSW_L) { register_code(KC_BSPACE); unregister_code(KC_BSPACE); return; }
      if (keycode == TSW_R) { register_code(KC_TAB); unregister_code(KC_TAB); return; }
    }

    if (IS_LAYER_ON(_POINT) && !LAYER_JUST_CHANGED) {
      if (keycode == TSW_R) { layer_move(_BASE); LAYER_JUST_CHANGED = true; return; }
    }
    if (IS_LAYER_ON(_MIDI) && !LAYER_JUST_CHANGED) {
      if (keycode == TSW_L) { layer_move(_POINT); LAYER_JUST_CHANGED = true; return;
      }
      if (keycode == TSW_R) { layer_move(_BASE); LAYER_JUST_CHANGED = true; return; }
    }
  }
}

void pointing_device_task(void) {
  report_mouse_t report = pointing_device_get_report();

  if (!dir_is_down && timer_elapsed(TIMESTAMP_RESET_DIR) > RESET_DIR_INTERVAL) {
    last_pressed_dir_key = 0;
    POINTER_DIR_STATE = 0;
    first_dir = true;
  }

  if (timer_elapsed(TIMESTAMP_PREV_POINTER) > POINTER_UPDATE_INTERVAL
      && last_pressed_dir_key > 0
      && last_pressed_vel_key > 0
      && !first_dir
     ) {
    TIMESTAMP_PREV_POINTER = timer_read();
    report.x = POINTER_X;
    report.y =  POINTER_Y;
  }
  pointing_device_set_report(report);
  pointing_device_send();
}
