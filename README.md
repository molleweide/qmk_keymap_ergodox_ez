================================================
KB LAYOUT
================================================

## todo

-   delete all unnecessary layers
        so that I can start improving on my layers and
        build new ones with ease
        
        1. make sure all layers are named
        2. make enumerated arr for layers
        3. delete unnecessary ones

- create a layer for using in conjunction with the mouse
    that is single toggle so that I can tap enter the layer
    fast for quick editing.
        candidate triggers
            -   double tap outer PINKY (KC_ESCAPE / KC_QUOTE)


-   strategy???
        how make sure I always have a working backup keymap !!!! 

RAPID DEV
    >>> LEARN HOW TO AUTO FLASH KEYBOARD
# layer improvements
    in mouse layer > only xxxxxxxxx keys - no transparent keys?
# types of buttons that I need to configure

    - the '-' character is a bit annoying under the pinky, or is it?

  - modifier keys 
      need access to mod keys in each layer -> for komplex key commands and mods + mouse

  - navigation
      mouse hard switch
      put mouse buttons on left outer keys? 
        and use thumb clusters for more important stuff
      put nav buttons on LOWEST row in BASE layer 

  - Numbers & Fn-key
      dedicated layer for these -> used in many media programs etc., eg. for screensets

  - media buttons
  
  - layer switches
      learn all types of switches
        populate base layer

  - spacing keys
      enter, space, backspace, tab

  - outer keys 
      what is the best way of utilizing the outer keys. 
        what smart layer switches can I make heres

# general thoughts and todos

- move numpad zero away from bottom row
    i would argue that 0 is used so freq that it shouldn't be in the bottom row

- SWAP shift and alt
    this could be smart because then I can switch to the symbols lay and also use shift at the same time
      which would make the layout even more ergonomic when it comes to generatic ([{]}) 

- HOW do i combine the mouse with modifiers in a smooth way 

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

## FUNCTIONS

    process_user
        case Mxx: based on state route events to corresponding pointerFunction.
            pointerModeRouter()
                pointerFunc()
                    if dir
                        setDirection()
                    else
                        setMove
                
        case click:
            regular || hook

    

RNDM
====================================

How do I manage the variable key position? Since I am going to switch between multiple
pointer modes during development, and I am also probably going to keep a bunch of modes,
I am thinking about creating a nested switch of a set of generic pointer grid keys.
This will mean that I'll have to create keys with a smart naming convention so that 
I can keep track of what I am doing in the code. I should probably add COL and ROW
number to the keys like this: 

___, M11, M12, M13, M14, M15,
___, M21, M22, M23, M24, M25,
___, M31, M32, M33, M34, M35,
___, M41, M42, M43, M44, M45,
___, M51, M52, M53, M54, ___,

1. keypress -> if mouse grid -> enter mouse mode router based on which mouse mode is selected

>>> idea on how to use ergodox with mouse.
    create a layer which is optimized for using a L/R hand in conjunction with mouse.
    remove click and scroll functionality from the mouse.










