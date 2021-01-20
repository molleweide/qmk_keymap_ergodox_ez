#include QMK_KEYBOARD_H

#include <math.h>
#include "pointing_device.h"

#include "keycodes/alias_definitions.c"
#include "keycodes/custom_keycodes.c"
#include "layers/layer_definitions.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#include "layers/base.h"
#include "layers/symbols.h"
#include "layers/move.h"
#include "layers/point.h"
#include "layers/func.h"
#include "layers/midi.h"
#include "layers/test.h"
};

#include "custom/custom_functions.c"
#include "user/user.c"
