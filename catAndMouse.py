#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the catAndMouse function below.
def catAndMouse(x, y, z):
    diff1 = z - x
    if diff1 < 0 :
        diff1 = int(diff1/-1)
    diff2 = y - z
    if diff2 < 0 :
        diff2 = int(diff2/-1)
    if diff1 < diff2 :
        return "Cat A"
    elif diff1 > diff2 :
        return "Cat B"
    else :
        return "Mouse C"
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        xyz = input().split()

        x = int(xyz[0])

        y = int(xyz[1])

        z = int(xyz[2])

        result = catAndMouse(x, y, z)

        fptr.write(result + '\n')

    fptr.close()

