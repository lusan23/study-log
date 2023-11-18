
""" A implementation of the data structure Graph """
from graphs.edges import Edge

class Vertex:
    """   (int) -> Vertex

    Represent a vertex b and its directional/undirectional edges  
    """

    def __init__(self, data=None) -> None:
        """ (Int) -> Vertex object

        Takes data an Edges that point to other vertexes
                 
        """
        self.__data = data
        
        # Attributes that will point to other Vertex Object
        self.__edge = Edge(src_vertex=self, dest_vertex=None)
        self.__edge_two = Edge(src_vertex=self, dest_vertex=None)

    def get_data(self) -> int:
        """ Return the data value """
        return self.__data
    
    def get_edge(self, two=False) -> Edge:
        """ Return the edge Object of this Vertex """
        if (two):
            return self.__edge_two
        else:
            return self.__edge

    def update_data(self, new_data: int) -> int:
        """### (int) -> int
        
        ###Overwrite the vertex's data and RETURN the old data
        
        >>> node_a.get_data()
        10000
        >>> node_a.update(20)
        10000 # returned after removed
        >>> node_a.get_data()
        20

        """
        retval = self.__data
        self.__data = new_data
        return retval
    
    def __update_edge(self, src, dest, two=True) -> None:
        """ (vertex, vertex) -> None

        It will change the src and dest attributes at its vertex's edge

        >>> vertex_a.get_edge()__dict__
        {'__src_vertex': vertex_a, '__dest_vertex': vertex_b, 'weight':1.0}
        >>> vertex_a.update_get(vertex_h, vertex_g)
        >>> vertex_a.get_edge()__dict__
        {'__src_vertex': vertex_h, '__dest_vertex': vertex_g, 'weight':1.0}
         """
        
        # Error handling

        # if src or dest is not None and not type Vertex raise an exception. 
        if (not type(src) != None or not type(dest) != None):    
            if (not isinstance(src, Vertex) or not isinstance(dest, Vertex)):
                raise TypeError(f"Expected an instace of {Vertex}, but received {type(src), type(dest)}")
        two_type = type(two)

        # make sure that two is a boolean value
        if (two_type != bool):
            raise TypeError("Expected an instance of {bool}, but received {two_type}")
            
        if (not two):
            self.__edge.update_edge(src, dest)
        else:
            self.__edge_two.update_edge(src, dest)

    def replace_edge(self, new_edge: Edge):
        """
        Overwite the reference to an edge a to the new_edge object
        """
        self.__edge = new_edge

    def point_to(self, vertex: "Vertex", direct=False) -> None:
        """    
        Make this edge object point to the given Vertex, and changes the edge of the given Vertex.
      
        """
        if (not direct):    
            if (self.__edge_two.get_dest_vertex() == None):
                self.__edge_two.update_edge(self, vertex)
                vertex.__update_edge(vertex, self, two=False)
                
                                
            else:
                print(f"This vertex is already pointing to somewhere else!!!")
            
        else:
            if (self.__edge_two.get_dest_vertex() == None):
                self.__edge_two.update_edge(self, vertex)
            else:
                print(f"This vertex is already pointing to somewhere else!!!")
            
        
    def unpoint(self) -> None:
        """
        Remove an existent vertex from edge attribute.

        """
        if (self.__edge == None):
            raise Exception("the given argument is empty")

        else:
            del self.__edge
            self.__edge_two.update_edge(new_source=self, new_destiny=None)
         


    def vertex_path(self) -> list:
        """ (Vertex) -> [Vertex]
        Return a list of vertexes conected to each other
   
        """
        current_vtx = self

        
        c = 0
        path_list = []
        prev_vtx = current_vtx
        # iterate through all the path of vertexes starting from first_vtx
        while (current_vtx != None):
            path_list.append(current_vtx)

            prev_vtx = current_vtx
            current_vtx = current_vtx.get_edge(two=True).get_dest_vertex()
            c+=1

        
        return path_list

class GraphSet:
    def __init__(self) -> None:
        """  (int) -> GraphSet
        Create a set of nodes/vertex
     

        @param enumerated if True the keys become numbers
        """

        self.__vertex_set = {}
        self.__number_nodes = None
        self.__enumerated = None


    def set_vertexes(self, number_nodes=None, enumerated=False) -> None:
        # Create an dict of {str: <Vertex Object>}

        if (not self.__enumerated):    
            # Generate a dictinary  {'a': <Vertex Object>, ... number_nodes} of length number_nodes
            for label in range(ord('a'), ord('a') + number_nodes):
                if (label < number_nodes):
                    self.__vertex_set[chr(label)] = Vertex(None)
                    
                else:
                    self.__vertex_set[chr(label)] = Vertex(None)
            self.__number_nodes = number_nodes
        else:
            # Generate a dictinary  {'0': <Vertex Object>, ... 'number_nodes-1':<Vertex Object>} of length number_nodes

            for label in range(1, self.__number_nodes + 1):
                self.__vertex_set[label] = Vertex(None)
                    
    def link_all(self,  direct=False):
        """ ()
            Link all the vertexes in the set by the created order.
        """

        if (self.__vertex_set == {}):
            raise Exception("The vertex set is empty!!!")
        elif (len(self.__vertex_set) == 1):
            raise Exception("The vertex set has only a single vertex, there's nothing to link with.")
            
        vtxs = self.__vertex_set
        vtxs_keys = list(vtxs.keys())
        counter = 0
        
        # this loop stop at the (i number_nodes-2)th vertex 
        while counter <= len(vtxs_keys)-2:
            # vtx_i will point to vtx_i + 1
            if (not direct):
                vtxs[vtxs_keys[counter]].point_to(vtxs[vtxs_keys[counter+1]])
            else:
                vtxs[vtxs_keys[counter]].point_to(vtxs[vtxs_keys[counter+1]], direct=True)
            counter+=1
             
    def get_graphs(self):
        return self.__vertex_set
    
    def adjascent_list(self) -> [Vertex]:
        """ (None) -> dict of [Vertex]
        Return a list of paths of each vertex in vertex_set 
        >>> graphs_a = GraphSet()
        >>> graphs_a.set_vertexes(3)
        >>> len(graphs_a.get_graphs())
        3
        >>> graphs_a.adjascent_list(0)
        
        [ 
            [<Vertex a Object> ... Vertex n Object>] , 
            [<Vertex b Object> ... <Vertex n Object>],
            [<Vertex c Object> ... <Vertex n Object>] , 
        ]
            
        """
        # make a adjct_dict
        adjct_dict = {}
        # iterate for each vtx in vertex_set and get its path
        for key in list(self.__vertex_set.keys()):
            adjct_dict[key] = self.__vertex_set[key].vertex_path()
        
        return adjct_dict