#!/bin/dash

for directory in "$@"
do
    for file in "$directory"/*
    do
        title="$(echo "$file" | cut -d '-' -f 2 | sed "s/^ //g")"
        album="$(echo "$file" | cut -d '/' -f 2)"
        year="$(echo "$file" | cut -d '/' -f 2 | cut -d ',' -f 2 | sed "s/^ //g")"
        artist="$(echo "$file" | cut -d '-' -f 3 | cut -d '.' -f 1 | sed "s/^ //g")"
        track="$(basename "$file" | cut -d '/' -f 3 | cut -d ' ' -f 1)"

        id3  -t "$title" -T "$track" -a "$artist" -A "$album" -y "$year" "$file" >/dev/null 
        # echo "$track"
    done
done


