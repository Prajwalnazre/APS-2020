n = 15
a = [3,5,10]

res = [0 for i in range(n + 1)]
#print(res)

ind = []

res[0] = 1

i = 0

for j in range(3,n + 1):
    #print(str(j) + " - " + str(j - a[i]))
    if res[j - a[i]] > 0 :
        res[j] += res[j - a[i]]
        #ind.append(j - a[i])
        
    
    
i = i + 1

for j in range(5,n + 1):
    #print(str(j) + " - " + str(j - a[i]))
    if res[j - a[i]] > 0 :
        res[j] += res[j - a[i]]
    
i = i + 1

for j in range(10,n + 1):
    #print(str(j) + " - " + str(j - a[i]))
    if res[j - a[i]] > 0 :
        res[j] += res[j - a[i]]
        
print(res)


