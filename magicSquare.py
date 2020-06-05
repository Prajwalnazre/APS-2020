#!/bin/python3

import math
import os
import random
import re
import sys
#import numpy as np

# Complete the formingMagicSquare function below.
def formingMagicSquare(s):
    allsum = [0 ,0]
    rowsum = [0,0,0]
    colsum = [0,0,0]
    for i in range(3):
        for j in range(3):
            #allsum[i] = allsum[i] + s[i][j]
            rowsum[i] = rowsum[i] + s[i][j]

    for j in range(3):
        for i in range(3):
            #allsum[i] = allsum[i] + s[i][j]
            colsum[i] = colsum[i] + s[i][j]

    allsum[0] = s[0][0] + s[1][1] + s[2][2]
    allsum[1] = s[0][2] + s[1][1] + s[2][0]

    for i in range(3):
        allsum.append(rowsum[i])
        allsum.append(colsum[i])

    magic = list()
   # magic = np.array([])
    magic = [[8    ,1    ,6],[3    ,5    ,7],[4    ,9    ,2]],[[6   ,1    ,8],[7    ,5    ,3],[2    ,9    ,4]],[[2    ,7    ,6],[9    ,5    ,1],[4    ,3    ,8]],[[2    ,9    ,4],[7    ,5    ,3],[6    ,1    ,8]],[[4    ,9    ,2],[3    ,5    ,7],[8    ,1    ,6]],[[6    ,7    ,2],[1    ,5    ,9],[8    ,3    ,4]],[[8    ,3    ,4],[1    ,5    ,9],[6    ,7    ,2]],[[4    ,3    ,8],[9    ,5    ,1],[2    ,7    ,6]]
    

    #magic1 = [[8    ,1    ,6],[3    ,5    ,7],[4    ,9    ,2]]
    #magic2 = [[6   ,1    ,8],[7    ,5    ,3],[2    ,9    ,4]]
    #magic3 = [[2    ,7    ,6],[9    ,5    ,1],[4    ,3    ,8]]
    #magic4 = [[2    ,9    ,4],[7    ,5    ,3],[6    ,1    ,8]]
    #magic5 = [[4    ,9    ,2],[3    ,5    ,7],[8    ,1    ,6]]
    #magic6 = [[6    ,7    ,2],[1    ,5    ,9],[8    ,3    ,4]]
    #magic7 = [[8    ,3    ,4],[1    ,5    ,9],[6    ,7    ,2]]
    #magic8 = [[4    ,3    ,8],[9    ,5    ,1],[2    ,7    ,6]]
    #magic = [magic1,magic2,magic3,magic4,magic5,magic6,magic7,magic8]

    #magic.append(magic1)
    #magic.append(magic2)
    #magic.append(magic3)
    ##magic.append(magic4)
    #magic.append(magic5)
    #magic.append(magic6)
    #magic.append(magic7)
    #magic.append(magic8) 

    
    diffsum = 0
    diffarr = [0,0,0,0,0,0,0,0]
    for i in range(len(magic)):
        for j in range(3):
            for k in range(3):
                diffsum = diffsum + abs(magic[i][j][k] - s[j][k])
        diffarr.append(diffsum)
        diffarr[i] = diffsum
        diffsum = 0
        #print("Diff " + str(diffarr[i]) )
    return min(diffarr)        


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = []

    for _ in range(3):
        s.append(list(map(int, input().rstrip().split())))

    result = formingMagicSquare(s)

    fptr.write(str(result) + '\n')

    fptr.close()

