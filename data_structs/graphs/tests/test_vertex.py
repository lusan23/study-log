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
                

        self.assertEqual(self.vertex_one.get_data(), 10)
        self.assertEqual(self.vertex_two.get_data(), 20)
        
        self.assertEqual(self.vertex_one.get_edge().__dict__['_Edge__src_vertex'], self.vertex_one)
        self.assertEqual(self.vertex_one.get_edge().__dict__['_Edge__dest_vertex'], None)
        self.vertex_one = None
        self.vertex_two = None

    def test_update_data(self):
        """ Test if the vertes overwrites properly """
        test_filled_node = Vertex(20)
        test_empty_node = Vertex()
        
        test_filled_node.update_data(1000)
        
        print(f"\nmy public attribute:{test_filled_node.get_data()}\n")
        # self.assertEqual(test_filled_node.data, 1000)


    def test_edges(self):
        """ Test if the vertex A is has an edge to vertex B."""
        vertex_a = Vertex(10)
        vertex_b = Vertex(20)
        vertex_c = Vertex(30)
        # testing undirect edge
        vertex_a.point_to(vertex_b, direct=False)
        vertex_b.point_to(vertex_c, direct=True)
        
        self.assertIs(vertex_a.get_edge(two=True).__dict__['_Edge__dest_vertex'], vertex_b)
        self.assertIs(vertex_b.get_edge(two=False).__dict__['_Edge__dest_vertex'], vertex_a)

        self.assertIs(vertex_b.get_edge(two=True).__dict__['_Edge__dest_vertex'], vertex_c)
        self.assertIs(vertex_c.get_edge(two=False).__dict__['_Edge__dest_vertex'], None)
        


        del vertex_a
        del vertex_b   
            
    def test_unpoint(self):
        
        vertex_a = Vertex("Chile")
        vertex_b = Vertex('Santiago')

        vertex_a.point_to(vertex_a)
        self.assertTrue(vertex_a.get_edge(two=True).__dict__['_Edge__dest_vertex'] != None)
        # remove the in_edge and check if it has actually removed
        vertex_a.unpoint()
        self.assertTrue(vertex_a.get_edge(two=True).__dict__['_Edge__dest_vertex'] == None)

    def test_path(self):
        vtx_a, vtx_b, vtx_c = Vertex('Buenos Aires'), Vertex('Paris'), Vertex('São Paulo')
        vtx_a.point_to(vtx_b), vtx_b.point_to(vtx_c)

        print(vtx_a.vertex_path())

    #     print("test ended")
        
