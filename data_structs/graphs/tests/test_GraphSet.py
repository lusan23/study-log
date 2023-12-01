from sys import path
import unittest

from graphs.graphs import DirectGraphSet
from random import random

DICT_SIZE = 10

class TestGraphSet(unittest.TestCase):
    """Test the behavior of the vertex class"""
    def __init__(self, *args, **kwargs):
        super(TestGraphSet, self).__init__(*args, **kwargs)
        self.graph_set = DirectGraphSet()
        self.filled_set = DirectGraphSet()
 
        self.filled_set.set_vertexes(DICT_SIZE)
    def test_settup(self):
        """ Test if the nodes at the the instance are stored in properly. """

        # Verify if a empty graphset is 

        self.assertTrue(self.graph_set.get_graphs() == {})

        # Verify if a filled graphset is created properly

        length = len(self.filled_set.get_graphs())
        self.assertTrue(self.filled_set.get_graphs() != {} and length == DICT_SIZE)

        # for each vertex inside the graphset verify if their default values
        self.assertEqual(len(self.filled_set.get_graphs()), 10)
            
        for i in self.filled_set.get_graphs():
            self.assertTrue(self.filled_set.get_graphs()[i].get_data() == None) 
            self.assertTrue(self.filled_set.get_graphs()[i].get_edge() != None) 

    def test_link(self):
        """
        test if all the vertexes were connected properly
        
        Test Cases

        1. vertex set is empty
        2. only one vertex 
        3. vertex set hsa 10 vertexes

        """
        # UNDIRECT LINK TEST
        self.filled_set.link_all()

        vtxs = self.filled_set.get_graphs()
        vtxs_keys = list(vtxs.keys())

        counter = 0
        
        # this loop stop at the (i number_nodes-2)th vertex 
        while counter <= len(vtxs_keys)-2:
            # verify if vtx_i points to vtx_i + 1
            edge = vtxs[vtxs_keys[counter]].get_edge(two=True)
            self.assertIs(edge.get_dest_vertex(), vtxs[vtxs_keys[counter+1]] )

            src_edge = vtxs[vtxs_keys[counter+1]].get_edge()
            self.assertIs(src_edge.get_dest_vertex(), vtxs[vtxs_keys[counter]] )
            
            counter+=1

            # DIRECT LINK TEST
            cities = DirectGraphSet()
            cities.set_vertexes(5)

            cities.link_all(direct=True)
            vtxs = cities.get_graphs()
            vtxs_keys = list(vtxs.keys())
            counter = 0
            
            # this loop stop at the (i number_nodes-2)th vertex 
            while counter <= len(vtxs_keys)-2:
                # verify if vtx_i points to vtx_i + 1

                edge = vtxs[vtxs_keys[counter]].get_edge(two=True)
                self.assertIs(edge.get_dest_vertex(), vtxs[vtxs_keys[counter+1]] )

                src_edge = vtxs[vtxs_keys[counter+1]].get_edge()
                self.assertIs(src_edge.get_dest_vertex(), None)
                counter+=1

    def test_adjacest_list(self):
        # testing vertex path
        # setting up graphset
        cities_gs = DirectGraphSet()
        cities_gs.set_vertexes(5)

        # all vertexes have path length 1, because they start without edges.
        cities = cities_gs.get_graphs()

        # ponting a to b, to the path length of a should be 2 
        cities['a'].point_to(cities['b'])
        adjacenst_list = cities_gs.adjascent_list()
        self.assertTrue(len(adjacenst_list['a']) == 2)

    
