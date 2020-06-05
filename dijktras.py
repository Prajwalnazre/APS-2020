class vertex(object):
    
    def __init__(self,name):
        self.name = name
        self.neighbours = []
        self.cost = []
        self.visit = 0
        self.mincost = 9999
        
   #def nameit(self,name):
    #    self.name = name
        
    def addNeighbour(self,nName,nCost):
        self.neighbours.append(nName)
        self.cost.append(nCost)
        
    #def visit(self):
    #   self.visit = 1
 
class graph(object):
    
    def __init__(self):
        self.vertices = []
        #self.src = vertex()
        #self.dest = vertex()
        self.q = []
        self.sum1 = 0
        
    def addVertex(self,vertex):
        self.vertices.append(vertex)
        
    def minNum(m,n):
        if(m < n):
            return m
        else:
            return n
    
    def findDest(self,src,dest):
        for i in range(len(self.vertices)):
            if(src.name == self.vertices[i].name):
                self.src = src
                print("Source Found")
            if(dest.name == self.vertices[i].name):
                self.dest = dest
                print("Dest.ination Found")
                
    def shortest(self):
        
        #for  i in range(len(self.vertices)):
        #    print(self.vertices[i].mincost)
            
        self.src.mincost = 0
        for  i in range(len(self.src.neighbours)):
            self.src.neighbours[i].mincost = self.src.cost[i]
            self.q.append(self.src.neighbours[i])
            
        self.src.visit = 1
        for j in range(len(self.q)):
            self.sum1 = self.q[j].mincost
            for k in range(len(self.q[j].neighbours)):
                self.sum1 = self.sum1 + self.q[j].cost[k]
                if self.sum1 < self.q[j].mincost:
                    self.q[j].mincost = self.sum1
                if self.q[j].visit == 0 :
                    self.q.append(self.q[j].neighbours[k])
                    
                #self.q[j].mincost = self.minNum(self.sum1,self.q[j].mincost)
                
            self.q[j].visit = 1
            
        for  i in range(len(self.vertices)):
            print(self.vertices[i].mincost)
                                 
v1 = vertex("1")
v2 = vertex("2")
v3 = vertex("3")
v4 = vertex("4")
v5 = vertex("5")
v1.addNeighbour(v2,1)
v1.addNeighbour(v3,2)
v2.addNeighbour(v3,7)
v2.addNeighbour(v4,5)
v3.addNeighbour(v5,1)
v4.addNeighbour(v3,3)
v4.addNeighbour(v5,7)
v5.addNeighbour(v1,1)

g = graph()
g.addVertex(v1)
g.addVertex(v2)
g.addVertex(v3)
g.addVertex(v4)
g.addVertex(v5)

g.findDest(v1,v5)







