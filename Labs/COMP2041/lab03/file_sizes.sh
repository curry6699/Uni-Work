#!/bin/dash

# Loop for small files first
echo -n "Small files: " 
for filename in *
do
    test -f "$filename" || continue

    length=$(wc -l "$filename" | cut -d ' ' -f 1)

    if [ "$length" -lt 10 ]
    then
        echo -n "$filename "
    fi
done
echo

# Loop for medium files
echo -n "Medium-sized files: " 
for filename in *
do
    test -f "$filename" || continue

    length=$(wc -l "$filename" | cut -d ' ' -f 1)

    if [ "$length" -gt 9 ] && [ "$length" -lt 101 ]
    then
        echo -n "$filename "
    fi
done

echo

# Loop for large files
echo -n "Large files: " 
for filename in *
do
    test -f "$filename" || continue

    length=$(wc -l "$filename" | cut -d ' ' -f 1)

    if [ "$length" -gt 100 ]
    then
        echo -n "$filename "
    fi
done

echo