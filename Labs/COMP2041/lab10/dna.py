import re
import collections


def read_dna(dna_file):
    """
    Read a DNA string from a file.
    the file contains data in the following format:
    A <-> T
    G <-> C
    G <-> C
    C <-> G
    G <-> C
    T <-> A
    Output a list of touples:
    [
        ('A', 'T'),
        ('G', 'C'),
        ('G', 'C'),
        ('C', 'G'),
        ('G', 'C'),
        ('T', 'A'),
    ]
    Where either (or both) elements in the string might be missing:
    <-> T
    G <->
    G <-> C
    <->
    <-> C
    T <-> A
    Output:
    [
        ('', 'T'),
        ('G', ''),
        ('G', 'C'),
        ('', ''),
        ('', 'C'),
        ('T', 'A'),
    ]
    """
    listPairs = []

    with (open(dna_file, 'r')) as file:
        for line in file:
            line = line.strip()
            splitOn = re.split('\<\-\>', line)
            tup1 = splitOn[0].replace(' ', '')
            tup2 = splitOn[1].replace(' ', '')
            listPairs.append((tup1, tup2))

    return listPairs


def is_rna(dna):
    """
    Given DNA in the aforementioned format,
    return the string "DNA" if the data is DNA,
    return the string "RNA" if the data is RNA,
    return the string "Invalid" if the data is neither DNA nor RNA.
    DNA consists of the following bases:
    Adenine  ('A'),
    Thymine  ('T'),
    Guanine  ('G'),
    Cytosine ('C'),
    RNA consists of the following bases:
    Adenine  ('A'),
    Uracil   ('U'),
    Guanine  ('G'),
    Cytosine ('C'),
    The data is DNA if at least 90% of the bases are one of the DNA bases.
    The data is RNA if at least 90% of the bases are one of the RNA bases.
    The data is invalid if more than 10% of the bases are not one of the DNA or RNA bases.
    Empty bases should be ignored.
    """
    DNA_Counter = 0
    RNA_Counter = 0
    Base_Count = 0
    for tup in dna:
        for base in tup:
            if base != "":
                if base in "ATGC":
                    DNA_Counter += 1
                if base in "AUGC":
                    RNA_Counter += 1
                Base_Count += 1

    DNA_Proportion = DNA_Counter / Base_Count
    RNA_Proportion = RNA_Counter / Base_Count

    if DNA_Proportion >= 0.9:
        return "DNA"
    elif RNA_Proportion >= 0.9:
        return "RNA"
    else:
        return "Invalid"


def clean_dna(dna):
    """
    Given DNA in the aforementioned format,
    If the pair is incomplete, ('A', '') or ('', 'G'), ect
    Fill in the missing base with the match base.
    In DNA 'A' matches with 'T', 'G' matches with 'C'
    In RNA 'A' matches with 'U', 'G' matches with 'C'
    If a pair contains an invalid base the pair should be removed.
    Pairs of empty bases should be ignored.
    """
    DNA = False
    if is_rna(dna) == "DNA":
        DNA = True
    cleanDNA = []
    if DNA:
        for tup in dna:
            tup0 = tup[0]
            tup1 = tup[1]

            if tup0 == "" and tup1 == "":
                continue
            if tup0 not in "ATGC":
                continue
            if tup[0] == "":
                if tup[1] == "T":
                    tup0 = "A"
                elif tup[1] == "A":
                    tup0 = "T"
                elif tup[1] == "C":
                    tup0 = "G"
                elif tup[1] == "G":
                    tup0 = "C"

            if tup1 not in "ATGC":
                continue
            if tup[1] == "":
                if tup[0] == "T":
                    tup1 = "A"
                elif tup[0] == "A":
                    tup1 = "T"
                elif tup[0] == "C":
                    tup1 = "G"
                elif tup[0] == "G":
                    tup1 = "C"
            cleanDNA.append((tup0, tup1))

    if not DNA:
        for tup in dna:
            tup0 = tup[0]
            tup1 = tup[1]
            if tup0 == "" and tup1 == "":
                continue
            if tup0 not in "AUGC":
                continue
            if tup[0] == "":
                if tup[1] == "U":
                    tup0 = "A"
                elif tup[1] == "A":
                    tup0 = "U"
                elif tup[1] == "C":
                    tup0 = "G"
                elif tup[1] == "G":
                    tup0 = "C"
            tup1 = tup[1]
            tup1 = tup[1]
            if tup1 not in "AUGC":
                continue
            if tup[1] == "":
                if tup[0] == "U":
                    tup1 = "A"
                elif tup[0] == "A":
                    tup1 = "U"
                elif tup[0] == "G":
                    tup1 = "C"
                elif tup[0] == "C":
                    tup1 = "G"
            cleanDNA.append((tup0, tup1))
    return (cleanDNA)


def mast_common_base(dna):
    """
    Given DNA in the aforementioned format,
    return the most common first base:
    eg. given:
    A <-> T
    G <-> C
    G <-> C
    C <-> G
    G <-> C
    T <-> A
    The most common first base is 'G'.
    Empty bases should be ignored.
    """
    counterDict = collections.Counter()

    for tup in clean_dna(dna):
        counterDict[tup[0]] += 1
    mostOccuring = counterDict.most_common(1)
    return (mostOccuring[0][0])


def base_to_name(base):
    """
    Given a base, return the name of the base.
    The base names are:
    Adenine  ('A'),
    Thymine  ('T'),
    Guanine  ('G'),
    Cytosine ('C'),
    Uracil   ('U'),
    return the string "Unknown" if the base isn't one of the above.
    """
    if base == "A":
        return "Adenine"
    if base == "T":
        return "Thymine"
    if base == "G":
        return "Guanine"
    if base == "C":
        return "Cytosine"
    if base == "U":
        return "Uracil"

    return "Invalid"
