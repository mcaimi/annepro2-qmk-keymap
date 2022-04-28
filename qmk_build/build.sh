#!/bin/bash

C15_BOARD=/qmk_firmware/keyboards/annepro2/c15
C15_KEYMAP=/qmk_firmware/keyboards/annepro2/keymaps

# setup qmk firmware
qmk setup -y || exit -1

# copy custom configuration from volume
cp -v /custom/boards/C15/config.h $C15_BOARD/config.h
cp -v /custom/boards/C15/rules.mk $C15_BOARD/rules.mk

# copy custom keymap
cp -vr /custom/keymap $C15_KEYMAP/

# build firmware
cd /qmk_firmware
make annepro2/c15:keymap

# copy built firmware
cp -v /qmk_firmware/annepro2_c15_keymap.bin /target/annepro2_c15_keymap_$(date +%F).bin
