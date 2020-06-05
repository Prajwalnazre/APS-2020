nocity = int(input())
nopaths = int(input())

inputs = []
for i in range(nopaths):
    inputs.append(input().split())

#print(inputs)
source = []
dest = []
cost = []
for i in range(nopaths):
    for j in range(3):
        if(j == 0):
            source.append(int(inputs[i][j]))
        if(j == 1):
            dest.append(int(inputs[i][j]))
        if(j == 2):
            cost.append(int(inputs[i][j]))
            

noqueries = int(input())

queries = []
for i in range(noqueries):
    queries.append(input().split())
       

qsource = []
qdest = []
qbudget = []

for i in range(noqueries):
    for j in range(3):
        if(j == 0):
            qsource.append(int(queries[i][j]))
        if(j == 1):
            qdest.append(int(queries[i][j]))
        if(j == 2):
            qbudget.append(int(queries[i][j]))
            
'''print(nocity)
print(nopaths)
print(source)
print(dest)
print(cost)
print(noqueries)
print(qsource)
print(qdest)
print(qbudget)
'''  
class vertex(object):
    
    def __init__(self,name):
        self.name = name
        self.visit = 0
        self.mincost = 99999
        self.neighbours = []

class edge(object):
    
    def __init__(self,v1,v2,cost):
        self.vertex1 = v1
        self.vertex2 = v2
        self.cost = cost
        
def retrievecost(e,v1,v2) :
    #print(str(e[1].vertex1.name) + " Specimen")
    for i in range(len(e)):
        #print(str(e[i].vertex1.name) + " - " + str(e[i].vertex2.name))
        if (e[i].vertex1.name == v1.name and e[i].vertex2.name == v2.name) :
            return int(e[i].cost)
        if v1.name == v2.name:
            return 0
        
def defneighbours(e) :
    e1 = []
    e2 = []
    for i in range(len(e)):
        e1.append(e[i].vertex1)
        #print(e1[i].name)
    #e2.append(e1[0])
    for j in range(len(e1)):
        #print(j)
        if e1[j] not in e2:
            e2.append(e1[j])
        
    for k in range(len(e2)):
        for l in range(len(e)):
            if e2[k] == e[l].vertex1:
                e2[k].neighbours.append(e[l].vertex2)
                
                
class graph(object):
    
    def __init__(self):
        self.vertices = []
        self.edges = []
        self.queue = []
        self.sum1 = 0
        
    def addvertex(self,v):
        self.vertices.append(v)
        
    def addedge(self,e):
        self.edges.append(e)
        
    def enqueue(self,q):
        self.queue.append(q)
        
    def dequeue(self):
        self.queue.pop(0)
        
    def shortpath(self,v,v2,bud):
        self.enqueue(v)
        self.src = v
        self.src.mincost = 0
     #  for i in  range(len(self.edges)):
     #       print(str(self.edges[i].vertex1.name) + " - " + str(self.edges[i].vertex2.name))
            
        while self.src.visit != 1 :
            #print("SRC " + str(self.src.name))
            for i in range(len(self.src.neighbours)):
                #print("SRC Mincost " + str(self.src.mincost))
                #print("Neighbour " + str(self.src.neighbours[i].name))
                #print(retrievecost(self.edges,self.src,self.src.neighbours[i]))
                self.sum1 = self.src.mincost + retrievecost(self.edges,self.src,self.src.neighbours[i])
                #self.sum1 = self.src.mincost + self.src.neighbours[i]
                #print("Sum " + str(self.sum1))
                if self.sum1 < self.src.neighbours[i].mincost:
                    self.src.neighbours[i].mincost = self.sum1
                 #   print("Queue Face - " + str(self.queue[0].name))
                self.queue.append(self.src.neighbours[i])
            self.src.visit = 1
            self.dequeue()
            if len(self.queue) > 0 :
                #print("Queue Again Face- " + str(self.queue[0].name) + "\n")
                self.src = self.queue[0]
        
        #for i in range(len(self.vertices)):
            #print(str(self.vertices[i].name) + " - " + str(self.vertices[i].mincost) + "\n")
        
        if( int(v2.mincost) <= int(bud)) :
            return 1
        else:
            return 0
            
        self.queue = [] 
        
        
v = []
ve = []
ed = []
'''
for i in range(len(source)):
    if source[i] not in v :
        v.append(source[i])
        
if len(v) != int(nocity) :
    for j in range(len(dest)):
        if(dest[i] not in v):
            v.append(dest[i])
            
for i in range(len(v)):
    ve.append(vertex(v[i]))
'''

for i in range(nocity):
    ve.append(vertex(i))

for i in range(nopaths):
    for j in range(len(ve)):
        if str(ve[j].name) == str(source[i]):
            va = ve[j]
        if str(ve[j].name) == str(dest[i]):
            vb = ve[j]
    ed.append(edge(va,vb,int(cost[i])))
    
defneighbours(ed)

g = graph()

for i in range(len(ve)):
    g.addvertex(ve[i])
    
for j in range(len(ed)):
    g.addedge(ed[j])
    
#print(str(ve[0].neighbours[0].name))
#print(ed[1].vertex1.name)
ans = []
for i in range(int(noqueries)):
    for j in range(len(ve)):
        #print("Finding S and D")
        if(str(ve[j].name) == str(qsource[i])):
            v1 = ve[j]
            #print("Source Found")
        if(str(ve[j].name) == str(qdest[i])):
            v2 = ve[j]
            #print("Destination Found")
            
    #print(g.shortpath(v1,v2,int(qbudget[i])))
	ans.append(g.shortpath(v1,v2,int(qbudget[i])))

if 0 in ans :
	print("NO")
else :
	print("YES")    
	#g.shortpath(v1,v2,int(qbudget[i]))

#print(ed[0].vertex1.name)
#print(ed[0].vertex2.name)
#print(ed[0].cost)
#print(ed[1].vertex1.name)
#print(ed[1].vertex2.name)
    
    
