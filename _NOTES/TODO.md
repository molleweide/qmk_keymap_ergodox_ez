# KB LAYOUT

## RNDM

# debugging macos ----------------------------------

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

- move up escape to tab pos.

- would it make sense to put layer shift to symbols on ring finger upper row?
- so that I can access control more easilly.

- transition away from thumb keys completely > only use for special stuff. > it
- is too straining to use a lot.

  try:

  1. use double tap to enter mouse mode || or release thumbs at the same time. tmux mode could be really nice.

  > > creating a tmux mode should not be that difficult i think.

  2. move space and enter up and then but backspace and tab on first thumb keys.
  3. when I have this setup with the mouse keys show marcus with my modifier keys > show marcus

- do some recording with midi >> how switch fast MIDI<->BASE?

- new colors. faded.

- does painting work with \_ep = off??

- hold down thumb keys >> enter mouse mode.

- ooh if I use only home row for mod keys in mouse layer >>> then I can use other keys for holding down mod keys
  which would make it possible to use various pencil tools in reaper.

- having to(BASE) next to index finger is not good. it should be on thumbs for sure.
  i could also have a hold down both thumbs to ender BASE.
  hold down left thumb(goToNewLayer). and press right thumb keygo back to base

- need to add capslock

- move control to pinky on row below

- mouse right click enter base???
