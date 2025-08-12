#!/bin/bash

printf "Enter upper limit: "
read limit

i=2
while [ $i -lt $limit ]; do
  j=2
  prime=1
  while [ $j -lt $(( $i / 2 + 1 )) ]; do
    if [ $(( $i % $j )) -eq 0 ]; then
      prime=0
    fi
    j=$(( $j + 1 ))
  done
  if [ $prime -eq 1 ]; then
    printf "$i "
  fi
  i=$(( $i + 1 ))
done
