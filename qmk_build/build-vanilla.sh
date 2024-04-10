#!/bin/bash

NAME=$1
KEYMAP_NAME=${NAME:-custom_layout}
C15_BOARD=/qmk_firmware/keyboards/annepro2/c15
C15_KEYMAP=/qmk_firmware/keyboards/annepro2/keymaps

# setup qmk firmware
qmk setup -y || exit -1
qmk setup -H /qmk_firmware/
qmk config user.keyboard=annepro2/c15
qmk config user.keymap=$KEYMAP_NAME
qmk new-keymap

# copy custom configuration from volume
cp -v /custom/boards/c15/config.h $C15_BOARD/config.h
cp -v /custom/boards/c15/rules.mk $C15_BOARD/rules.mk
cp -v /custom/boards/c15/info.json $C15_BOARD/info.json

# copy custom keymap
cp -vr /custom/keymap/keymap.c $C15_KEYMAP/$KEYMAP_NAME/

# build keyboard firmware
qmk compile

# build shine (rgb ligting) firmware
git clone https://github.com/OpenAnnePro/AnnePro2-Shine.git --recursive --depth 1 || exit 1
cd /AnnePro2-Shine
make C15

# copy built firmware
cp -v /qmk_firmware/annepro2_c15_${KEYMAP_NAME}.bin /target/annepro2_c15_${KEYMAP_NAME}_$(date +%F).bin
cp -v /AnnePro2-Shine/build/annepro2-shine-C15.bin /target/annepro2_c15_shine_$(date +%F).bin
