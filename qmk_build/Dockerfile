FROM docker.io/qmkfm/qmk_cli

RUN mkdir -p /custom && mkdir -p /target
COPY build-vanilla.sh /tmp
COPY build-vial.sh /tmp

VOLUME /custom
VOLUME /target

