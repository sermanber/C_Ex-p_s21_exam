#!/bin/bash

gcc main.c -o main -lfcgi

if [ $? -ne 0 ]; then
    exit 1
fi

sudo fuser -k 8080/tcp || true
sleep 1

sudo spawn-fcgi -p 8080 ./main

if pgrep nginx >/dev/null; then
    sudo nginx -s stop
    sleep 1
fi

sudo nginx -c "$(pwd)/nginx/nginx.conf"
