#!/usr/bin/env python3

import sys
import re
import collections

words = collections.Counter()

matchWord = sys.argv[1]

for line in sys.stdin:
    line = re.split(r'[^a-zA-Z]+', line)

    for word in line:
        if matchWord.lower() == word.lower():
            words[matchWord] += 1

print(f"{matchWord} occurred {words[matchWord]} times")
