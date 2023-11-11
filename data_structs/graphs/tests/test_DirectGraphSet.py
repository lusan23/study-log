""" Tests for the DirectGraphSet class """
from sys import path
from random import random
import unittest


from graphs.DirectGraph import DirectGraphSet

class TestDirectGraph(unittest.TestCase):
    """ Test the behavior of the DGS class """

    def __init__(self, *args, **kwargs):
        super(TestDirectGraph, self).__init__(*args, **kwargs)

        self.graph_set_empty = DirectGraphSet()
        self.graph_set = DirectGraphSet()
        self.graph_set.set_vertexes(3)
    def test_settup(self):

        # check the integrity when a empty DGS
        self.assertEqual({}, self.graph_set_empty.get_graphs())



            

        


  

        
