import unittest
from graphs.mdv import Mdv

class TestMdv(unittest.TestCase):
    """Test the behavior of the mdv class"""
    def __init__(self, *args, **kwargs):
        super(TestMdv, self).__init__(*args, **kwargs)
        self.vertex_one = Mdv(10)
        self.vertex_two = Mdv(20) 

    def test_set_up(self):
        """
        check the intregrity of attributes.
        """

        self.assertTrue(self.vertex_one.__dict__['_Mdv__edge_set'] == {})

    def test_point_to(self):
        self.vertex_one.point_to(self.vertex_two)
        vtx_c = Mdv(30)
        self.vertex_one.point_to(vtx_c)
        # self.assertEqual(self.vertex_one.get_edge(two=True).get_dest_vertex() is self.vertex_two)