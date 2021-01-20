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
float CLOCK_SHIFT = - PI / 3; // shift keys however I want

int POINTER_UPDATE_INTERVAL = 20; // milliseconds
uint16_t TIMESTAMP_PREV_POINTER = 0; // change to regular int??????

bool INNER_THUMB_IS_DOWN = false;
bool OUTER_THUMB_IS_DOWN = false;
