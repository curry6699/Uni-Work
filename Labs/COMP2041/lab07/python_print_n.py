#!/usr/bin/env python3

import sys

n = sys.argv[1]
argument = sys.argv[2]

print("#!/usr/bin/env python3")
print("import sys")
print("print(" + repr(argument) + ")")

i = 0

while i < n:

