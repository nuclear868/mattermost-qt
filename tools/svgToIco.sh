#!/bin/bash

if [ "$#" != "2" ]; then
	echo "Usage: $0 <"sizes"> <input .svg file>"
	echo "Note: sizes should be enclosed in quotes"
	echo "Example: $0 \"16 32 64\" input.svg"
	exit 1
fi

sizes=($1)
src=$2
dst=${src/.svg/.ico}

if [ ! -f "$src" ]; then
	echo "source file '$src' does not exist"
	exit 1;
fi


echo "convert $src to $dst"

exit 1
outList=""

for s in "${sizes[@]}"; do
	tmpName="$(mktemp).png"
	outList="$outList $tmpName"
	inkscape -w "$s" -h "$s" -o "$tmpName" "$src"
done

convert $outList $dst

