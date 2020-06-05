#Assignment Problem
from itertools import combinations

c = [0,1]

cost = [[3,2,7],[1,6,5],[2,4,7]]
dp = []
for i in range(pow(2,len(cost))) :
    dp.append(100000)

dp[0] = 0

def countSetBits(n) :
    a = bin(n)
    print(a)
    count = 0
    x
            

#for i in range(pow(2,len(cost))) :
#    x = countSetBits(i)
    #print(x)
#    for j in range(len(cost)) :
#        if i & (1<<j) != i :
#            dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + cost[x][j])
            
#print(dp)
print(countSetBits(7))

