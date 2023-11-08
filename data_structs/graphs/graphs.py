
""" A implementation of the data structure Graph """

class Vertex:
    """   (int) -> Vertex

    Represent a vertex b and its bidirectional and undirectional edges  
            A <--> B <--> C
            A -> B -> C
    """

    def __init__(self, data=None, out_edge=None, in_edge=None):
        """ (Int) -> Vertex object
        >>> node_a = Vertex(10)
        >>> node_a.data
        10
        >>> node_a.in_edge, node_a.out_edge
        None, None
                 
        """
        self.data = data
        

        # Attributes that will point to other Vertex Object
        self.in_edge = in_edge
        self.out_edge = out_edge

    

    def update_data(self, new_data: int):
        """ (int) -> int
        Overwrite the vertex's data and return the old  data
        """
        retval = self.data
        self.data = new_data
        return retval
    
    def point_to(self, vertex: "Vertex"):
        """  
        Make the current vertex point to another vertex object.
        a -> B
        >>> a.out_edge
        None
        >>> a.point_to(b)
        >>> a,out_edge
        <Vetex b object>
        """

        if (self.out_edge == None):
            self.out_edge = vertex
        else:
            print(f"This vertex is already pointing to somewhere else!!!")
           
        

    def pointed_by(self, vertex: "Vertex"):
        """  
        Make  A  point to B, it should be called if and only If B is ponting to A.

        A <--> B

        >>> a.
        [node_b,node_g]
        >>> node_a.add(node_b)
        >>> node_a.edges
        [node_b,node_g, node_b]
        """

        if (self.in_edge == None):
            self.in_edge = vertex
        else:
            print(f"This vertex is already been pointed!!!")
        
    def remove_edge(self, edge):
        """
        Remove an existent vertex from the in or out edge attribute.

        >>> node_a.in_edge
        [node_b]
        >>> node_a.remove_edge(node_a.in_edge)
        >>> node_a.in_edge
        None  
        """
        edge = None

        

class GraphSet:
    def __init__(self, number_nodes=None):
        """ 
        Create a set of nodes/vertex
        >>> graph_x = GraphSet()
        >>> graph_x.vertex_set
        []
        >>> graphs_a = GraphSet(3)
        >>> graphs_a.vertex_set
        [vertex object, vertex object , vertex object]
        """

        # if an argument is given, Create a list contaning (number_node) nodes with data None
        # else just create a empty list

        if (number_nodes != None):
            self.vertex_set = [ Vertex(None) for i in list( range(0,number_nodes) ) ]
        else:
            self.vertex_set = []
        
    

