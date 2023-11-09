import unittest

# Import the test cases from the individual files

from tests.test_vertex import TestVertex
from tests.test_GraphSet import TestGraphSet
from tests.test_DirectGraphSet import TestDirectGraph

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

    return suite_graphset


def create_direct_graphset_suite():
    suite_direct_graphset = unittest.TestSuite()
    suite_direct_graphset.addTest(unittest.makeSuite(TestDirectGraph))


    return suite_direct_graphset



if __name__ == "__main__":
    runner = unittest.TextTestRunner()
    test_suite_one = create_graphset_suite()
    test_suite_two = create_direct_graphset_suite()
    runner.run(test_suite_one)
    runner.run(test_suite_two)
    
