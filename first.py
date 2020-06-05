n = int(input())

for i in range(n) :
    inputs = input().split()
    nums = int(inputs[0])
    lines = int(inputs[1])
    for j in range(lines) :
        line = input().split()
        p = int(input())
        oddCount = 0
        evenCount = 0
        for k in range(nums) :
            a = int(line[k]) ^ p
            count = bin(a)[2:].count('1')
            if count % 2 == 0 :
                evenCount += 1
            else :
                oddCount += 1
        print(str(evenCount) + " " + str(oddCount))
        
