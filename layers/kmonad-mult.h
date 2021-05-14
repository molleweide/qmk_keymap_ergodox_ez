// copy over to kmo-single-layer.h
[_BASE] = LAYOUT_ergodox_pretty(
    TO_TEST,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   xxxxxxx,xxxxxxx,KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   xxxxxxx,
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   xxxxxxx,xxxxxxx,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
    KC_ESC, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   /*------------*/KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_RET,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   xxxxxxx,xxxxxxx,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_LSFT,
    xxxxxxx,KC_LCTL,KC_LALT,KC_LCMD,KC_SPC, /*----------------------------*/KC_SPC, KC_LCMD,KC_LALT,KC_LCTL,xxxxxxx,
    /*-----------------------------------*/ xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-------------------------------------------*/ xxxxxxx,xxxxxxx,
    /*---------------------------*/ TSW_L,  xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,TSW_R),


    // need to check this layer with reaper to make sure this
    // works.
    //
    // i can use any midi keys in this layer since these are not captured by
    // kmo.
[_MIDI] = LAYOUT_ergodox_pretty(
    xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,TO_BASE,
    xxxxxxx,NTE_020,NTE_021,NTE_022,NTE_023,NTE_024,xxxxxxx,xxxxxxx,NTE_025,NTE_026,NTE_027,NTE_028,NTE_029,xxxxxxx,
    xxxxxxx,NTE_010,NTE_011,NTE_012,NTE_013,NTE_014,/*------------*/NTE_015,NTE_016,NTE_017,NTE_018,NTE_019,xxxxxxx,
    xxxxxxx,NTE_000,NTE_001,NTE_002,NTE_003,NTE_004,xxxxxxx,xxxxxxx,NTE_005,NTE_006,NTE_007,NTE_008,NTE_009,xxxxxxx,
    xxxxxxx,xxxxxxx,xxxxxxx,_______,_______,/*----------------------------*/_______,_______,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-----------------------------------*/ xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-------------------------------------------*/ xxxxxxx,xxxxxxx,
    /*-------------------------*/   TSW_L,  MI_AOFF,xxxxxxx,xxxxxxx,MI_AOFF,TSW_R),

    // can I use any pointing device keycodes here??
[_POINT] = LAYOUT_ergodox_pretty(
    xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,TO_BASE,
    xxxxxxx,PDIR2,  PDIR3,  PDIR4,  PDIR1,  _______,xxxxxxx,xxxxxxx,KC_BTN3,KC_WHD, KC_WHU, KC_BTN4,KC_BTN5,xxxxxxx,
    KC_ESC, PDIR1,  PDIR2,  PDIR3,  PDIR4,  _______,/*-----------*/ _______,PVEL1,  PVEL2,  PVEL3,  PVEL_LS,xxxxxxx,
    xxxxxxx,PDIR4,  PDIR1,  PDIR2,  PDIR3,  _______,xxxxxxx,xxxxxxx,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,xxxxxxx,
    xxxxxxx,xxxxxxx,xxxxxxx,_______,KC_BTN1,/*----------------------------*/KC_BTN2,_______,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-----------------------------------*/ xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-------------------------------------------*/ xxxxxxx,xxxxxxx,
    /*---------------------------*/ TSW_L,  xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,TSW_R),

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

[_TEST] = LAYOUT_ergodox_pretty(
    xxxxxxx,xxxxxxx,xxxxxxx,RESET  ,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,RESET  ,xxxxxxx,xxxxxxx,TO_BASE,
    xxxxxxx,_______,_______,_______,_______,_______,xxxxxxx,xxxxxxx,_______,_______,_______,_______,_______,xxxxxxx,
    xxxxxxx,_______,_______,_______,_______,_______,/*------------*/_______,_______,_______,_______,_______,xxxxxxx,
    xxxxxxx,_______,_______,_______,_______,_______,xxxxxxx,xxxxxxx,_______,_______,_______,_______,_______,xxxxxxx,
    xxxxxxx,xxxxxxx,xxxxxxx,_______,_______,/*----------------------------*/_______,_______,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-----------------------------------*/ xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-------------------------------------------*/ xxxxxxx,xxxxxxx,
    /*---------------------------*/ xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx),
