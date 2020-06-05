#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the staircase function below.
def staircase(n):
    for i in range(1,n + 1) :
        j = 0
        while j != (n - i) :
            print(" ", end = "")
            j += 1
        while j != n :
            print("#", end = "")
            j += 1
        print("")

if __name__ == '__main__':
    n = int(input())
    staircase(n)

