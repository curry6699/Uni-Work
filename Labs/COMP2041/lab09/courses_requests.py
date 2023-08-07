#!/usr/bin/env python3

import sys
import re
from bs4 import BeautifulSoup
import requests

courseCode = sys.argv[1:]
link = "http://www.timetable.unsw.edu.au/2023/" + courseCode[0] + "KENS.html"

response = requests.get(link)
soup = BeautifulSoup(response.content, "html.parser")

a_tags = soup.find_all("a")

myset = set()

for line in a_tags:
    if re.search(r"[A-Z]{4}[0-9]{4}", str(line)):
        code = re.split(r'["]', str(line))[1]
        code = code[:-5]
        title = re.split(r'["]', str(line))[2]
        title = title[1:-4]
        if code == title:
            continue
        formattedLine = code + " " + title
        myset.add(formattedLine)

mylist = list(myset)
mylist.sort()
for value in mylist:
    print(value)
