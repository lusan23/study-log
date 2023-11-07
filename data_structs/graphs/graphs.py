
""" A implementation of the data structure Vertex """

class Vertex:
    """ Represent a vertex and its edges  """

    def __init__(self, data: int, edges=[]):
        self.data = data
        self.edges = edges
        
    def add_edge(self, vertex: "Vertex"):
        self.edges.append(vertex)

    def remove_edge(self, vertex: "Vertex"):

        for edge in self.edges:

            if id(edge) == id(vertex):
                self.edges.remove(edge)
                print("found!!!")
                break  

class VertexSet:
    def __init__(self):
        initial_vertex = Vertex(None)
        self.vertexs = [initial_vertex]

    def add_vertex(self, vertex_data: int):
        pass
    

