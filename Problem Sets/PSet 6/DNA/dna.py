# importing library 
from sys import argv
from csv import reader, DictReader

# using built-in function len()
if len(argv) <= 2:
    print("Usage Python dna.py data.csv sequence.txt")
    exit(1)

# open file and read
with open(argv[2]) as list:
    rDNA = reader(list)
    
    for row in rDNA:
        list = row

# save in string
dna = list[0]

# create a dictionary
sequences = {}

with open(argv[1]) as pfile:
    namepessoa = reader(pfile)
    for row in namepessoa:
        dnaSequences = row
        dnaSequences.pop(0)
        break

for item in dnaSequences:
    sequences[item] = 1

for key in sequences:
    count = len(key)
    # Temporary
    tempcommon = 0
    # Temporary 
    tTotal = 0

    for i in range(len(dna)):

        while tempcommon > 0:
            tempcommon -= 1
            continue

        if dna[i: i + count] == key:
            while dna[i - count: i] == dna[i: i + count]:
                tempcommon += 1
                i += count

            if tempcommon > tTotal:
                tTotal = tempcommon

    sequences[key] += tTotal

with open(argv[1], newline='') as pfile:
    namepessoa = DictReader(pfile)

    for person in namepessoa:
        match = 0

        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1

        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")