#!/bin/bash

filename=$1
gregorian=2020
buddhist=2563
for line in $(cat $filename); do
    fname=$(echo $line | cut -d ',' -f 1)
    lname=$(echo $line | cut -d ',' -f 2)
    year_born=$(echo $line | cut -d ',' -f 3 | head -c 4)
    if [ $year_born -gt $gregorian ]; then 
        age=$((buddhist-year_born))
    else
        age=$((gregorian-year_born))
    fi
    if [ $age -ge 18 ]; then
        echo "Dear Mr/Mrs $lname, $fname"
    fi
done