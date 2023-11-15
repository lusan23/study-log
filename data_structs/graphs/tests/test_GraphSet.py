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
            
    def test_adjacest_list(self):
        # testing vertex path
        # setting up graphset
        cities_gs = GraphSet()
        cities_gs.set_vertexes(5)
        # all vertexes have path length 1, because they start without edges.
        cities = cities_gs.get_graphs()
        # ponting a to b, to the path length of a should be 2 
        cities['a'].point_to(cities['b'])
        adjacenst_list = cities_gs.adjascent_list()
        self.assertTrue(len(adjacenst_list['a']) == 2)
