#!/usr/bin/env python3
import glob
import sys
import re
import collections
import pprint

matchWord = sys.argv[1]

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

    # pprint.pp(words)
    # print(words)
    divisionResult = int(words[matchWord]) / counter
    print(
        f"{words[matchWord]:4}/{counter:6} = {divisionResult:.9f} {artistName}")
