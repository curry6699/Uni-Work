#!/bin/dash

for arg in "$@" 
do
    date="$(ls -l "$arg" | cut -d ' ' -f 6,7,8)"

    argNew="${arg%????}"
    argTemp="${argNew}temp.png"

    convert -gravity south -pointsize 36 -draw "text 0,10 '$date'" "$arg" "$argTemp"
done