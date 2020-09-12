# KB LAYOUT ----------------------------------------------------

# reduce firmware size

https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

---

# debugging

1. use this to create log statements
   #ifdef CONSOLE_ENABLE
   uprintf("set direction");
   #endif
2. run `./hid_listen.mac` in commandline to start logging

# flash

1. build
2. flash
3. reset

# todo ---------------------------------------------------------

- make 12 directions like the clock > 1 in upper right
  all the numbers can be the same positions but I have to create a shift
  in the trig funcs so that 1 becomes 1 on a clock.

- `_BAS` add symbols to bottom layer.

- Index_finger layer?

- mod keys in all layers

- spacing keys
  enter, space, backspace, tab

- where put `RESET`

- add show mouse key >> make moure spin in cicles.

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
