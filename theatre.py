#from itertools import permutations 

n = int(input())

profitarr = []

def calc(p, cost) :
    prof = 0
    for i in range(4) :
        if p[i] == 0 :
            prof += -100
        else :
            prof += p[i] * cost[i]
    
    return prof
    

for i in range(n) :
    m = int(input())
    arr = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    profit = 0
    #cost = [[100,75,50,25],[75,100,25,50],[50,25,75,100],[25,50,100,75]]
    cost = [[100, 75, 50, 25], [100, 75, 25, 50],
            [100, 50, 75, 25], [100, 50, 25, 75], 
            [100, 25, 75, 50], [100, 25, 50, 75],
            [75, 100, 50, 25], [75, 100, 25, 50],
            [75, 50, 100, 25], [75, 50, 25, 100], 
            [75, 25, 100, 50], [75, 25, 50, 100],
            [50, 100, 75, 25], [50, 100, 25, 75], 
            [50, 75, 100, 25], [50, 75, 25, 100],
            [50, 25, 100, 75], [50, 25, 75, 100],
            [25, 100, 75, 50], [25, 100, 50, 75], 
            [25, 75, 100, 50], [25, 75, 50, 100], 
            [25, 50, 100, 75], [25, 50, 75, 100]]   
    for j in range(m) :
        inputs = input().split()
        if inputs[0] == 'A' :
            row = 0
        if inputs[0] == 'B' :
            row = 1
        if inputs[0] == 'C' :
            row = 2
        if inputs[0] == 'D' :
            row = 3
        if inputs[1] == '12' :
            col = 0
        if inputs[1] == '3' :
            col = 1
        if inputs[1] == '6' :
            col = 2
        if inputs[1] == '9' :
            col = 3
            
        arr[row][col] += 1
       
    arr1 = arr.copy()
    

    #perm = permutations([0, 1, 2, 3], 4) 
    li = [[0, 1, 2, 3], [0, 1, 3, 2],
            [0, 2, 1, 3], [0, 2, 3, 1],
            [0, 3, 1, 2], [0, 3, 2, 1], 
            [1, 0, 2, 3], [1, 0, 3, 2], 
            [1, 2, 0, 3], [1, 2, 3, 0], 
            [1, 3, 0, 2], [1, 3, 2, 0], 
            [2, 0, 1, 3], [2, 0, 3, 1], 
            [2, 1, 0, 3], [2, 1, 3, 0],
            [2, 3, 0, 1], [2, 3, 1, 0],
            [3, 0, 1, 2], [3, 0, 2, 1], 
            [3, 1, 0, 2], [3, 1, 2, 0], 
            [3, 2, 0, 1], [3, 2, 1, 0]] 
    #for a in list(perm): 
	#    li.append(list(a))
	     
    #print(li[22])
    
    #print(arr)
    secProfArr = []
    for j in range(24) :
        for k in range(len(li)) :
            p = []
            for l in range(4) :
                p.append(arr[l][li[k][l]])
            #print(p)
            #print(cost[j])
            secProfArr.append(calc(p,cost[j]))
            
    print(max(secProfArr))
    #print(secProfArr)
    profitarr.append(max(secProfArr))
                
print(sum(profitarr))
        
#print(calc([3, 0, 1, 0],[100,50,75,25]))

                
    
                
            
            
            
            
            
            
            
