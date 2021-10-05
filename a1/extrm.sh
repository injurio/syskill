#!/bin/bash

ext=$1
dir=$2
for i in $(find $dir -name "*$ext"); do
	no_ext=$(echo $(basename $i) | cut -d'.' -f 1)
	mv $i $dir/$no_ext
done