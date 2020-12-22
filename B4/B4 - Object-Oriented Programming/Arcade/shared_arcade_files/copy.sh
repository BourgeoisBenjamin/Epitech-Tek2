#!/bin/bash

if [ "$#" -le 1 ]; then
    echo "\$1: Git repository directory"
    echo "\$2: Destination"
    exit 1
fi

cp `find "$1" -name "arcade"` "$2"
cp `find "$1/games" -name "*.so"` "$2/games"
cp `find "$1/lib" -name "*.so"` "$2/lib"
cp -r "$1/assets" "$2"
