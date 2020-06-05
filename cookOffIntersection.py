import  time 
import datetime
import math

#n = int(input())

n = 1



def dateinfo(year,month,day) :
    while year >= 10000 :
        x = math.log(year,10)
        year = year - (28 ** (x - 2)) 
        
    start1 = datetime.datetime(int(year), int(month), day)
    #end1 = datetime.datetime(int(year), int(month), day)
    w1 = start1.strftime("%w")
    #w2 = end1.strftime("%w")
    noOfDays = 31
    if int(month) == 2 :
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
    if int(month) == 4 or int(month) == 6 or int(month) == 9 or int(month) == 11 :
        noOfDays = 30 
    
    return int(w1),int(noOfDays)    
    
start = [5,100010]
end = [9, 120000]

for i in range(n) :
    intersect = 0
    #start = input().split()
    #end = input().split()
    if int(end[0]) < 2 and int(start[0]) <= 2 :
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
        for j in range(int(start[1]) + 1,int(end[1]) + 1) :
            weekday, days = dateinfo(j,2,1)
            if weekday == 6 :
                if days <= 29 :
                    print(j )
                    intersect += 1
            if weekday == 0 :
                if days == 28 :
                    print(j)
                    intersect += 1
                    
    if int(start[0]) > 2 and int(end[0]) < 2 :
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
        
