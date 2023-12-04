import unittest

# Import the test cases from the individual files

from tests.test_vertex import TestVertex
from tests.test_GraphSet import TestGraphSet
from tests.test_mdv import TestMdv
from tests.test_edge import TestEdge

# Create a TestSuite nd add the test cases

def create_graphset_suite():
    """
        Create a suite test about the GraphSet class

        >>> graphset_suite = create_graphset_suite()
        >>>runner.run(graphset_suite)
        .
        .
        .
        OK
    """
    suite_graphset = unittest.TestSuite()

    suite_graphset.addTest(unittest.makeSuite(TestVertex))
    suite_graphset.addTest(unittest.makeSuite(TestGraphSet))

    suite_graphset.addTest(unittest.makeSuite(TestEdge))
    

    return suite_graphset


def create_mdv_suite():
    """
        Create a suite test about the GraphSet class

        >>> graphset_suite = create_graphset_suite()
        >>>runner.run(graphset_suite)
        .
        .
        .
        OK
    """
    suite_dmv = unittest.TestSuite()

    suite_dmv.addTest(unittest.makeSuite(TestMdv))



    return suite_dmv


if __name__ == "__main__":
    runner = unittest.TextTestRunner()
    test_suite_one = create_graphset_suite()
    test_mdv_suite = create_mdv_suite()

    runner.run(test_suite_one)
    runner.run(test_mdv_suite)

    
