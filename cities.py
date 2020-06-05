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
    for i in range(len(e)):
        #print(str(e[i].vertex1.name) + " - " + str(e[i].vertex2.name))
        if (e[i].vertex1 == v1 and e[i].vertex2 == v2) :
            return e[i].cost
        if v1 == v2:
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
        
    def shortpath(self,v):
        """
        self.src = v
        self.src.mincost = 0
        self.src.visit = 1
        for i in range(len(self.edges)):
            if self.src.visit != 1 : 
                if self.edges[i].vertex1 == self.src   :
                    self.sum1 = self.sum1 + self.edges[i].vertex2.mincost
                    #if edges[i].cost < edges[i].vertex2.mincost :
                    if self.edges[i].cost < self.sum1
                        self.edges[i].vertex2.mincost = self.sum1
        """
        
        self.enqueue(v)
        self.src = v
        self.src.mincost = 0
        while self.src.visit != 1 :
            print("SRC " + str(self.src.name))
            for i in range(len(self.src.neighbours)):
                print("SRC Mincost " + str(self.src.mincost))
                print("Neighbour " + str(self.src.neighbours[i].name))
                self.sum1 = self.src.mincost + retrievecost(self.edges,self.src,self.src.neighbours[i])
                print("Sum " + str(self.sum1))
                if self.sum1 < self.src.neighbours[i].mincost:
                    self.src.neighbours[i].mincost = self.sum1
                    print("Queue Face - " + str(self.queue[0].name))
                self.queue.append(self.src.neighbours[i])
            self.src.visit = 1
            self.dequeue()
            if len(self.queue) > 0 :
                print("Queue Again Face- " + str(self.queue[0].name) + "\n")
                self.src = self.queue[0]
        
        for i in range(len(self.vertices)):
            print(str(i + 1) + " - " + str(self.vertices[i].mincost))
            
        self.queue = [] 
        
       
v1 = vertex("1")
v2 = vertex("2")
v3 = vertex("3")
v4 = vertex("4")
v5 = vertex("5")
v6 = vertex("6")

e = []
e1 = edge(v1,v2,12)
e.append(e1)

e2 = edge(v1,v5,1)
e.append(e2)

e3 = edge(v1,v6,12)
e.append(e3)

e4 = edge(v2,v4,7)
e.append(e4)

e5 = edge(v1,v3,2)
e.append(e5)

e6 = edge(v5,v6,2)
e.append(e6)

e7 = edge(v5,v3,6)
e.append(e7)

e8 = edge(v6,v4,3)
e.append(e8)

e9 = edge(v6,v2,8)
e.append(e9)

defneighbours(e)

g = graph()

g.addvertex(v1)
g.addvertex(v2)
g.addvertex(v3)
g.addvertex(v4)
g.addvertex(v5)
g.addvertex(v6)

g.addedge(e1)
g.addedge(e2)
g.addedge(e3)
g.addedge(e4)
g.addedge(e5)
g.addedge(e6)
g.addedge(e7)
g.addedge(e8)
g.addedge(e9)



g.shortpath(v4)
#print("||")
#print(retrievecost(e,v1,v5))
#print(v1.neighbours[0].name)
#print(v1.neighbours[1].name)
#print(v1.neighbours[3].name)
#print(v1.neighbours[2].name)
#g.vertices[0].mincost = 8888
#print(g.vertices[0].mincost)
#print(e1.vertex1.mincost) 
    


