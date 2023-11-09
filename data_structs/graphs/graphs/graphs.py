
""" A implementation of the data structure Graph """

class Vertex:
    """   (int) -> Vertex

    Represent a vertex b and its bidirectional and undirectional edges  
            A <--> B <--> C
            A -> B -> C
    """

    def __init__(self, data: int =None, out_edge=None, in_edge=None) -> None:
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


    def update_data(self, new_data: int) -> int:
        """ (int) -> int
        
        Overwrite the vertex's data and RETURN the old data
        
        >>> node_a.data
        10000
        >>> node_a.update(20)
        10000 # returned after removed
        >>> node_a.data
        20

        """
        retval = self.data
        self.data = new_data
        return retval
    
    def point_to(self, vertex: "Vertex") -> None:
        """  
        Make the current vertex point to another vertex object.
        a -> B
        >>> a.out_edge
        None
        >>> a.point_to(b)
        >>> a,out_edge
        <Vetex B object>
        """

        if (self.out_edge == None):
            self.out_edge = vertex
        else:
            print(f"This vertex is already pointing to somewhere else!!!")
           
        

    def pointed_by(self, vertex: "Vertex") -> None:
        """  
        Make  A  point to B, it should be called if and only If B is ponting to A.

        A <--> B

        >>> a.in_edge
        None
        >>> node_a.pointed_by(node_b)
        >>> node_a.in_edge
        <Vertex B Object> 
        """

        if (self.in_edge == None):
            self.in_edge = vertex
        else:
            print(f"This vertex is already been pointed!!!")
        
    def remove_edge(self, edge: "Vertex") -> None:
        """
        Remove an existent vertex from the in or out edge attribute.

        >>> node_a.in_edge
        [node_b]
        >>> node_a.remove_edge(node_a.in_edge/out_edge)
        >>> node_a.in_edge/out_edge
        None  
        """
        if (edge == None):
            raise Exception("the given argument is empty")

        if (edge is self.in_edge):
            self.in_edge = None
        elif (edge is self.out_edge):
            self.out_edge = None

        

class GraphSet:
    def __init__(self, number_nodes=None, enumerated=False) -> None:
        """  (int) -> GraphSet
        Create a set of nodes/vertex
        >>> graph_x = GraphSet()
        >>> graph_x.vertex_set
        {}
        >>> graphs_a = GraphSet(3)
        >>> graphs_a.vertex_set
        {'a': <Vertex Object> , 'b': <Vertex Object>, }

        @param enumerated if True the keys become numbers
        """

        # if an argument is given, Create a list contaning (number_node) nodes with data None
        # else just create a empty list

        if (number_nodes != None):
            # Dict {str : Vertex }
            self.vertex_set = {}

            if (not enumerated):
                    
                # Generate a dictinary  {'a': <Vertex Object>, ... number_nodes}
                for label in range(ord('a'), ord('a') + number_nodes):
                    self.vertex_set[chr(label)] = Vertex(None)
            else:
                # Generate a dictinary  {'0': <Vertex Object>, ... number_nodes}
                for label in range(1, number_nodes + 1):
                    self.vertex_set[label] = Vertex(None)
                    
        else:
            self.vertex_set = {}
        
    

