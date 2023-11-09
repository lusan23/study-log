from sys import path
import unittest
from graphs.graphs import Vertex

class TestVertex(unittest.TestCase):
    """Test the behavior of the vertex class"""
    def __init__(self, *args, **kwargs):
        super(TestVertex, self).__init__(*args, **kwargs)
        self.vertex_one = Vertex(10)

        self.vertex_two = Vertex(20) 

    def test_settup(self):
        """ Test if the data for an Vertex instance is stored in data."""
                

        self.assertEqual(self.vertex_one.data, 10)
        self.assertEqual(self.vertex_one.in_edge, None)
        self.assertEqual(self.vertex_one.out_edge, None)
        del self.vertex_one


    def test_update_data(self):
        """ Test if the vertes overwrites properly """
        test_filled_node = Vertex(20)
        test_empty_node = Vertex()
        
        test_filled_node.update_data(1000)

        self.assertEqual(test_filled_node.data, 1000)


    def test_edges(self):
        """ Test if the vertex A is has an edge to vertex B."""
        self.vertex_a = Vertex(10)
        self.vertex_b = Vertex(20)

        
        self.vertex_a.point_to(self.vertex_b)
        self.vertex_b.pointed_by(self.vertex_a)
        
        self.vertex_b.point_to(self.vertex_a)
        self.vertex_a.pointed_by(self.vertex_b)
        
        self.assertIs(self.vertex_a.out_edge, self.vertex_b)
        self.assertIs(self.vertex_a.in_edge, self.vertex_b)



    def test_remove_edge(self):
        # 
        self.vertex_one.point_to(self.vertex_two)
        self.vertex_two.pointed_by(self.vertex_one)
        
        self.assertEqual(self.vertex_one.out_edge, self.vertex_two)
        self.assertEqual(self.vertex_two.in_edge, self.vertex_one)

        # remove the in_edge and check if it has actually removed
        self.vertex_one.remove_edge(self.vertex_one.out_edge)
        self.assertEqual(self.vertex_one.out_edge, None)

        self.vertex_one.remove_edge(self.vertex_two.in_edge)

        self.assertEqual(self.vertex_one.in_edge, None)

        # self.vertex_one = Vertex(10)
        # self.vertex_two = Vertex(20) 


       
        print("test ended")
        
