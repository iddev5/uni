#!/bin/sh

printf "Enter file name to read: "
read filename

if [ -e $filename ]; then
  echo "File content:"
  cat $filename
else
  echo "File does not exists"
fi
