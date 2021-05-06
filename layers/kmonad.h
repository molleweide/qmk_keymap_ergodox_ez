[_BASE] = LAYOUT_ergodox_pretty(
    TO_TEST,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,
    xxxxxxx,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   xxxxxxx,xxxxxxx,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   xxxxxxx,
    xxxxxxx,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   /*------------*/KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,xxxxxxx,
    xxxxxxx,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   xxxxxxx,xxxxxxx,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,xxxxxxx,
    xxxxxxx,xxxxxxx,xxxxxxx,KC_TAB, KC_SPC, /*----------------------------*/KC_SPC, KC_RET, xxxxxxx,xxxxxxx,xxxxxxx,
    /*-----------------------------------*/ KCMUTE, xxxxxxx,xxxxxxx,xxxxxxx,
    /*-------------------------------------------*/ xxxxxxx,xxxxxxx,
    /*-------------------------*/ BTL_OUTER,KCVOLU, xxxxxxx,xxxxxxx,KCVOLD,BTR_OUTER),

[_MIDI] = LAYOUT_ergodox_pretty(
    xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,TO_BASE,
    xxxxxxx,NTE_020,NTE_021,NTE_022,NTE_023,NTE_024,xxxxxxx,xxxxxxx,NTE_025,NTE_026,NTE_027,NTE_028,NTE_029,xxxxxxx,
    xxxxxxx,NTE_010,NTE_011,NTE_012,NTE_013,NTE_014,/*------------*/NTE_015,NTE_016,NTE_017,NTE_018,NTE_019,xxxxxxx,
    xxxxxxx,NTE_000,NTE_001,NTE_002,NTE_003,NTE_004,xxxxxxx,xxxxxxx,NTE_005,NTE_006,NTE_007,NTE_008,NTE_009,xxxxxxx,
    xxxxxxx,xxxxxxx,xxxxxxx,KC_TAB, KC_SPC, /*----------------------------*/KC_SPC, KC_RET, xxxxxxx,xxxxxxx,xxxxxxx,
    /*-----------------------------------*/ xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-------------------------------------------*/ xxxxxxx,xxxxxxx,
    /*-------------------------*/ BTL_OUTER,BTL_OUTER,MI_ALLOFF,MI_ALLOFF,BTR_OUTER,BTR_OUTER),

[_POINT] = LAYOUT_ergodox_pretty(
    xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,TO_BASE,
    xxxxxxx,PDIR2,  PDIR3,  PDIR4,  PDIR1,  _______,xxxxxxx,xxxxxxx,KC_BTN3,KC_WHD, KC_WHU, KC_BTN4,KC_BTN5,xxxxxxx,
    KC_ESC, PDIR1,  PDIR2,  PDIR3,  PDIR4,  _______,/*------------*/_______,PVEL1,  PVEL2,  PVEL3,  PVEL_LS,xxxxxxx,
    xxxxxxx,PDIR4,  PDIR1,  PDIR2,  PDIR3,  _______,xxxxxxx,xxxxxxx,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,xxxxxxx,
    xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,KC_BTN1,/*----------------------------*/KC_BTN2,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-----------------------------------*/ xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-------------------------------------------*/ xxxxxxx,xxxxxxx,
    /*-------------------------*/ BTL_OUTER,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,BTR_OUTER),

    [_TEST] = LAYOUT_ergodox_pretty(
    xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,RESET,  xxxxxxx,xxxxxxx,TO_BASE,
    xxxxxxx,_______,_______,_______,_______,_______,xxxxxxx,xxxxxxx,_______,_______,_______,_______,_______,xxxxxxx,
    xxxxxxx,_______,_______,_______,_______,_______,/*------------*/_______,_______,_______,_______,_______,xxxxxxx,
    xxxxxxx,_______,_______,_______,_______,_______,xxxxxxx,xxxxxxx,_______,_______,_______,_______,_______,xxxxxxx,
    xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,/*----------------------------*/xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-----------------------------------*/ xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,
    /*-------------------------------------------*/ xxxxxxx,xxxxxxx,
    /*---------------------------*/ xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx,xxxxxxx),

