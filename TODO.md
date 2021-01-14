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

- move sym/num into same layer?? size...

- remove put underscore on outer right sides

- I need to add new mouse move that only moves when a directional key is pressed down
  right hand just updates the speed variable. this should be easy by reusing the code I already have.

  1. go back copy code mouse cont.
  2. paste function in current
  3. change state variables
  4. point my custom_pointer function to this new function. > I could even have a switch for shifting the move modality.

- \_TEST layer >> reset safety: hold down keys with left hand > make RESET button available

- put thumb space etc. on the lowest row.

- how do I mouse scroll

- if grid and layer === \_TEST

  so that I can test different things with the grid.

- add new modular file from which I import functions that I can use with marcus.

  import new mouse function?

- custom syntax / prettier ?
  ignore syntax between comments??? so that I can structure my layers freely.

- VIM TABULAR >>> can I use this to more easilly manage the qmk syntax in code???

- key > turn off rgb lights

* add / to numpad!!!

* switch disc/cont.

* add a repeat button > that makes it possible to repeat a char without double hitting it.

* mirror mouse mode for right hand.

* why are the steps of the mouse pointer not linear.

* `_BAS` add symbols to bottom layer.

* Index_finger layer?

* mod keys in all layers

* spacing keys
  enter, space, backspace, tab

* where put `RESET`

* add show mouse key >> make moure spin in cicles.

* reverse repeat.

  ---

# general thoughts and todos

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
