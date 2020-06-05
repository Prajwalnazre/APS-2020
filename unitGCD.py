n = int(input())

for i in range(n) :
    num = int(input())
    if num > 4 :
        print(int(num/2))
        print("3 1 2 3")
        for j in range(4,num + 1,2) :
            if j + 1 <= num :
                print("2 " + str(j) + " " + str(j + 1))
            else :
                print("1 " + str(j))
    else :
        if num == 1 :
            print("1")
            print("1 1")
        if num == 2 :
            print("1")
            print("2 1 2")
        if num == 3 :
            print("1")
            print("3 1 2 3")
        if num == 4 :
            print("2")
            print("3 1 2 3")
            print("1 4")
