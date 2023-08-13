#!/bin/bash
timer=10
neg_1=0

#you cannot have operator values in the while statement. i have not figured that one out yet. you can compare variables however as I have below. If neg_1 was -1, it would countdown to -1
while [ $timer -ge $neg_1 ]
do
    echo $timer
    sleep 0.5
    ((timer=timer-1))
done
echo "GO!"
