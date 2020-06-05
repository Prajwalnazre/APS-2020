n = int(input())

for i in range(n) :
    m = int(input())
    l = input().split()
    b = input().split()
    ls = []
    bs = []
    for k in range(m) :
        ls.append(int(l[k]))
        bs.append(int(b[k]))
        
    ls1 = sorted(ls)
    bs1 = sorted(bs)
    #print(ls1)
    #print(bs1)
    minarr = []
    for j in range(m) :
        if ls1[j] < bs1[j] :
            minarr.append(int(ls1[j]))
        else :
            minarr.append(int(bs1[j]))
    
    #print(minarr)
    print(sum(minarr))
    
