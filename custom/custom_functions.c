// VARIABLES ----------------------------------------
rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool LAYER_JUST_CHANGED = true;

int POINTER_DIR_COUNT =  PDIR_LAST - PDIR1 + 1;
// since I am now using variable vel keycodes, not linear, i should rename it to pointer_vel_max??;
int POINTER_VEL_COUNT =  PVEL_LAST - PVEL1 + 1;

int last_pressed_dir_key = 0;
int last_pressed_vel_key = 0;

int POINTER_CURR_DIR = 0;
int POINTER_V = 0;
int POINTER_X = 0;
int POINTER_Y = 0;

float rad = PI / 180;
float CLOCK_SHIFT = - PI / 3; // 0 == 12 o'clock ?

int POINTER_UPDATE_INTERVAL = 15; // milliseconds
uint16_t TIMESTAMP_PREV_POINTER = 0; // change to regular int??????

bool INNER_THUMB_IS_DOWN = false;
bool OUTER_THUMB_IS_DOWN = false;


// why does it output wrong dirs when

void update_pointer_xy(int dummy){
  float direction_in_radians = POINTER_CURR_DIR * 360/POINTER_DIR_COUNT * rad; // replace 30 by 360/POINTER_DIR_COUNT
  POINTER_X = round(POINTER_V * cos(direction_in_radians + CLOCK_SHIFT));
  POINTER_Y = round(POINTER_V * sin(direction_in_radians + CLOCK_SHIFT));
}

// TODO
//   add and not = prev keycode!!!

void handle_pointer_keycodes(uint16_t keycode, keyrecord_t *record){
  int pk = keycode - PDIR1 + 1; // important !!! but does this work when I have non linear variuables??
  if ( 1 <= pk && pk <= POINTER_DIR_COUNT ) { // poin
    if (record->event.pressed) {
      POINTER_CURR_DIR = pk; last_pressed_dir_key = keycode;
      update_pointer_xy(1);
    } else {
      if (last_pressed_dir_key == keycode) {
        last_pressed_dir_key = 0;
      }
    }
  }
  if ( POINTER_DIR_COUNT < pk && pk <= POINTER_DIR_COUNT + POINTER_VEL_COUNT ) {
    if (record->event.pressed) {
      POINTER_V = pk - POINTER_DIR_COUNT; last_pressed_vel_key = keycode;
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
