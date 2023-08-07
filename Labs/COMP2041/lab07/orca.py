#!/usr/bin/env python3

import sys 
counter = 0

for arg in sys.argv[1:]:
    f = open(arg, 'r')
    for line in f:
        if "Orca" in line:
            listString = line.split(' ')
            listString = [x for x in listString if x != '']
            counter+= int(listString[1])

print(f"{counter} Orcas reported")    