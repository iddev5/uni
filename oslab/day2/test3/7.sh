#!/bin/sh

printf "Enter file name: "
read filename

chars=$(wc -c < $filename)
words=$(wc -w < $filename)
lines=$(wc -l < $filename)

echo "No. of characters: $chars"
echo "No. of words: $words"
echo "No. of lines: $lines"

