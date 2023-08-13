#!/bin/bash
whom=$(whoami)
gm="Good Morning, ${whom}"
ga="Good Afternoon,${whom}"
ge="Good Evening,${whom}"
sl="You should be sleeping, ${whom}!"

current_time=$(date +%k)

#brackets are very finicky. must have spaces!
if [ $current_time -lt 12 ]
then
echo $gm
elif [ $current_time -ge 12 && $current_time -lt 17 ]
then
echo $ga
elif [ $current_time -ge 17 && $current_time -lt 23 ]
then
echo $ge
else
echo $sl
fi

echo "Date is:" $(date)
echo "Users Logged in:"
echo $(who)
