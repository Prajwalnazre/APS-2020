n = 15
a = [3,5,10]

res = [0 for i in range(n + 1)]
#print(res)

ind = [ [] for i in range(n + 1)]
ind2 = [ [] for i in range(n + 1)]

res[0] = 1

i = 0

for j in range(3,n + 1):
    #print(str(j) + " - " + str(j - a[i]))
    if res[j - a[i]] > 0 :
        res[j] += res[j - a[i]]
        ind[j].append(j - a[i])
        ind2[j].append(a[i])
        
i = i + 1

for j in range(5,n + 1):
    #print(str(j) + " - " + str(j - a[i]))
    if res[j - a[i]] > 0 :
        res[j] += res[j - a[i]]
        ind[j].append(j - a[i])
        ind2[j].append(a[i])
    
i = i + 1

for j in range(10,n + 1):
    #print(str(j) + " - " + str(j - a[i]))
    if res[j - a[i]] > 0 :
        res[j] += res[j - a[i]]
        ind[j].append(j - a[i])
        ind2[j].append(a[i])
        
print(res)
print(ind)
print(ind2)

#def rec():
l = []
l2 = []
for i in range(len(ind[15])):
    j = 0
    n = 15
    l.append(ind2[15][j])
    while n != 0 :
        if len(ind[ind[n][i]]) == 1 :
            l.append(ind2[ind[n][i]])
            print(ind2[ind[n][i]][0])
            n = n - ind2[ind[n][i]][0]
        
    l2.append(l)
    
print(l2)
    
