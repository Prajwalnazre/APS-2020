
def permute(data, i, length): 
    if i==length: 
        #a.join(data)
        #print(''.join(data) )
        #print(data)
        countx = 0
        county = 0
        for i in range(len(data)):
            if(data[i] == 'X'):
                countx += 1
            else:
                county += 1
                if(countx < county):
                    print('Not')
            #print(data)
        #print(a)
    else: 
        for j in range(i,length): 
            #swap
            data[i], data[j] = data[j], data[i] 
            permute(data, i+1, length) 
            data[i], data[j] = data[j], data[i]  


string = "XXXYYY"
n = len(string) 
data = list(string) 
permute(data, 0, n)
