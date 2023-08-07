#!/usr/bin/env python3
import glob
import sys
import re
import collections
import math

matchPhrase = sys.argv[1:]

for artist in sorted(glob.glob("lyrics/*")):
    words = collections.Counter()

    counter = 0

    artistName = artist.split("/")[1]
    artistName = artistName.split(".")[0]
    artistName = re.sub(r'[^A-Za-z]', ' ', artistName)

    with open(artist, "r") as artistFile:
        for line in artistFile:
            line = re.split(r'[^a-zA-Z]+', line)

            for word in line:
                word = word.lower()
                if word:
                    words[word] += 1
                    counter += 1

    probability = 0
    for matchWord in matchPhrase:
        divisionResult = (1 + int(words[matchWord])) / counter

        if divisionResult != 0:
            probability += math.log(divisionResult)
    print(f"{probability:10.5f} {artistName}")
