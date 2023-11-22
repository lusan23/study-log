import unittest
from graphs.mdv import Mdv
from graphs.graphs import Vertex

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
        """
        Testing the behavior of the method point_to in the mdv subclass.

        Test Case

        | `vertex_edge_two` is empty | `vertex.__edge_two.__dest_vtx == None` | class |Action | Return Value |
        UNDIRECTIONAL LINKS
        | --- | --- | --- | --- |
        | False | True | Create a new edge to point to the given vertex, return key of the pointed vertex at `set_edge` and set vertex.__edge.__dest_vertex to point to self| key | mdv
        | False | False | Create a new edge to point to the given vertex and create a new edge at the given vertex to point back, return key of the pointed vertex at `set_edge` and creates a new edge | key | mdv

        | --- | --- | --- | --- |
        | True | True | Handled by edge method | None | not mdv
        | True | False | Handled by edge method | None | not mdv
        | False | True | Create a new edge to point to the given vertex, return key of the pointed vertex at `set_edge`| key | mdv
        | False | False | Create a new edge to point to the given vertex and create a , return key of the pointed vertex at `set_edge` and creates a new edge | key | mdv

        """
        # Mdv <--> Vertex
        self.vertex_one.point_to(self.vertex_two)
        vtx_c = Vertex(30)
        self.vertex_one.point_to(vtx_c)
        vone_edge_two = self.vertex_one.get_edge(two=True)
        
        v2_edge = self.vertex_two.get_edge(two=False)
        self.assertTrue(vone_edge_two.get_dest_vertex() is self.vertex_two)
        self.assertTrue(v2_edge.get_dest_vertex() is self.vertex_one)


     


    def test_point_to_truetrue(self):
        # Mdv -> Mdv, src vertex not pointing already == True, dest vertex not being pointed already == True
        mdv_one = Mdv("Flamengo")
        mdv_two = Mdv("Fluminense")
        mdv_one.point_to(mdv_two)
        mdv_one_edge = mdv_one.get_edge(two=True)
        dest_edge = mdv_one_edge.get_dest_vertex()

    def test_point_to_truefalse(self):
        # Mdv -> Mdv, src vertex not pointing already == True, dest vertex not being pointed already == False
        mdv_fla = Mdv("Flamengo")
        mdv_flu = Mdv("Fluminense")
        any_bt = Mdv("Bota Fogo")
        """
        Expected
        Bota fogo <-> Fluminense
        Flamengo <-> Fluminense

        Actual
        Fluminense <-> Flamengo
        Fluminense <-> Flamengo
        """
        any_bt.point_to(mdv_flu)
        key = mdv_fla.point_to(mdv_flu)

        # expected result 
        expected_pb_key = id(mdv_fla)
        expected_p = mdv_flu
        
        # real result
        mdv_fla_edge = mdv_fla.get_edge(two=True)
        dest_edge = mdv_fla_edge.get_dest_vertex()

        self.assertEqual(id(expected_p), id(dest_edge))
        keys_list = mdv_flu.get_edges()
        keys_list = keys_list.keys()
        # next time i need to check why set_vertex pb is empty
        
        self.assertIn(hex(expected_pb_key), keys_list)
        self.assertTrue( dest_edge is mdv_flu) 
        pass      

    def test_point_to_false_true(self):
        # Mdv -> Mdv, src vertex not pointing already == False, dest vertex not being pointed already == True
        mdv_fla = Mdv("Flamengo")
        mdv_flu = Mdv("Fluminense")
        any_bt = Mdv("Bota Fogo")
        mdv_fla.point_to(mdv_flu)
        mdv_fla.point_to(any_bt)

        fla_edges = mdv_fla.get_edges()
        expect_result = fla_edges[hex(id(any_bt))]
        self.assertTrue(expect_result != None)


    def test_point_to_false_false(self):
        # Mdv -> Mdv, src vertex not pointing already == False, dest vertex not being pointed already == False
        mdv_fla = Mdv("Flamengo")
        mdv_flu = Mdv("Fluminense")
        any_bt = Mdv("Bota Fogo")
        mdv_vasco = Mdv("Vasco")

        mdv_fla.point_to(mdv_flu)
        any_bt.point_to(mdv_vasco)

        mdv_fla.point_to(mdv_vasco)

        fla_edges = mdv_fla.get_edges()
        expect_pointed_to = fla_edges[hex(id(mdv_vasco))]

        vasco_edges = mdv_vasco.get_edges()
        expect_pointing_back = vasco_edges[hex(id(mdv_fla))]

        self.assertTrue(expect_pointed_to != None)
        self.assertTrue(expect_pointing_back != None)

    def test_mdv_to_vtx_true_true(self):
        pass

    def test_mdv_to_vtx_true_false(self):
        pass

    def test_mdv_to_vtx_false_true(self):
        pass

    def test_mdv_to_vtx_false_false(self):
        pass