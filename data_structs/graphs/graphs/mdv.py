import random
""" A implementation of the data structure Graph that handles multi-edge vertexes"""
from graphs.graphs import Vertex
from graphs.edges import Edge

class Mdv(Vertex):
    """   (int) -> Vertex
    # Multi Degree Vertex
    Represent an vertex that is connected (directionaly or undirectionaly) to more than one vertexes  

    >>> vtx = Mdv()
    """
    def __init__(self, data=None):
        super().__init__(data)    
        self.__edge_set = {}

    def add_edge(self, edge_name):
        """  
        Add an Edge object to the edge set
        >>> mdv = Mdv(10)
        >>> mdv.__dict__['_Mdv__edge_set']
        {}
        >>> mdv.add_edge('ab')
        >>> mdv.__dict__['_Mdv__edge_set']
        {'ab':<Edge Object>}
        """

        self.__edge_set[edge_name] = Edge(src_vertex=self)

    def point_to(self, vertex: Vertex, direct=False) -> None:
        """
        if the edge two is empty just do the usual point_to else,
        point to a given edge name at edge set.
        >>> mdv_a.point_to(mdv_b) 
        """
        # case one: ths mdv is not pointing to anyone, therefore __edge_two.__dest_vertex is None
        if (self.__dict__['_Vertex__edge_two'].get_dest_vertex() == None ):
            super().point_to(vertex, direct)
        else:
        # case two: this mdv already has one edge
            # what old be a good key name for that ? its memory addresss
            vertex[hex(id(self))] = Edge(src_vertex=self,dest_vertex=vertex)
