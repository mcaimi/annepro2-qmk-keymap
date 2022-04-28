FROM docker.io/qmkfm/qmk_cli

RUN mkdir -p /custom && mkdir -p /target
COPY build.sh /tmp

VOLUME /custom
VOLUME /target

ENTRYPOINT ["/tmp/build.sh"]
