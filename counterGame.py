#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the counterGame function below.
def counterGame(n):
    count = 0
    while n != 1 :
        if (n & (n - 1)) == 0 :
            n = n >> 1
            count += 1
        else :
            m = bin(n)
            m2 = int(m[3:],2)
            n = n - m2
            count += 1
    
    if n == 1 :
        return "Richard"
    elif count % 2 == 0 :
        return "Louise"
    else :
        return "Richard"


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        result = counterGame(n)

        fptr.write(result + '\n')

    fptr.close()

