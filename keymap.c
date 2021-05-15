#include QMK_KEYBOARD_H
#include <math.h>
#include "pointing_device.h"

// personal below
#include "keycodes/alias_definitions.c"
#include "keycodes/custom_keycodes.c"
#include "layers/layer_definitions.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#include "layers/kmonad.h"
};

#include "custom/variable_definitions.h"
#include "custom/functions.c"
#include "user/user.c"
