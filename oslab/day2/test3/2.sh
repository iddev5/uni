#!/bin/bash

echo -n "Enter your age: "
read age
if [ $age -ge 18 ]; then
  echo "User is adult"
else
  echo "User is minor"
fi
