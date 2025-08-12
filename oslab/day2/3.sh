#!/bin/bash

files1=$(ls $1)
files2=$(ls $2)

while read f1; do
  while read f2; do
    if [ $f1 == $f2 ]; then
      echo "Found duplicate $1$f1 and $2$f2. Removed $1$f1"
      rm $1/$f1
    fi
  done <<<$files2
done <<<$files1

echo "All duplicate files have been removed"
