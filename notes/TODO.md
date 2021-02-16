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

- ignore movement if release and press first. >> so that you don't move
  with the previous direction from before the prev release.

- 2seq > use a timeout to allow for short release before reset > so that you don't
  get tense from forcing fingers down at all times.

* test change the number of directions.

* where put .ccls, qmk root?

* need to add capslock

## RNDM
