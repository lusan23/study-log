import graphviz
from heap import Heap
hp = Heap()
hp.set_name("Heap Data Structure")
dot = graphviz()
dot.Digraph(comment=hp.name)

def set_nodes(hp):
    """
    insert a couple of nodes to the heap
    """
    hp.insert(hp.root,10)
    hp.insert(hp.root,20)
    hp.insert(hp.root,30)
    
    hp.insert(hp.root,40)
    hp.insert(hp.root,50)
    hp.insert(hp.root,60)

print(hp.root.__dict__)