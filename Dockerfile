FROM debian:bullseye-slim

RUN dpkg-reconfigure debconf -f noninteractive -p critical \
    && echo 'root:root' | chpasswd \
    && groupadd -g 1000 dev \
    && useradd -m -u 1000 -g dev dev

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        cmake \
        gcc-arm-none-eabi \
        git \
        libnewlib-arm-none-eabi \
        libstdc++-arm-none-eabi-newlib \
        python3

RUN mkdir -p /usr/src \
    && cd /usr/src \
    && git clone -b master https://github.com/raspberrypi/pico-sdk.git \
    && cd pico-sdk \
    && git submodule update --init --recursive 

ENV PICO_SDK_PATH=/usr/src/pico-sdk

USER dev
