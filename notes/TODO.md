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

- bt thumbs with tap dance

- add move layer with all quick switch with all modifiers

## RNDM

now if i get a better keyboard with nice thumb keys then i'll be able to
do all of these things
it is just that the ergodox ez is completely wrong for my hands.

i have to get something that is more custom fit for my hands
so that i can really know that i am designing for my own hands.
