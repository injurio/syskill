#!/bin/bash

dir_size=$(du -ms $1 | cut -f1)

if [ $dir_size -lt 1 ]; then
    echo "Low"
elif [ $dir_size -lt 20 ]; then
    echo "Medium"
else
    echo "High"
    echo "$1" > ListOfBigDirs.txt
fi