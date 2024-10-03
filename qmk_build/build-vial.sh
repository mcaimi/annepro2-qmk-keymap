#!/bin/bash

QMK_FIRMWARE=/vial-qmk
QMK_BASE=$QMK_FIRMWARE/keyboards/annepro2
C15_BOARD=$QMK_BASE/c15
C15_KEYMAP=$QMK_BASE/keymaps
KEYMAP_NAME=vial

# setup qmk firmware
qmk setup -y -H $QMK_FIRMWARE -b vial vial-kb/vial-qmk || exit -1
qmk config user.keyboard=annepro2/c15
qmk config user.keymap=$KEYMAP_NAME

# copy keyboard info.json
cp -v /custom/boards/c15/vial/info.json $QMK_BASE/info.json

# copy custom config code
cp -v /custom/boards/c15/vial/config.h $C15_BOARD/config.h
cp -v /custom/boards/c15/vial/rules.mk $C15_BOARD/rules.mk
cp -v /custom/boards/c15/vial/keyboard.json $C15_BOARD/keyboard.json

# copy keymap code
cp -v /custom/keymap/vial/config.h $C15_KEYMAP/$KEYMAP_NAME/config.h
cp -v /custom/keymap/vial/vial.json $C15_KEYMAP/$KEYMAP_NAME/vial.json
cp -v /custom/keymap/vial/rules.mk $C15_KEYMAP/$KEYMAP_NAME/rules.mk
cp -v /custom/keymap/vial/keymap.c $C15_KEYMAP/$KEYMAP_NAME/keymap.c

# build keyboard firmware
qmk compile

# build shine (rgb ligting) firmware
git clone https://github.com/OpenAnnePro/AnnePro2-Shine.git --recursive --depth 1 || exit 1
cd /AnnePro2-Shine
make C15

# copy built firmware
cp -v $QMK_FIRMWARE/annepro2_c15_${KEYMAP_NAME}.bin /target/annepro2_c15_${KEYMAP_NAME}_$(date +%F).bin
cp -v /AnnePro2-Shine/build/annepro2-shine-C15.bin /target/annepro2_c15_shine_$(date +%F).bin
