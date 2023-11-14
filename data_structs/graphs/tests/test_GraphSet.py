from sys import path
import unittest

from graphs.graphs import GraphSet
from random import random

DICT_SIZE = 10

class TestGraphSet(unittest.TestCase):
    """Test the behavior of the vertex class"""
    def __init__(self, *args, **kwargs):
        super(TestGraphSet, self).__init__(*args, **kwargs)
        self.graph_set = GraphSet()
        self.filled_set = GraphSet()
 
        self.filled_set.set_vertexes(DICT_SIZE)
    def test_settup(self):
        """ Test if the nodes at the the instance are stored in properly. """

        # Verify if a empty graphset is 

        self.assertTrue(self.graph_set.get_graphs() == {})

        # Verify if a filled graphset is created properly


        self.assertTrue(self.filled_set.get_graphs() != {} and len(self.filled_set.get_graphs()) == DICT_SIZE)

        # for each vertex inside the graphset verify if their default values
        self.assertEqual(len(self.filled_set.get_graphs()), 10)
            
        for i in self.filled_set.get_graphs():
            self.assertTrue(self.filled_set.get_graphs()[i].get_data() == None) 
            self.assertTrue(self.filled_set.get_graphs()[i].get_edge() != None) 
            
    def test_graph_path(self):
        vtxs = self.filled_set.get_graphs()

        vtxs['a'].point_to(vtxs['b'], direct=False)

        path_list = self.graph_set.vertex_path(vtxs['a'])
        print(path_list)