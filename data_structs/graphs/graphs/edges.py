""" Implementation of Edges as an Object, storing two 'pointers' and an weight data"""
class Edge:
    """ (float, Vertex, Vertex) -> Edge

    ### Work like an bridge between Vertex Objects.

    >>> edge_ab = Edge(1.0, vertex_a, vertex_b)
    >>> edge_ab.__dict__
    {"weight":1.0, "from":vertex_a, "to": vertex_b}
    
    """
    def __init__(self, src_vertex = None, 
                 dest_vertex = None, weight=999999,) -> "Edge":
        """
        @param src_vertex the vertex object where the edge is comming from.
        @param dest_vertex the vertex object where the edge is pointing to.
        """
        self.__weight = weight
        self.__src_vertex = src_vertex
        self.__dest_vertex = dest_vertex


    # Functions to check attributes.
    def get_weight(self):
        return self.__weight
    
    def get_src_vertex(self):
        return self.__src_vertex
    
    def get_dest_vertex(self):
        return self.__dest_vertex
    
    def update_weight(self, new_weight: float) -> float: 
        """ 
        ### Change the weight of the edge and return the old weight value.
        >>> edge_ab.get_weight()
        1.0
        >>> old_weight = edge_ab.update_weight(4.7)
        >>> edge_ab.get_weight
        4.7
        >>> old_weight
        1.0
        
        """
        retval = self.__weight
        self.__weight = new_weight
        return retval

    def __from_vtx(self, vertex, direct=False) -> None:
        """
        ### Define from what Vertex object the edge is comming from. 
        
        >>> edge_one.get_src_vertex()
        vertex_a
        >>> edge_one.from_vtx(vertex_h)
        >>> edge_one.get_src_vertex()
        vertex_h
        

        """

        if (direct):
            self.__src_vertex = vertex
            return None

        if (self.__src_vertex == None):
            self.__src_vertex = vertex
        else:
            raise Exception("This attribute is already filled!!!")
        

    def __to_vtx(self, vertex, direct=False) -> None:
        """
        ### Define where the edge is ponting to what Vertex 
        
        >>> edge_one.get_dest_vertex()
        vertex_b
        >>> edge_one.to_vtx(vertex_h)
        >>> edge_one.get_dest_vertex()
        vertex_h
        """
        if (direct):
            self.__dest_vertex = vertex
            return None

        if (self.__dest_vertex == None):
            self.__dest_vertex = vertex
        else:
            raise Exception("This attribute is already filled!!!")

    def update_edge(self, new_source, new_destiny):
        """ (vertex, vertex) -> None
        
            It will change the src and dest attributes at this edge

        """
        self.__from_vtx(new_source, direct=True)
        self.__to_vtx(new_destiny, direct=True)
