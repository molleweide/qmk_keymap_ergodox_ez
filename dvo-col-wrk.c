    /**
     * Dvorak, Colemak, and Workman ----------------
     *     these layouts SHOULD BE superimposed nicely on top of the baselayer
     */

    [_DVO] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
        KC_TRNS,        KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_TRNS,        /**/            KC_TRNS,        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_TRNS,
        KC_TRNS,        KC_A,           KC_O,           KC_E,           KC_U,          KC_I,                           /**/                            KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_TRNS,
        KC_TRNS,        KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,           KC_TRNS,        /**/            KC_TRNS,        KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        /**/                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,        /**/            KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,        KC_TRNS),

    [_COL] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
        KC_TRNS,        KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRNS,        /**/            KC_TRNS,        KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_TRNS,
        KC_TRNS,        KC_A,           KC_R,           KC_S,           KC_T,           KC_G,                           /**/                            KC_K,           KC_N,           KC_E,           KC_I,           KC_O,           KC_TRNS,
        KC_TRNS,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_TRNS,        /**/            KC_TRNS,        KC_M,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLSH,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        /**/                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,        /**/            KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,        KC_TRNS),

    [_WRK] = LAYOUT_ergodox_pretty(//---|---------------|---------------X---------------|---------------$---------------/**/------------$---------------|---------------X---------------|---------------|---------------|---------------|---------------
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TO(_BAS),
        KC_TRNS,        KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,           KC_TRNS,        /**/            KC_TRNS,        KC_J,           KC_F,           KC_U,           KC_P,           KC_SLSH,       KC_TRNS,
        KC_TRNS,        KC_A,           KC_S,           KC_H,           KC_T,           KC_G,                           /**/                            KC_Y,           KC_N,           KC_E,           KC_O,           KC_I,           KC_TRNS,
        KC_TRNS,        KC_Z,           KC_X,           KC_M,           KC_C,           KC_V,           KC_TRNS,        /**/            KC_TRNS,        KC_K,           KC_L,           KC_COMMA,       KC_DOT,         KC_SLSH,       KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        /**/                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        //--------------|***************|***************|***************|***************|---------------$---------------/**/----------------------------$---------------|***************|***************|***************|***************|---------------
                                                                                        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,
                                                                                                        KC_TRNS,        /**/            KC_TRNS,
                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        /**/            KC_TRNS,        KC_TRNS,        KC_TRNS),

