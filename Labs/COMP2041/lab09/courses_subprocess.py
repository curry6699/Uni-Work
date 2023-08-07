#!/usr/bin/env python3

import subprocess
import sys
import re

courseCode = sys.argv[1:]
link = "http://www.timetable.unsw.edu.au/2023/" + courseCode[0] + "KENS.html"

command = ["curl", "--location", "--silent", link]
response = subprocess.run(command, capture_output=True, text=True)

courseInfo = []
for line in response.stdout.splitlines():
    if re.search(r"[A-Z]{4}[0-9]{4}", line):
        courseInfo.append(line)

# print(courseInfo[::2])

myset = set()
for entry in courseInfo:
    code = re.split(r'["]', entry)[3]
    title = re.split(r'[>]', entry)[2]

    if (code[0:8] != title[:-3]):
        line = code[0:8] + " " + title[:-3]
        myset.add(line)

mylist = list(myset)
mylist.sort()
for value in mylist:
    print(value)