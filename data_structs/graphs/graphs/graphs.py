
""" A implementation of the data structure Graph """
from graphs.edges import Edge

class Vertex:
    """   (int) -> Vertex

    Represent a vertex b and its bidirectional and undirectional edges  
            A <--> B <--> C
            A -> B -> C
    """

    def __init__(self, data=None) -> None:
        """ (Int) -> Vertex object
        >>> node_a = Vertex(10)
        >>> node_a.data
        10
        >>> node_a.in_edge, node_a.out_edge
        None, None
                 
        """
        self.__data = data
        
        # Attributes that will point to other Vertex Object
        self.__edge = Edge(src_vertex=self, dest_vertex=None)
        
    def get_data(self) -> int:
        """ Return the data value """
        return self.__data
    
    def get_edge(self) -> int:
        """ Return the edge Object of this Vertex """
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
    
    def update_edge(self, src, dest) -> None:
        """ (vertex, vertex) -> None
        It will change the src and dest attributes at its vertex's edge

        >>> vertex_a.get_edge()__dict__
        {'__src_vertex': vertex_a, '__dest_vertex': vertex_b, 'weight':1.0}
        >>> vertex_a.update_get(vertex_h, vertex_g)
        >>> vertex_a.get_edge()__dict__
        {'__src_vertex': vertex_h, '__dest_vertex': vertex_g, 'weight':1.0}
         """
        self.__edge.update_edge(src, dest)

    def replace_edge(self, new_edge: Edge):
        """
        Overwite the reference to an edge a to the new_edge object
        """
        self.__edge = new_edge

    def point_to(self, vertex: "Vertex", direct=False) -> None:
        """    
        Make this edge object point to the given Vertex, and changes the edge of the given Vertex.

        >>> vertex_a.get_edge()
        <An Edge Object x>
        >>> vertex_b.get_edge()
        <An Edge Object y>
        >>> vertex_a.point_tio(vertex_b)
        >>> vertex_a.get_edge().get_dest_vertex()
        <Vertex  Object b>
        >>> vertex_b.get_get() == vertex_a.get_edget()
        True
        """
    
        if (self.__edge.get_dest_vertex() == None):
            self.__edge.to_vtx(vertex)
            if (not direct):
                vertex.update_edge(vertex, self)
             
        else:
            print(f"This vertex is already pointing to somewhere else!!!")
           
    
        
    def remove_edge(self) -> None:
        """
        Remove an existent vertex from edge attribute.

        >>> node_a.in_edge
        [node_b]
        >>> node_a.remove_edge(node_a.in_edge/out_edge)
        >>> node_a.in_edge/out_edge
        None  
        """
        if (self.__edge == None):
            raise Exception("the given argument is empty")

        else:
            del self.__edge
            self.__edge = None
         

class GraphSet:
    def __init__(self) -> None:
        """  (int) -> GraphSet
        Create a set of nodes/vertex
        >>> graph_x = GraphSet()
        >>> graph_x.vertex_set
        {}
        >>> graphs_a = GraphSet(3)
        >>> graphs_a.vertex_set
        {'a': <Vertex Object> , 'b': <Vertex Object>, 'c': <Vertex Object>}

        @param enumerated if True the keys become numbers
        """

        # if an argument is given, Create a list contaning (number_node) nodes with data None
        # else just create a empty list
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
                    self.__vertex_set[chr(label)].point_to(Vertex(None))
                else:
                    self.__vertex_set[chr(label)] = Vertex(None)
            self.__number_nodes = number_nodes
        else:
            # Generate a dictinary  {'0': <Vertex Object>, ... number_nodes} of length number_nodes

            for label in range(1, self.__number_nodes + 1):
                self.__vertex_set[label] = Vertex(None)
                    
                    
    def get_graphs(self):
        return self.__vertex_set
    
    def vertex_path(self, first_vtx) -> [Vertex]:
        """ (Vertex) -> [Vertex]
        Return a list of vertexes conected to each other
        >>> graphs_a = GraphSet(3)
        >>> graphs_a.vertex_set
        {'a': <Vertex Object> , 'b': <Vertex Object>, 'c': <Vertex Object>}
        >>> graphs_a.vertex_path("a")
        [<Vertex a Object> ,<Vertex b Object>]
        """
        current_vtx = first_vtx

        # iterate through all the path of vertexes starting from first_vtx
        c = 0
        path_list = []
        # if the graph path is undirect it will verify the last node
        is_last_vtx = current_vtx.get_edge().get_src_vertex() is current_vtx.get_edge().get_dest_vertex()
        while (current_vtx != None or is_last_vtx):
            print(f"\ncurrent data[{c}]:{current_vtx}")
            path_list.append(current_vtx)
            current_vtx = current_vtx.get_edge().get_dest_vertex()
            c+=1

            

        return path_list
        
    

