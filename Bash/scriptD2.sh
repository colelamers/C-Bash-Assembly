#!/bin/bash
timer=$1
min=0

#args for commands can be executed anywhere on the line afaik

if [ $# -ne 1 ]
then
echo "Usage: countdown2 initial-value"
exit
fi

while [ $timer -ge $min ]
do
    echo $timer
    sleep 0.5
    ((timer=timer-1))
done
echo "GO!"
