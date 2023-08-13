#!/bin/bash
#chmod 755 scriptfile = absolute file access

echo 'Hello,' $(whoami)

echo 'Date is:' $(date)
echo 'Users Logged in:'
echo $(who)
