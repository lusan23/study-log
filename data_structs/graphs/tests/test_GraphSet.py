from sys import path
import unittest

from graphs.graphs import GraphSet
from random import random

class TestGraphSet(unittest.TestCase):
    """Test the behavior of the vertex class"""
    def __init__(self, *args, **kwargs):
        super(TestGraphSet, self).__init__(*args, **kwargs)
        self.graph_set = GraphSet()
        
    def test_settup(self):
        """ Test if the nodes at the the instance are stored in properly. """

        # Verify if a empty graphset is 

        self.assertTrue(self.graph_set.get_graphs() == {})

        # Verify if a filled graphset is created properly

        filled_set = GraphSet()
        filled_set.set_vertexes(10)
        self.assertTrue(filled_set.get_graphs() != {})

        # for each vertex inside the graphset verify if their default values

        print(f"dict:{filled_set.get_graphs()}")
        self.assertEqual(len(filled_set.get_graphs()), 10)
            
        for i in filled_set.get_graphs():
            print(filled_set.get_graphs()[i].get_data()) 
