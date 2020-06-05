#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the viralAdvertising function below.
def viralAdvertising(n):
    cumulative = 0
    shared = 5
    liked = 0
    for i in range(n) :
        liked = int(shared/2)
        cumulative += liked
        shared = int(3 * liked)
    return cumulative



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    result = viralAdvertising(n)

    fptr.write(str(result) + '\n')

    fptr.close()

