# FLASH

1. qmk build : `make <keyboard>:<keymap>`
    gulp takes care of this

2. flash : zshrc > alias tfl="teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_molleweide.hex"

3. hit RESET from current layout
    wait for 5 seconds... boom new layout!
