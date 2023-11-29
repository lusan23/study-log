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
        testing the if root -> left -> left is filled
        """
        hp = self.hp
        for index in range(10, 50, 10):
            hp.insert(hp.root, index)
        self.assertTrue(hp.root.left.left != None )
        self.assertTrue(hp.root.left.left.data == 40 )


    def test_insert_recusive_call_left_right_(self):
        """ 
        testing the if root -> left -> right is filled
        """
        hp = self.hp
        for index in range(10, 60, 10):
            hp.insert(hp.root, index)
        self.assertTrue(hp.root.left.right != None )
        self.assertTrue(hp.root.left.right.data == 50 )

    def test_insert_recusive_call_right_left(self):
        """ 
        testing the if root -> right -> left is filled
        """
        hp = self.hp
  
        for index in range(10, 70, 10):
            hp.insert(hp.root, index)

        self.assertTrue(hp.root.right.left != None )
        self.assertTrue(hp.root.right.left.data != 60 )

    def test_insert_recusive_call_right_left(self):
        """ 
        testing the if root -> right -> right is filled
        """
        hp = self.hp
        # keep inserting it until hp.root.right.right is filled
        for index in range(10, 80, 10):
            hp.insert(hp.root, index)

        self.assertTrue(hp.root.right.right != None )
        self.assertTrue(hp.root.right.right.data != 70 )


    def test_remove_root_node(self):
        """testing if the data from root node is removed."""
        hp = self.hp

        hp.insert(hp.root, "raiz")
        hp.remove_at(hp.root)

        self.assertTrue(hp.root.data is None)

    def test_remove_not_root_node(self):
        """testing if the an node that is not the root is properly deleted."""
        hp = self.hp

        hp.insert(hp.root, "raiz")
        hp.insert(hp.root, "esquerda")
        hp.remove_at(hp.root.left)
        
        self.assertTrue(hp.root.left is None)

    def test_remove_not_root_node_rightchild(self):
        """testing if the an node that is not the root is properly deleted."""
        hp = self.hp

        hp.insert(hp.root, "raiz")
        hp.insert(hp.root, "esquerda")
        hp.insert(hp.root, "direita")
        hp.remove_at(hp.root.right)
        
        self.assertTrue(hp.root.right is  None)


    def test_insert_root_max_heap(self):
        """ testing when no node was ever inserted """
        hp = self.hp

        hp.insert(hp.root,10)
        self.assertTrue(hp.root.data == 10 )


    def test_insert_left_max_heap_new_smaller(self):
        """ testing when inserted in the left child, (new node < parent)"""
        hp = self.hp
        hp.insert_max(20,hp.root,)
        hp.insert_max(10,hp.root)
        self.assertTrue(hp.root.left.data == 10 )
        self.assertTrue(hp.root.data == 20 )

    def test_insert_left_max_heap_new_bigger(self):
        """ testing when inserted in the left child, (new node < parent) """
        hp = self.hp
        hp.insert_max(10,hp.root,)
        hp.insert_max(20,hp.root)
        self.assertTrue(hp.root.left.data == 10 )
        self.assertTrue(hp.root.data == 20 )

    def test_insert_right_max_heap_new_largest(self):
        """ testing when inserted in the right child, (new node > parent) """
        hp = self.hp
        hp.insert_max(10,hp.root,)
        hp.insert_max(9,hp.root)
        hp.insert_max(30,hp.root)
        self.assertTrue(hp.root.right.data == 10 )
        self.assertTrue(hp.root.data == 30 )
        self.assertTrue(hp.root.left.parent.data == 30)

    

    def test_insert_right_max_heap_new_smallest(self):
        """ testing when inserted in the right child, (new node > parent) """
        hp = self.hp
        hp.insert_max(10,hp.root)
        hp.insert_max(9,hp.root)
        hp.insert_max(1,hp.root)

        self.assertTrue( hp.root.right.data == 1 )
        self.assertTrue( hp.root.data == 10 )
        self.assertTrue( hp.root.left.data == 9 )

    

    def test_insert_left_left_max_heap_new_bigger(self):
        """ testing when it insert the root.left.left, (new node > parent and new_node > parent.parent) """
        hp = self.hp
        hp.insert_max(10,hp.root,)
        hp.insert_max(9,hp.root)
        hp.insert_max(1,hp.root)
        hp.insert_max(11, hp.root)
        self.assertTrue(hp.root.left.left == 10 )
        self.assertTrue(hp.root.data == 11 )
        # self.assertTrue(hp.root.left.data == 9)

    
if __name__ == "__main__":
    unittest.main()