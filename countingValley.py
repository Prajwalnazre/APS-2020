#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):
    val = 0
    count = 0
    for i in range(n) :
        if s[i] == 'U' :
            val += 1
        if s[i] == 'D' :
            val -= 1
        if val == -1 :
            count += 1
    return int(count/2)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()

