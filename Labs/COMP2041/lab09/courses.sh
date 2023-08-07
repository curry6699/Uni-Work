#!/bin/dash

info=$(curl --location --silent http://www.timetable.unsw.edu.au/2023/$1KENS.html)

string=$(echo "$info" | grep -E "td class=\"data\"" | grep -E ".html" | cut -d '>' -f 2,3 )

title=$(echo "$string" | cut -d '>' -f2 | cut -d '<' -f1 | sed '$!N;s/\n/ /' | grep -E "^[A-Z]{4}[0-9]{4}" | sort -u)

echo "$title"
