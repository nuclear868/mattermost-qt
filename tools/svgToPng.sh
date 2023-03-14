#!/bin/bash

if [ "$#" != "2" ]; then
	echo "Usage: $0 <"sizes"> <source>"
	echo "Note: sizes should be enclosed in quotes"
	echo "Example: $0 \"16 32 64\" input.svg"
	exit 1
fi

sizes=($1)
src=$2

if [ ! -f "$src" ]; then
	echo "source file '$src' does not exist"
	exit 1;
fi

srcBase=$(basename "$src")
dstName="$(dirname $src)/${srcBase/.svg/}"

for s in "${sizes[@]}"; do
	inkscape -w "$s" -h "$s" -o "${dstName}-${s}.png" "$src"
done

