#!/bin/bash

i=1
while [ $i -le 100 ]; do
  if [ $(( $i % 2 )) -eq 0 ]; then
    printf "$i "
  fi
  i=$(( $i + 1 ))
done
