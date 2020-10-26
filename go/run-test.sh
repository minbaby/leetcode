#!/usr/bin/env bash

if [ "$1" != "" ]; then
    CUR=$(dirname $(realpath $0))
    cd $CUR/$1
fi

go test -failfast -timeout=3s ./...

if [ "$CUR" != "" ]; then
  cd $CUR
fi