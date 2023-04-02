#!/bin/bash

if [ "$#" != "3" ]; then
	echo "Usage: $0 <"sizes"> <source svg> <destination dir>"
	echo "Note: sizes should be enclosed in quotes"
	echo "Example: $0 \"16 32 64\" input.svg resources/icons"
	exit 1
fi

sizes=($1)
srcSvg=$2
dstDir=$3

if [ ! -f "$srcSvg" ]; then
	echo "source file '$srcSvg' does not exist"
	exit 1;
fi

srcBase=$(basename "$srcSvg")
dstName="$dstDir/${srcBase/.svg/}"

for s in "${sizes[@]}"; do
	inkscape -w "$s" -h "$s" -o "${dstName}-${s}.png" "$srcSvg"
done

