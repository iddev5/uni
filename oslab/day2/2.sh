#!/bin/bash

filename=$1
i=1
while read line; do
  if [ $(( $i % 2 )) -eq 1 ]; then
    echo $line >> $filename.tmp
  fi
  i=$(( $i + 1 ))
done < $filename

mv $filename.tmp $filename
echo "All even lines have been removed from $filename"

echo "After removing, new file content is: "
cat -n $filename