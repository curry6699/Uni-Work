#!/bin/dash

for file in *.jpg
do
    if ! [ -f "$file" ]
    then
        echo "No JPGs"
        exit 1
    fi 

    filename="${file%????}"
    filenamePNG="$filename.png"

    if [ -f "$filenamePNG"  ]
    then
        echo "$filenamePNG already exists"
        exit 1
    fi

    convert "$file" "$filename.png"
    rm "$file"
done