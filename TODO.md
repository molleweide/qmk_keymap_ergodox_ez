# KB LAYOUT ----------------------------------------------------

# reduce firmware size

https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

---

# debugging macos

1. use this to create log statements
   #ifdef CONSOLE_ENABLE
   uprintf("set direction");
   #endif
2. get hid_listen app.
3. run `./hid_listen.mac` in commandline to start logging

# flash w/KB

1. qmk build : `make <keyboard>:<keymap>`
2. flash : zshrc > alias tfl="teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_myergo.hex"
   (3). hit RESET kc in safe layer.
   this is only necessary if you load the keymap manually into teensy app.
   then, hitting RESET is the same as pressing the reset button with paperclip

# todo ---------------------------------------------------------

- mouse release is not perfect yet

- having to(BASE) next to index finger is not good. it should be on thumbs for sure.
  i could also have a hold down both thumbs to ender \_BASE.

  1. hold down left thumb(goToNewLayer). and press right thumb key(go back to base)

- need to add capslock

- move control to pinky on row below

- mouse right click > enter base???

## general thoughts and todos

- how should I do with the CMD key

  - dual with SPACE and ENTER?
  - add it to the outermost thumb keys?

## THUMBCLUSTER

- tap dance in combination with hold
  main kc, tap kc, and hold down kc.
  this will make the thumb clusters into monsters

# RNDM

so it seems that the enum keys are mapped to an integer and therefore the switch case complains.
So I have to fix this now. but this is a good foundation for the controller pointer.
now ri will just figure out how to modify it a little bit so that it can work with the new
rule or whatever.
