import unittest
from heap import Heap

class TestHeap(unittest.TestCase):
    def __init__(self, *args, **kwargs) -> None:
        super(TestHeap, self).__init__(*args, **kwargs)
        self.hp = Heap()

    def test_insert_root(self):
        """ testing when no node was ever inserted """
        hp = self.hp

        hp.insert(hp.root,10)
        self.assertTrue(hp.root.data == 10 )


    def test_insert_left(self):
        """ testing the case wher one node was already inserted """
        hp = self.hp
        hp.insert(hp.root,10)
        hp.insert(hp.root,20)
        self.assertTrue(hp.root.left != None )
        self.assertTrue(hp.root.left.data == 20 )
        print()

    def test_insert_RIGHT(self):
        """ testing the case wher two nodes were already inserted """
        hp = self.hp
        hp.insert(hp.root,10)
        hp.insert(hp.root,20)
        hp.insert(hp.root,30)
        self.assertTrue(hp.root.right != None )
        self.assertTrue(hp.root.right.data == 30 )

    def test_insert_recusive_call_left_left_child(self):
        """ 
        testing the when the first subtree is filled and 
        it does the first recusirve call to left child
        """
        hp = self.hp
        hp.insert(hp.root,10)
        hp.insert(hp.root,20)
        hp.insert(hp.root,30)
        hp.insert(hp.root,40)
        self.assertTrue(hp.root.left.left != None )
        self.assertTrue(hp.root.left.left.data == 40 )


    def test_insert_recusive_call_left_right_(self):
        """ 
        testing the when the first subtree is filled and 
        it does the first recusirve call to left child
        """
        hp = self.hp
        hp.insert(hp.root,10)
        hp.insert(hp.root,20)
        hp.insert(hp.root,30)
        hp.insert(hp.root,40)
        hp.insert(hp.root,50)
        self.assertTrue(hp.root.left.right != None )
        self.assertTrue(hp.root.left.right.data == 50 )

    def test_insert_recusive_call_right_left(self):
        """ 
        testing the when the first subtree is filled and 
        it does the first recusirve call to left child
        """
        hp = self.hp
        hp.insert(hp.root,10)
        hp.insert(hp.root,20)
        hp.insert(hp.root,30)
        hp.insert(hp.root,40)
        hp.insert(hp.root,50)
        hp.insert(hp.root,60)
        self.assertTrue(hp.root.right.left != None )
        self.assertTrue(hp.root.right.left.data != 60 )

    def test_insert_recusive_call_right_left(self):
        """ 
        testing the when the first subtree is filled and 
        it does the first recusirve call to left child
        """
        hp = self.hp
        hp.insert(hp.root,10)
        hp.insert(hp.root,20)
        hp.insert(hp.root,30)
        hp.insert(hp.root,40)
        hp.insert(hp.root,50)
        hp.insert(hp.root,60)
        hp.insert(hp.root,70)
        self.assertTrue(hp.root.right.right != None )
        self.assertTrue(hp.root.right.right.data != 70 )

   
if __name__ == "__main__":
    unittest.main()