#!/bin/dash

counter=0


while [ -d ."snapshot.$counter" ]
do
    counter="$((counter + 1))"
done

echo "Creating snapshot $counter"
mkdir ."snapshot.$counter"

# Not currently ignoring names starting with .
for file in *.txt
do
    cp "$file" ."snapshot.$counter"
done