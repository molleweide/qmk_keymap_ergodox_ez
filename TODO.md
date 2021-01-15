# KB LAYOUT

## RNDM

det kommer ju bli so mycket roligare att jobba med datorer naer det haer goes as fast
as you can imagine.

the importance is that you know what the fuck you are doing. then there will be a magical path.

# debugging macos

1. use this to create log statements

```C
#ifdef
CONSOLE_ENABLE uprintf("set direction");
#endif
```

2. get hid_listen app.
3. run `./hid_listen.mac` in commandline to start logging

# flash w/KB

1. qmk build : `make <keyboard>:<keymap>`
2. flash : zshrc > alias tfl="teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_myergo.hex"
3. hit RESET kc in safe layer. wait for 5 seconds...

## todo

- mouse release is not perfect yet

- having to(BASE) next to index finger is not good. it should be on thumbs for sure.
  i could also have a hold down both thumbs to ender BASE.
  hold down left thumb(goToNewLayer). and press right thumb keygo back to base

- need to add capslock

- move control to pinky on row below

- mouse right click enter base???

## general thoughts and todos

- how should I do with the CMD key

  - dual with SPACE and ENTER?
  - add it to the outermost thumb keys?

## THUMBCLUSTER

- tap dance in combination with hold
  main kc, tap kc, and hold down kc.
  this will make the thumb clusters into monsters
