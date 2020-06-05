n = int(input())

for i in range(n) :
    list1 = input().split()
    numOfBaskets = int(list1[0])
    types = int(list1[1])
    fruits = input().split()
    intFruits = []
    for j in range(len(fruits)) :
        intFruits.append(int(fruits[j]))
    price = input().split()
    priceArr = []
    for j in range(1,types + 1) :
        total = 0
        flag = 0
        for k in range(numOfBaskets) :
            if j == intFruits[k] :
                flag = 1
                total += int(price[k])
            if j not in intFruits :
                flag = 0
                
        if flag != 0 :
            priceArr.append(total)    
    print(min(priceArr))
