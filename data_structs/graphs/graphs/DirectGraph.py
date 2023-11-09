""" Implementation of a DirectGraph Set"""
from .graphs import GraphSet

class DirectGraphSet(GraphSet):
    """ 
    Represent a set of graphs with birectional edges  
    
    >>> set_a = DirecGraphSet()
    >>> set_a.vertex_set
    []
    """
    def __init__(self, number_nodes=None) -> None:
        super().__init__( number_nodes)

    
    


    

