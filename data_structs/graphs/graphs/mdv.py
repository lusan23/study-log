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

    def get_edges(self) -> dict:
        """
        Return the attribtue __edge_set
        """

        return self.__edge_set
    def __update_edge(self, src, dest, two=True) -> None:
        """ (Vertex/Mdv, Vertex/Mdv) -> None

        It will change the src and dest attributes at its vertex's edge

        """
        # Error handling

        two_type = type(two)

        # make sure that two is a boolean value
        if (two_type != bool):
            raise TypeError("Expected an instance of {bool}, but received {two_type}")
            
        if (not two):
            if (self.__dict__['_Vertex__edge'].get_dest_vertex() == None):
                self.__dict__['_Vertex__edge'].update_edge(src, dest)
            else:
                self.__edge_set[hex(id(dest))] = Edge(src_vertex=self, dest_vertex=dest)

        else:
            self.__edge_two.update_edge(src, dest)


    def point_to(self, vertex: Vertex, direct=False) -> None:
        """ (Vertex) -> None or Int(base=16)(iff it's added in set_edges)

        with edge two is already been used, create a new edge and point to the given vertex

        >>> mdv_a.point_to(mdv_b) 
        
        """
        # case one: ths mdv is not pointing to anyone, therefore __edge_two.__dest_vertex is None
        if (self.__dict__['_Vertex__edge_two'].get_dest_vertex() == None ):  
            if (not direct):    
                    if (self.__dict__['_Vertex__edge_two'].get_dest_vertex() == None):
                        self.__dict__['_Vertex__edge_two'].update_edge(self, vertex)
                        vtx_one = vertex.get_edge()
                        # if th given vertex is not being pointed just complete undirectional edge
                        if (vtx_one.get_dest_vertex() == None):    
                            vertex.__update_edge(vertex, self, two=False)

                        elif( type(vertex) == Mdv):
                            edges_pointed_mdv = vertex.get_edges()
                            key = hex(id(self))
                            edges_pointed_mdv[key] = Edge(vertex, self)
                            return key
                        else:

                        # if it's a vtx just tell that it's being already pointed.
                            raise Exception(f"The object {type(vertex)} is already been pointed!! You might consider point to an Mdv object.")
                        
                                    
                    else:
                        print(f"This vertex is already pointing to somewhere else!!!")
                
            else:
                if (self.__edge_two.get_dest_vertex() == None):
                    self.__edge_two.update_edge(self, vertex)
                else:
                    print(f"This vertex is already pointing to somewhere else!!!")
            return None
        else:
        # case two: this mdv already has one edge
        # creates an new edge at edge set and point to the given vertex
            
            key = hex(id(vertex))
            edges = self.__edge_set
            edges[key] = Edge(src_vertex=self,dest_vertex=vertex)
            
            # if there's no other vtx pointing to the given vertex just complete the undirect edge.
            edge_one = vertex.get_edge()
            if (edge_one.get_dest_vertex() == None):    
                edge_one.update_edge(vertex, new_destiny=self)
                
                return key

            # if the given vtx is already been poninted and is a mdv subclass, 
            # create a new edge to complete the undirectoinal edge
            elif( type(vertex) == Mdv):
                edges_pointed_mdv = vertex.get_edges()
                key = hex(id(self))
                edges_pointed_mdv[key] = Edge(vertex, self)
                return key
            else:

            # if it's a vtx just tell that it's being already pointed.
                raise Exception(f"The object {type(vertex)} is already been pointed!! You might consider point to an Mdv object.")
           
          