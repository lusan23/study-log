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

        self.assertTrue(self.graph_set.vertex_set == {})

        # Verify if a filled graphset is created properly

        filled_set = GraphSet(10, enumerated=True)

        self.assertTrue(filled_set.vertex_set != {})

        # for each vertex inside the graphset verify if their default values

        print(f"dict:{filled_set.vertex_set}")
        self.assertEqual(len(filled_set.vertex_set), 10)
            

