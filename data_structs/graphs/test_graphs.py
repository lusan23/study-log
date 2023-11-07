import unittest
from graphs import Vertex
from random import random

class TestVertex(unittest.TestCase):
    """Test the behavior of the vertex class"""

    def test_settup(self):
        one_vertex = Vertex(10)
        vertex_two = Vertex(20) 
 
        self.assertEqual(one_vertex.data, 10)
        self.assertEqual(vertex_two.data, 20)

        del one_vertex
        del vertex_two


    def test_add_edge(self):
        vertex_one = Vertex(10)
        vertex_two = Vertex(20)

        vertex_one.add_edge(vertex_two)
        vertex_two.add_edge(vertex_one)

        self.assertIn(vertex_two, vertex_one.edges)
        self.assertIn(vertex_one, vertex_two.edges)

        del vertex_one
        del vertex_two


    def test_remove_edge(self):

        vertex_one = Vertex(10)
        vertex_two = Vertex(20)
        vertex_one.add_edge(vertex_two)
        vertex_two.add_edge(vertex_one)

        vertex_one.remove_edge(vertex_two)
        self.assertNotIn(vertex_two, vertex_one.edges)
       
        print(vertex_one.edges[0].data)
        pass
        

if __name__ == "__main__":
    unittest.main()