import sys
import csv

# if user does not put in command-line argument, return error, exit 1
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

with open(sys.argv[2], "r") as sequences:
    # read the dna sequence from file
    DNAsequence = csv.reader(sequences)
    for row in DNAsequence:
        dnalist = row

# store it in a string
dna = dnalist[0]
# create a dictionary to store count of consecutive repeats of STR
long_seq = {}

# extract sequence from databases into a list
with open(sys.argv[1]) as databases:
    people = csv.reader(databases)
    for rows in people:
        dna_seq = rows
        dna_seq.pop(0)
        break

for item in dna_seq:
    long_seq[item] = 1

for key in long_seq:
    # current longest run of the sequence 
    long_run = 0
    # current run of the sequence
    run = 0
    for i in range(len(dna)):
        # avoid recounting again
        while run > 0:
            run -= 1
            continue
        # if DNA == ley
        if dna[i:(i + len(key))] == key:
            # if there's repetition, increase count
            while dna[i - len(key):i] == dna[i:i + len(key)]:
                run += 1
                i += len(key)
            # As explained in walkthrough, comparing it against the previous longest sequence, if it is longer, replace the current longest sequence
            if run > long_run:
                long_run = run
    # update to the dictionary            
    long_seq[key] += long_run


# printing match
# reopen the closed file
with open(sys.argv[1], newline='') as databases:
    people = csv.DictReader(databases)
    # iliterate through the databases and comparing
    for individual in people:
        match = 0
        for dna in long_seq:
            if long_seq[dna] == int(individual[dna]):
                match += 1
        # compare the every sequence to every individual and print name if match, then end the program, else print "No match"
        if match == len(long_seq):
            name = individual['name']
            print(name)
            sys.exit(0)
    print('No match')
        
