#!/usr/bin/env python3

import sys 
import re

f = open(sys.argv[1], 'r')

sum = 0
    
for line in f:
    line = re.sub("[^0-9]", " ", line)
    line = re.sub(" +", " ", line)
    line = line.rstrip()
    if line:
        tmp = "0"

        for character in line:
            if character.isdigit():
                tmp += character
            else:
                sum += int(tmp)
                tmp = "0"

        if tmp != "0":
            sum += int(tmp)
            
print(sum)