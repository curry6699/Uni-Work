#!/bin/dash


if [ "$#" -ne 2 ]
then
    echo "Usage: ./scraping_courses.sh <year> <course-prefix>"
    exit 1
fi

if ! [ "$1" -eq "$1" ] 2>/dev/null
then
    echo "./scraping_courses.sh: argument 1 must be an integer between 2019 and 2023"
    exit 1
fi

if [ "$1" -lt 2019 ] || [ "$1" -gt 2023 ] 2>/dev/null
then
    echo "./scraping_courses.sh: argument 1 must be an integer between 2019 and 2023"
    exit 1
fi

year="$1"
prefix="$2"

jsonvariable="https://www.handbook.unsw.edu.au/api/content/render/false/query/+unsw_psubject.implementationYear:${year}%20+unsw_psubject.studyLevel:undergraduate%20+unsw_psubject.educationalArea:${prefix}*%20+unsw_psubject.active:1%20+unsw_psubject.studyLevelValue:ugrd%20+deleted:false%20+working:true%20+live:true/orderby/unsw_psubject.code%20asc/limit/10000/offset/0"
jsonvariable2="https://www.handbook.unsw.edu.au/api/content/render/false/query/+unsw_psubject.implementationYear:${year}%20+unsw_psubject.studyLevel:postgraduate%20+unsw_psubject.educationalArea:${prefix}*%20+unsw_psubject.active:1%20+unsw_psubject.studyLevelValue:pgrd%20+deleted:false%20+working:true%20+live:true/orderby/unsw_psubject.code%20asc/limit/10000/offset/0"

curl -sL "${jsonvariable}" "${jsonvariable2}" | jq -r '.contentlets[] | select(.implementationYear=="'"$year"'") | "\(.code) \(.title)"' | grep -E "^$prefix" | sed 's/  / /g' |sort -k 1,1n | sort -u
