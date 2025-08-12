#!/bin/bash

files=$(ls $1)

pushd $1 > /dev/null

while read f1; do
  while read f2; do
    if [ -e $f1 -a -e $f2 ]; then
      diff -q $f1 $f2 > /dev/null
      if [ $? -eq 0 -a ! $f1 == $f2 ]; then
        echo "Duplicate found: $f1 and $f2. Removed $f2"
        rm $f2
      fi
    fi
  done <<<$files
done <<<$files

echo "All duplicate files have been removed"

popd > /dev/null