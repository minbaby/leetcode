#!/usr/bin/env bash

if [ "$1" != "" ]; then
    cd $1
fi

go test -failfast -timeout=3s ./...