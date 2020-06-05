#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    #print(s[1])
    st = list(s)
    if st[8] == "A" :
        if st[0] == "1" and st[1] == "2" :
            st[0] = "0"
            st[1] = "0"
    else :
        num = int(s[:2])
        #if st[0] != "1" and st[1] != "2" :
        if num != 12 :
            num += 12
            num = str(num)
            st[0] = num[0]
            st[1] = num[1]
            #ans = ''.join(st)
    ans = ''.join(st)
    return ans[:8]

        
if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()

