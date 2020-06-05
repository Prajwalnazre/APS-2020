def root(a, i) :
    while a[i] != i :
        i = a[i]
    return i

def find(a, u, v) :
    if root(a, u) == root(a, v) :
        return 1
    else :
        return 0
    
def WeightedUnion(a, size, u, v) :
    rootA = root(a, u)
    rootB = root(a, v)
    size = []
    for i in range(len(a)) :
        size.append(1)
    if size[]
