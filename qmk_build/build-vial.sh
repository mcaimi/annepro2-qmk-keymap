#!/bin/bash

C15_BOARD=/qmk_firmware/keyboards/annepro2/c15
C15_KEYMAP=/qmk_firmware/keyboards/annepro2/keymaps

# setup qmk firmware
qmk setup -y -H /vial-qmk -b vial vial-kb/vial-qmk || exit -1
qmk config user.keyboard=annepro2/c15
qmk config user.keymap=vial

# build keyboard firmware
qmk compile

# build shine (rgb ligting) firmware
git clone https://github.com/OpenAnnePro/AnnePro2-Shine.git --recursive --depth 1 || exit 1
cd /AnnePro2-Shine
make C15

# copy built firmware
cp -v /vial-qmk/annepro2_c15_${KEYMAP_NAME}.bin /target/annepro2_c15_${KEYMAP_NAME}_$(date +%F).bin
cp -v /AnnePro2-Shine/build/annepro2-shine-C15.bin /target/annepro2_c15_shine_$(date +%F).bin
