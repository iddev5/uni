#!/bin/bash

printf "Enter upper limit: "
read limit

for (( i=2; i<$limit; i++ )); do
  prime=1
  for (( j=2; j<$i/2+1; j++ )); do
    if [ $(( $i % $j )) -eq 0 ]; then
      prime=0
    fi
  done
  if [ $prime -eq 1 ]; then
    printf "$i "
  fi
done
