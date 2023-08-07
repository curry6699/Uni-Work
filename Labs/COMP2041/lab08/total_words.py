#!/usr/bin/env python3

import sys
import re

counter = 0
for line in sys.stdin:
    line = re.split(r'[^a-zA-Z]+', line)

    for word in line:
        if word:
            counter += 1

print(counter, "words")
