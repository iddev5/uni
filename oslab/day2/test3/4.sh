#!/bin/sh

printf "Enter name of the file: "
read filename

touch $filename

printf "Enter contents of the file: "
read contents

echo $contents > $filename
echo "File written successfully!"