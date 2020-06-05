#import numpy as np

no_of_lines = int(input())
#inputs = int()


inputs = list()
for i in range(no_of_lines):
    inputs+=input().split()

numarr = []
partarr = []

for i in range(no_of_lines*2):
    #print(i)
    if(i%2 == 0):
        num = int(inputs[i])
        numarr.append(num)
    else:
        part = int(inputs[i])
        partarr.append(part)
        
#print(numarr)
#print(partarr)
arr = []

def power2(n):
    for i in range(17):
        if(n == 2**i):
            return "YES"
        else:
            return "NO"

def power2(n):
    flag = 0
    for i in range(17):
        if(n == 2**i):
            flag = 1
    
    return flag

    
    
print(power2(2049))



for i in range(no_of_lines):
    if(numarr[i] < partarr[i]):
        print("NO")
         
    elif(numarr[i] == partarr[i]):
        print("YES")
    else:  
    #arr = np.zeros(partarr[i])
        for k in range(partarr[i]):
            arr.append(0)
            #print(arr)
        
        for j in range(numarr[i]):
            if(j >= partarr[i]):
                arr[j - partarr[i]] = arr[j - partarr[i]] + 1
                #print(arr)
            else:
                arr[j] = arr[j] + 1
                #print("else" + str(arr))  
                
        for l in range(len(arr)):
            result = power2(arr[l])
            
        
              
    #print(arr)

