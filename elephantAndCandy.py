num = int(input())

inputs = []
a = []

for i in range(2 * num):
    if i%2 == 0 :
        inputs += list(input().split())
    else :
        a += list(input().split())
 
#print(inputs)
#print(a)
k = 0
for i in range(0,2 * num,2):
    n = int(inputs[i])
    c = int(inputs[i + 1])
    #print("N " + str(n))
    #print("C Before " + str(c))
    for j in range(k,n + k):
        #print("A " + str(a[j]))
        c = c - int(a[j])
        #print("C " + str(c))
    k = n + k
    #print("K " + str(k))    
    if c < 0 :
        print("No")
    else :
        print("Yes")
