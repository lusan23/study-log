import unittest
from graphs.graphs import DirectVertex
from graphs.graphs import UndirectVertex
class TestVertex(unittest.TestCase):
    """Test the behavior of the vertex class"""
    def __init__(self, *args, **kwargs):
        super(TestVertex, self).__init__(*args, **kwargs)
        self.vertex_one = DirectVertex(10)

        self.vertex_two = DirectVertex(20) 

    def test_settup(self):
        """ Test if the data for an Vertex instance is stored in data."""
                
        self.assertEqual(self.vertex_one.get_data(), 10)
        self.assertEqual(self.vertex_two.get_data(), 20)
        
        self.assertEqual(self.vertex_one.get_edge().__dict__['_Edge__src_vertex'], self.vertex_one)
        self.assertEqual(self.vertex_one.get_edge().__dict__['_Edge__dest_vertex'], None)

    def test_update_data(self):
        """ Test if the vertes overwrites properly """
        test_filled_node = DirectVertex(20)
        test_empty_node = DirectVertex()
        
        test_filled_node.update_data(1000)
        
        print(f"\nmy public attribute:{test_filled_node.get_data()}\n")
        # self.assertEqual(test_filled_node.data, 1000)


    def test_edges(self):
        """ Test if the vertex A is has an edge to vertex B."""
        vertex_a = UndirectVertex(10)
        vertex_b = DirectVertex(20)
        vertex_c = DirectVertex(30)
        # testing undirect edge
        vertex_a.point_to(vertex_b)
        vertex_b.point_to(vertex_c)
        
        self.assertIs(vertex_a.get_edge(two=True).__dict__['_Edge__dest_vertex'], vertex_b)
        self.assertIs(vertex_b.get_edge(two=False).__dict__['_Edge__dest_vertex'], vertex_a)

        self.assertIs(vertex_b.get_edge(two=True).__dict__['_Edge__dest_vertex'], vertex_c)
        self.assertIs(vertex_c.get_edge(two=False).__dict__['_Edge__dest_vertex'], None)
        
        del vertex_a
        del vertex_b   
            
    def test_unpoint(self):
        
        vertex_a = DirectVertex("Chile")
        vertex_b = DirectVertex('Santiago')

        vertex_a.point_to(vertex_a)
        self.assertTrue(vertex_a.get_edge(two=True).__dict__['_Edge__dest_vertex'] != None)
        # remove the in_edge and check if it has actually removed
        vertex_a.unpoint()
        self.assertTrue(vertex_a.get_edge(two=True).__dict__['_Edge__dest_vertex'] == None)

    def test_path(self):
        vtx_a, vtx_b, vtx_c = DirectVertex('Buenos Aires'), DirectVertex('Paris'), DirectVertex('São Paulo')
        vtx_a.point_to(vtx_b), vtx_b.point_to(vtx_c)

        print(vtx_a.vertex_path())

    #     print("test ended")
        
