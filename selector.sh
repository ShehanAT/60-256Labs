#!/bin/bash
firstword=$(grep -n $1 < headandtail | cut  -d ':' -f 1  | head -n 1)
secondword=$(grep -n $2 < headandtail | cut -d ':' -f 1 | head -n 1)
list=$((firstword - second+1))

head -n $secondword headandtail| tail -n $list 
