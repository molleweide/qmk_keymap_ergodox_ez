# KB LAYOUT

## DEBUGGING

1. use this to create log statements

```C
#ifdef
CONSOLE_ENABLE uprintf("set direction");
#endif
```

2. get hid_listen app.
3. run `./hid_listen.mac` in commandline to start logging

# FLASH

1. qmk build : `make <keyboard>:<keymap>`
2. flash : zshrc > alias tfl="teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_myergo.hex"
3. hit RESET kc in safe layer. wait for 5 seconds...

## TODO --------------------------------------------

- esc dir

- improve velocities,

* are these all combinations???

  1. BASE 2 MOUSE >> 1 press
  2. BASE 2 MOVE >> 1 press
  3. BASE 2 MIDI >> 1 press

  4. MIDI 2 BASE >> 1 press
  5. MIDI 2 MOVE >> 1 press
  6. MIDI 2 MOUSE >> 1 press

  7. MOVE 2 BASE >> 1 press
  8. MOVE 2 MOUSE >> 1 press
  9. MOVE 2 MIDI >> 1 press

* test change the number of directions.

## bluetooth

- building ergoblue would be cool >>> learn go > https://www.xudongz.com/blog/2019/ergoblue/

- ergo bt https://github.com/Biacco42/ErgoDox-BT

- dactyl
  awesome >>> https://github.com/potakhov/qmk_firmware/tree/pap_rev0.2/keyboards/handwired/papuno
  https://github.com/jamiehs/custom-bluetooth-dactyl-manuform
