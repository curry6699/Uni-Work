#!/usr/bin/env python3
import glob
import sys
import re
import collections
import math

matchPhrase = sys.argv[1:]
fileProbabilities = {}

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

    artistProbabilities = []
    for arg in sys.argv[1:]:
        probability = 0
        with open(arg, "r") as argFile:
            for line in argFile:
                line = re.split(r'[^a-zA-Z]+', line)
                for word in line:
                    if word:
                        divisionResult = (1 +
                                          int(words[word.lower()])) / counter
                        if divisionResult != 0:
                            probability += math.log(divisionResult)
            artistProbabilities.append(probability)
    fileProbabilities[artistName] = artistProbabilities

i = 0
for song in matchPhrase:
    highest = -10000
    artistName = None
    for artist, key in fileProbabilities.items():
        if key[i] > highest:
            highest = key[i]
            artistName = artist
    # print(highest, artistName)
    print(
        f"{song} most resembles the work of {artistName} (log-probability={round(highest, 1)})"
    )
    i += 1