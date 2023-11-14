from sys import path
import unittest
from graphs.edges import Edge
from graphs.graphs import Vertex

class TestEdge(unittest.TestCase):
    """Test the behavior of the Edge class"""
    def __init__(self, *args, **kwargs):
        super(TestEdge, self).__init__(*args, **kwargs)
        # Setting up a basic graph Cidade A -> Cidade B  
        self.vertex_a = Vertex("Rio de Janeiro")
        self.vertex_b = Vertex("São Paulo")
        self.distance_ab = Edge(weight=18.1,src_vertex=self.vertex_a,
                            dest_vertex=self.vertex_b) # 18.1 km
        
    def test_setup(self):
        print(f"\nattributes:{self.vertex_a.__dict__}")

        pass
        

        



