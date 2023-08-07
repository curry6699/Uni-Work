#!/usr/bin/env python3

import sys

argument = sys.argv[1]

print("#!/usr/bin/env python3")
print("import sys")
print("print(" + repr(argument) + ")")
