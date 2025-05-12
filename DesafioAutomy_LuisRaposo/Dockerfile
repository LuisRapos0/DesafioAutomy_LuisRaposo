FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive
ENV TERM=xterm

RUN apt-get update && \
    apt-get install -y \
    build-essential \
    curl \
    libcurl4-openssl-dev \
    git \
    cmake \
    wget \
    nlohmann-json3-dev \
    bash \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY ./src/src /app/src
COPY ./src/include /app/include
COPY ./src/Makefile /app/

RUN make -C /app

ENTRYPOINT ["./bin/desafio_github_luisraposo"]