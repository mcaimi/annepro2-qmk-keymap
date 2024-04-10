## Custom QMK Keymap for my Anne Pro 2 Keyboard

Only C15 revision built and tested so far. This is *REALLY* work-in-progress

### Build and Installation Instructions

1- Generate the builder image

```bash
$ cd qmk_build && podman build -t qmk/builder:latest .
```

2- Run the builder image to assemble the firmware

To build the vanilla QMK image...

```bash
$ mkdir -p /tmp/output
$ podman run --rm --name qmk_builder -v <repo_basepath>/:/custom/:z -v /tmp/output:/target/:z qmk/builder:latest /tmp/build-vanilla.sh
```

To build the vial-qmk fork image...

```bash
$ mkdir -p /tmp/output
$ podman run --rm --name qmk_builder -v <repo_basepath>/:/custom/:z -v /tmp/output:/target/:z qmk/builder:latest /tmp/build-vial.sh
```

3- Flash images

After booting the keyboard in IAP mode (insert USB cable while presing ESC):

```bash
$ annepro2_tool --boot /tmp/output/<annepro2_c15_keymap_firmware.bin>
$ annepro2_tool --boot -t led /tmp/output/<annepro2_c15_shine_firmware.bin>
```

