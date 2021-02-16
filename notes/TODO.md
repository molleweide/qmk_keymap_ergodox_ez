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

## RNDM

even if this is not the ultimate maybe it dous get me one step further this time
and this iss a bit of a switch but the more i do it and fail the closer i get
and now hoepefully it will be an even faster process since i can switch quite
fast now actually i think.
