rgblight_config_t rgblight_config;
bool disable_layer_color = 0;

bool LAYER_JUST_CHANGED = true;

bool first_dir = true;

int POINTER_DIR_COUNT =  PDIR_LAST - PDIR1 + 1;
// since I am now using variable vel keycodes, not linear, i should rename it
// to pointer_vel_max??;
int POINTER_VEL_COUNT =  PVEL_LS - PVEL1 + 1;

int last_pressed_dir_key = 0;
int last_pressed_vel_key = 0;

int POINTER_CURR_DIR = 0;
int POINTER_V = 0;
int POINTER_X = 0;
int POINTER_Y = 0;

float rad = PI / 180;
float CLOCK_SHIFT = - PI / 3; // shift keys however I want

int POINTER_UPDATE_INTERVAL = 19; // milliseconds

uint16_t TIMESTAMP_PREV_POINTER = 0; // change to regular int??????

bool INNER_THUMB_IS_DOWN = false;
bool OUTER_THUMB_IS_DOWN = false;

bool POINTER_DIR_STATE = 0;

int POINTER_DIR_QUADRANT = 0;

int same_press_count = 0;

bool dir_is_down = false;

// release time before dir is reset.
//  allows one to be a bit sloppy when one is pressing
//  and releasing the keys.
uint16_t RESET_DIR_INTERVAL = 50;

uint16_t TIMESTAMP_RESET_DIR = 0;
