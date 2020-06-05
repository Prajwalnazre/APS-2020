n = int(input())

for i in range(n):
    inputs = input().split()
    #print(inputs)
    x = int(inputs[0])
    y = int(inputs[1])
    bud = int(inputs[2])
    num = int(inputs[3])
    diff = x - y
    if diff <= 0 :
        print("LuckyChef")
    nb = []
    for j in range(num):
        nb += input().split()
    
    flag = 0
    for k in range(0,len(nb),2):
        if int(nb[k]) >= diff :
            if int(nb[k + 1]) <= bud:
                flag = 1
                #print("LuckyChef")
                
    if flag == 0:
        print("UnluckyChef")
    else :
        print("LuckyChef")
        
    
        
