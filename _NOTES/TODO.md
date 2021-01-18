# KB LAYOUT

## RNDM

1. use this to create log statements

```C
#ifdef
CONSOLE_ENABLE uprintf("set direction");
#endif
```

2. get hid_listen app.
3. run `./hid_listen.mac` in commandline to start logging

# flash w/KB ---------------------------------------

1. qmk build : `make <keyboard>:<keymap>`
2. flash : zshrc > alias tfl="teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_myergo.hex"
3. hit RESET kc in safe layer. wait for 5 seconds...

## todo --------------------------------------------

- change to mouse by double press thumbs AND enter midi layer by double press outer thumbs

  can refactor the function to make this easy?

* where put .ccles, qmk root?

* need to splig up my qmk configs as much as possible.
  https://beta.docs.qmk.fm/developing-qmk/qmk-reference/config_options

* why is KC_PLUS broken in symb layer with CTL_T()

* move up escape to tab pos.

* would it make sense to put layer shift to symbols on ring finger upper row?
* so that I can access control more easilly.

* ooh if I use only home row for mod keys in mouse layer >>> then I can use other keys for holding down mod keys
  which would make it possible to use various pencil tools in reaper.

* having to(BASE) next to index finger is not good. it should be on thumbs for sure.
  i could also have a hold down both thumbs to ender BASE.
  hold down left thumb(goToNewLayer). and press right thumb keygo back to base

* need to add capslock

* move control to pinky on row below

* mouse right click enter base???
