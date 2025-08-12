#!/bin/bash

echo -n "Enter name of file: "
read filename

echo -n "Enter string to search: "
read string

grep -bo $string $filename > $filename.tmp

sed -i "s/:$string//g" $filename.tmp

echo "Index of given string in file: "
cat $filename.tmp

rm $filename.tmp
