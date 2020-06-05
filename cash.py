n = int(input())

def diffun(n,m) :
    q = int(int(n) / m)
    diff = (q + 1)*m - int(n)
    return diff
        

    

for i in range(n) :
    s = input().split()
    c = input().split()
    
    num = int(s[0])
    div = int(s[1])
    
    
    m = []
        
    for cn in range(num + 1):
        coin = 0
        diffsum = 0
        for j in range(cn) :
            rem = int(c[j]) % div 
            coin += rem
            
        #print("First " + str(coin))
            
        for k in range(cn,num) :
            q = int(int(c[k]) / div)
            #print(q)
            diff = (q + 1)*div - int(c[k])
            #print(diff)
            diffsum = diffsum + diff
            #print("Coin gone " + str(coin))
            
        x = coin - diffsum
        #print(coin)
        #print(x)
        if x >= 0 :
            m.append(x)
            
    print(min(m))
            
        
    
    
