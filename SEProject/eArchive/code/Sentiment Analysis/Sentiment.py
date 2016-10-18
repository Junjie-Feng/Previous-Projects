__author__ = 'kk'

from textblob.sentiments import NaiveBayesAnalyzer

# read the local txt file
lines = [line.strip('\n') for line in open('result.txt')]

# the posValue and the negValue
pos = 0
neg = 0

# the posCount and the negCount
posCount = 0
negCount = 0

# initialize the NaiveBayesAnalyzer
analyzer = NaiveBayesAnalyzer()

print("===== Start =====")

print("Training Analyzer...")

# analyze every tweets
for line in range(len(lines)):

    # get the results
    analyze = analyzer.analyze(lines[line])

    print("Analyzing tweet " + str(line + 1) + "....")

    # count the pos tweets and neg tweets
    if analyze[0] == "pos":
        posCount += 1
    else:
        negCount += 1

    # add the value to pos and neg
    pos += analyze[1]
    neg += analyze[2]

print("===== Finished =====")

print("Results:")
print("pos count VS neg count:", posCount, negCount)

print("posValue VS negValue", pos, neg)
