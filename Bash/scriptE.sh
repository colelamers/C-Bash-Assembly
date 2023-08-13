#!/bin/bash
filepath="cs452_scripts/"

#Moves files to a specified directory in the active directory
#for future reference, do not have the directory maintain the same name as the substring your looking for
for file in *
do
fileString=$file
    if [[ $fileString == *"script"* ]];then
        mv $file $filepath
    fi
done
echo DONE!
