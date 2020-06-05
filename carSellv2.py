#def depreciate(arr) :
#    for i in range(len(arr)) :
#        if arr[i] > 0 :
#            arr[i] -= 1
#    return arr
    
def main() :
    n = int(input())

    for i in range(n) :
        profit = 0
        cars = []
        cars2 = []
        cars3 = []
        num = int(input())
        #cars = input().split()
        #for j in range(len(cars)) :
        #    cars2.append(int(cars[j]))
    
        cars = [int(cars) for cars in input().split()] 
        cars2 = sorted(cars, reverse = True)
        
        for j in range(len(cars2)) :
            cars3.append(cars2[j] - j)
            if cars3[j] < 0 :
                cars3[j] = 0
                
        profit = sum(cars3)
        #print(cars2)
        #for j in range(len(cars2)) :
        #   profit += cars2[0]
        #    cars2.pop(0)
        #    cars3 = depreciate(cars2)
        
        print(profit%1000000007)
        
if __name__ == "__main__":
    main()
    
    
    
    
