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
    coin = 0
    
    for j in range(num) :
        coin += int(c[j])
        
    a = coin % div

    print(a)            
        
    
    
