import unittest
from node import Node

class TestNode(unittest.TestCase):
    def __init__(self, *args, **kwargs) -> None:
        super(TestNode, self).__init__(*args, **kwargs)
        self.bt = Node()

    def test_insert_left(self):
        """ Check if the node is created properly """
        bt = self.bt 
        bt.insert_left(10)
        self.assertNotEqual(bt.left, None )
        self.assertEqual( bt.left.data, 10 )

    def test_insert_right(self):
        """ Check if the node is created properly """
        bt = self.bt 
        bt.insert_right(10)
        self.assertNotEqual(bt.right, None )
        self.assertEqual( bt.right.data, 10 )

    def test_remove_left(self):
        """ Check if the node is created properly """
        bt = self.bt 

        self.assertEqual(bt.left, None )
      

    def test_remove_right(self):
        """ Check if the node is created properly """
        bt = self.bt 
        self.assertEqual( bt.right, None )

if __name__ == "__main__":
    unittest.main()