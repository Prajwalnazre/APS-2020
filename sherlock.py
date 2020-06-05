#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the cost function below.
def cost(B):
    c = B.copy()
    d = B.copy()
    for i in range(len(B)):
        if i%2 == 0:
            c[i] = 1
        else:
            d[i] = 1
        
#print(c)
#print(d)

    sum1 = 0
    for i in range(len(B)):
        if i != len(B) - 1 :
        #print(str(B[i]) + " - " +str(B[i + 1]))
            diff1 = c[i] - c[i + 1]
            if diff1 < 0:
                diff1 = diff1/-1

            sum1 += diff1

    #print(sum1)

    sum2 = 0
    for i in range(len(B)):
        if i != len(B) - 1 :
        #print(str(B[i]) + " - " +str(B[i + 1]))
            diff2 = d[i] - d[i + 1]
            if diff2 < 0:
                diff2 = diff2/-1

            sum2 += diff2
        
        #print(sum2)

        sum3 = max(sum1,sum2)

    #print(sum3)
    return int(sum3)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        B = list(map(int, input().rstrip().split()))

        result = cost(B)

        fptr.write(str(result) + '\n')

    fptr.close()

