================================================
KB LAYOUT
================================================


debugging
================================================

1. use this to create log statements
  #ifdef CONSOLE_ENABLE
      uprintf("set direction");
  #endif

2. run `./hid_listen.mac` in commandline to start logging




todo
================================================

1. remove dvo, col, wrk layer
  - put these in new file
2. rm mouse helper layers






# types of buttons that I need to configure

    - the '-' character is a bit annoying under the pinky, or is it?

  - modifier keys 
      need access to mod keys in each layer -> for komplex key commands and mods + mouse

  - navigation
      mouse hard switch
      put mouse buttons on left outer keys? 
        and use thumb clusters for more important stuff
      put nav buttons on LOWEST row in BASE layer 

  - spacing keys
      enter, space, backspace, tab


# general thoughts and todos

- how should I do with the CMD key
    * dual with SPACE and ENTER?
    * add it to the outermost thumb keys?
    * 

- REAL ESTATE layer switches
    use the LT layer switch to create a layer switching router.
      I don't know how useful this would be but this would make it possible to access all other layers 
        by a 2-step sequence.

## THUMBCLUSTER
  - tap dance in combination with hold
      main kc, tap kc, and hold down kc.
        this will make the thumb clusters into monsters

POINTER DESIGN
====================================

(guitar mode) move with one hand, control speed with other hand

- direction
    select resolution (usable digits; 1, 2, or 3)
    how to specify?
        degrees, pi, clock, etc..

- movement type
    continuous
    discrete

- click
    L/R 
    regular
    hook
    release

- stateSwitching
    WHY?     
        I have good speed but I only want to change direction or vice versa  
        Is it possible to accomodate for this?

- modeSwitching
    since there is no LED or GUI showing what the mode is using Tap Dance
    for mode switching is a good idea, because then there will never be 
    any ambiguity when it comes to the selection.
        I can also use tap dance for entering into modeSelection, or
        specifying settings.
  
## VARIABLES 

    pointerState        // dirReceiver; moveReceiver
    specSettings        // if true, then I can change mode/settings
    
    directionAngle 
    directionInputArr   // 1-3
    directionMode       // hardcoded; free angle

    moveMode            // hardcoded steps; specify freely
    moveInputLength     // 1-3
    moveStepping        // continuous; discrete
    moveFreeze

    keepDir
    keepMove

    clickMode           // regular; hook

    

RNDM
====================================


