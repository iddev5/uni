#!/bin/bash

echo -n "Enter name of file: "
read filename

echo -n "Enter string to search: "
read string

indices=$(grep -bo $string $filename | cut -d: -f1)

printf "Index of given string in file:\n$indices"
