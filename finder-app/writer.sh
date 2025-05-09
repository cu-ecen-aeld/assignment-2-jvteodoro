#!/bin/bash

if [ $# -ne 2 ]; then
	echo "Error"
	exit 1
fi
if [ ! -d $1 ]; then
	mkdir -p "$(dirname $1)" 
fi
echo "$2" > $1
if [ ! -e $1 ]; then
	echo "Error could not create file"
	exit 1
fi
