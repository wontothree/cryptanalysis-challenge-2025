# Docker Base Image
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# 기본 패키지 및 valgrind 설치
RUN apt update && apt install -y \
    bash \
    sudo \
    vim \
    git \
    curl \
    build-essential \
    valgrind \
    cmake \
    qtbase5-dev \
    qt5-qmake \
    qtbase5-dev-tools \
    libsqlite3-dev \
    sqlite3 \
    x11-apps \
    && rm -rf /var/lib/apt/lists/*
    
# 작업 디렉토리 설정
WORKDIR /workspace

# 기본 쉘
CMD [ "bash" ]
