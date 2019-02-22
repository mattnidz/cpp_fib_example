FROM alpine:3.6 as build
MAINTAINER "Matt Nidzgorski"

WORKDIR /cpp-build

RUN apk update && \
    apk upgrade && \
    apk --update add \
        gcc \
        g++ \
        libstdc++ \
        gfortran \
        make \
        cmake \
        bash \
        build-base \
        git  && \
    rm -rf /var/cache/apk/*

ADD . .

RUN g++ -c fib.cpp && \
    g++ -o fib fib.o


FROM alpine:3.6

WORKDIR /application

RUN apk update && \
    apk upgrade && \
    apk --update add \
        libstdc++ && \
    rm -rf /var/cache/apk/*

COPY --from=build /cpp-build/fib /application/fib

CMD ./fib 10