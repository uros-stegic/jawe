#!/usr/bin/env bash

if [ $# -eq 0 ];
then
	mkdir -p build
	cd build
	cmake ..
	make
elif [ "$1" == "--remove" ];
then
	rm -rf build
else
	echo "Unknown command $1"
fi

