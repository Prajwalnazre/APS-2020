def denseRank(arr) :
    rank = 1
    rankArr = []
    rankArr.append(rank)
    for i in range(1, len(arr)) :
        if arr[i - 1] == arr[i] :
            rankArr.append(rank)
        else :
            rank += 1
            rankArr.append(rank)
    return rankArr

def insertArr(arr, ele, ranks) :
    for i in range(len(arr)) :
        if ele > arr[i] :
            arr.insert(i,ele)
            ranks = denseRank(arr)
            #if arr[i - 1] == arr[i] :
            #    for j in range(i + 1, len(ranks)) :
            #        ranks[j] += 1
            #else :
            #    for j in range(i, len(ranks)) :
            #        ranks[j] += 1
            #print(arr)
            #print(ranks)
            break
        if i == len(arr) - 1 :
            arr.append(ele)
            ranks.append(ranks[len(ranks) - 1] + 1)
            #print(arr)
            #print(ranks)
            i = len(ranks) - 1
            break
             
    return arr, ranks[i]

def rankTim(scores, tim):
    rank = 0
    ranks = denseRank(scores)
    ansArr = []
    for i in range(len(tim)) :
        scores, rank = insertArr(scores, tim[i], ranks)
        #ansArr.append(rank)
		print(rank)
    #return ansArr
        
        
n = int(input())

scores1 = input().split()
scores = []
for i in range(n) :
	scores.append(int(scores1[i]))

m = int(input())

tim1 = input().split()
tim = []
for i in range(n) :
	scores.append(int(tim1[i]))

#result = rankTim(scores, tim)
rankTim(scores, tim)

#for i in range(len(result)) :
#	print()


