#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the breakingRecords function below.
def breakingRecords(scores):
    minimum = scores[0]
    minCount = 0
    maxCount = 0
    maximum = scores[0]
    for i in range(1, len(scores)) :
        if scores[i] > maximum :
            maximum = scores[i]
            maxCount += 1
        if scores[i] < minimum :
            minimum = scores[i]
            minCount += 1

    return maxCount,minCount

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

