#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the extraLongFactorials function below.
def extraLongFactorials(n,fact):
    #print(n)
    #print(fact)
    if n == 1 :
        print(1)
        return
    fact = fact * (n - 1)
    if n - 1 > 1 :
        extraLongFactorials(n - 1,fact)
    else :
        print(fact)
        return fact


if __name__ == '__main__':
    n = int(input())
    fact = n
    extraLongFactorials(n,fact)


