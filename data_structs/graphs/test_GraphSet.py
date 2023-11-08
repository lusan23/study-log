import unittest
from graphs import Vertex, GraphSet
from random import random

class TestGraphSet(unittest.TestCase):
    """Test the behavior of the vertex class"""
    def __init__(self, *args, **kwargs):
        super(TestGraphSet, self).__init__(*args, **kwargs)
        self.nodes = GraphSet()
        
    def test_settup(self):
        """ Test if the nodes at the the instance is stored in properly. """

        self.assertEqual(self.nodes.vertex_set, [])

        filled_set = GraphSet(3)
        
        self.assertEqual( len( filled_set.vertex_set ), 3)

        # for each vertex in  the graph set verify if all have None data

        for vertex in filled_set.vertex_set:
            self.assertEqual(None, vertex.data)

        

if __name__ == "__main__":
    unittest.main()