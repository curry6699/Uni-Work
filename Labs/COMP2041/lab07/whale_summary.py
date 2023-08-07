#!/usr/bin/env python3

import sys 
import re
counter = 0

dict = {}
    
for arg in sys.argv[1:]:
    f = open(arg, 'r')

    for line in f:
        whaleName = line[12:]
        whaleName = whaleName.rstrip("\n")
        whaleName = whaleName.lower()
        whaleName = whaleName.strip()
        whaleName = re.sub(' +', ' ', whaleName)
        whaleName = whaleName.rstrip('s')
        numIndividual = line[9:12]

        if whaleName not in dict:
            dict[whaleName] = [0,0]
        
        value = dict[whaleName]
            
        if value[0] is not None:
            pods = value[0]
            count = value[1]
            dict[whaleName] = [int(pods) + 1, int(count) + int(numIndividual)]
    
    f.close()

keys = list(dict.keys())
keys.sort()
sorted_dict = {i: dict[i] for i in keys}

for key, value in sorted_dict.items():
    print(f"{key} observations: {value[0]} pods, {value[1]} individuals")