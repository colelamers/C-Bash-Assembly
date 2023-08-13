#!/bin/bash

min=0

#args for commands can be executed anywhere on the line afaik
echo -n "Enter the timer max:"
read timer
echo $varA

while [ $timer -ge $min ]
do
    echo $timer
    sleep 0.5
    ((timer=timer-1))
done
echo "GO!"
