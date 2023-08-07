#!/bin/dash

if [ "$#" -ne 2 ]
then
    echo "Usage: ./echon.sh <number of lines> <string>"
    exit 1
fi

if ! [ "$1" -eq "$1" ] 2>/dev/null
then
    echo "./echon.sh: argument 1 must be a non-negative integer"
    exit 1
fi

if [ "$1" -lt 0 ] 2>/dev/null
then
    echo "./echon.sh: argument 1 must be a non-negative integer"
    exit 1
fi


times="$1"
line="$2"
i=0

while [ "$i" -lt "$times" ]
do
    echo "$2"

    i=$((i + 1))
done