#!/bin/dash

fileName="$1"

counter=0

while [ -f ."$fileName.$counter" ]
do
    counter="$((counter + 1))"
done
    echo "Backup of '$fileName' saved as '.$fileName.$counter'"
    cp "$fileName" ."$fileName.$counter"


