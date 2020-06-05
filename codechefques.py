import  time 
import datetime
import math

n = int(input())

def dateinfo(year,month,day) :
    #while year >= 10000 :
    #    x = math.log(year,10)
    #    year = year - (28 ** (x - 2)) 
    
    #w1 = " "
    if int(year) >= 10000 : 
        print(year)
        diff = int(year) - 10000
        print("Diff " + str(diff))
        diff = diff/28
        print("DIV " + str(diff))
        year = year - int((diff + 1) * 28)
        print(year)
    
    
    
    #if year == 0 :
    #    w1 = "2"
    #    noOfDays = 29
    #else :    
    start1 = datetime.datetime(int(year), int(month), day)
    #end1 = datetime.datetime(int(year), int(month), day)
    w1 = start1.strftime("%w")
    #w2 = end1.strftime("%w")
    noOfDays = 28
    #if int(month) == 2 :
    if (int(year) % 4) == 0:
        if (int(year) % 100) == 0:
            if (int(year) % 400) == 0:
                noOfDays = 29
            else:
                noOfDays = 28
        else:
            noOfDays = 29
    else:
        noOfDays = 28
    
    print("W1 " + str(w1))
    print("No " + str(noOfDays))
    
    return int(w1),int(noOfDays)    
    

    
    
def findIntersection(startY, endY, var) :
    intersect = var
    j = startY
    l = endY
    year = 0
    while j % 400 != 0 :
        #intersectFlag = 0
        #year = 0
        #for j in range(int(start[1]),int(start[1]) + 6) :
        #while intersectFlag == 0 :
            #year += 1
        weekday, days = dateinfo(j,2,1)
        if weekday == 6 :
            if days <= 29 :
                #print(j)
                #intersectFlag = 1
                intersect += 1
        if weekday == 0 :
            if days == 28 :
                #print(j)
                #intersectFlag = 1
                intersect += 1
        j += 1
        

    year = 0
    while l % 400 != 0 :
        #year = 0
        #intersectFlag = 0
        #for j in range(int(start[1]),int(start[1]) + 6) :
        #while intersectFlag == 0 :
        #    year += 1
        weekday, days = dateinfo(l,2,1)
        if weekday == 6 :
            if days <= 29 :
                    #print(l)
                #intersectFlag = 1
                intersect += 1
        if weekday == 0 :
            if days == 28 :
                print(l)
                #intersectFlag = 1
                intersect += 1
        l = l - 1
    
    j = j - 1    
    l = l + 1
    
    intersect += int(((l - j)/400) * 101)
    #print(intersect)
    #print("J = " + str(j - 7))
    #print("L = " + str(l + 1))
    #print("L - J divided by 28 = " + str(((l + 1) - (j - 7) )/28))
    #intersect = intersect + (7 * (int(((l + 1) - (j - 7))/28))) - 

    return intersect
                
for i in range(n) :
    start = input().split()
    end = input().split()
    intersect = 0
    var = 0
    if int(end[0]) < 2 and int(start[0]) <= 2 :
        #for l in range(7) :
        if int(start[1]) - int(end[1]) > 1200 :
            intersect = findIntersection(int(start[1]), int(end[1]) - 1, var)
        else :
            for j in range(int(start[1]),int(end[1])) :
                weekday, days = dateinfo(j,2,1)
                if weekday == 6 :
                    if days <= 29 :
                        #print(j)
                        intersect += 1
                if weekday == 0 :
                    if days == 28 :
                        #print(j)
                        intersect += 1

        
    if  int(end[0]) >= 2 and int(start[0]) <= 2 :
        if int(start[1]) - int(end[1]) > 1200 :
            intersect = findIntersection(int(start[1]), int(end[1]), var)
        else :
            for j in range(int(start[1]),int(end[1]) + 1) :
                weekday, days = dateinfo(j,2,1)
                if weekday == 6 :
                    if days <= 29 :
                        #print(j)
                        intersect += 1
                if weekday == 0 :
                    if days == 28 :
                        #print(j)
                        intersect += 1

                    
    if int(start[0]) > 2 and int(end[0]) >= 2 :
        if int(start[1]) - int(end[1]) > 1200 :
            intersect = findIntersection(int(start[1]) + 1, int(end[1]), var)
        else :
            for j in range(int(start[1]) + 1,int(end[1]) + 1) :
                weekday, days = dateinfo(j,2,1)
                if weekday == 6 :
                    if days <= 29 :
                        #print(j)
                        intersect += 1
                if weekday == 0 :
                    if days == 28 :
                        #print(j)
                        intersect += 1
                    
    if int(start[0]) > 2 and int(end[0]) < 2 :
        if int(start[1]) - int(end[1]) > 1200 :
            intersect = findIntersection(int(start[1]) + 1, int(end[1]) - 1, v)
        else :
            for j in range(int(start[1]) + 1,int(end[1])) :
                weekday, days = dateinfo(j,2,1)
                if weekday == 6 :
                    if days <= 29 :
                        #print(j)
                        intersect += 1
                if weekday == 0 :
                    if days == 28 :
                        #print(j)
                        intersect += 1    #for k in range()
            
    print(intersect)
        
        
        
    
