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
    gulp takes care of this

2. flash : zshrc > alias tfl="teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_molleweide.hex"

3. hit RESET from current layout
    wait for 5 seconds... boom new layout!

## TODO --------------------------------------------

- bool > continue prev movement if only velocity

- only exit midi by right thumb >> security. what can i do with
  pointer left thumb when single click.

* if point layer and double press >> enter midi layer!!

* bt thumbs with tap dance

* add move layer with all quick switch with all modifiers

## RNDM
