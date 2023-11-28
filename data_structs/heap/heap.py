""" representation of a heap data structure """
from binary_tree import BinaryTree
from node import Node

# create a heap class 
    # create insert and delete methods
    # 10 MIN BREAK
class Heap(BinaryTree):
    """ Represent an max/min heap data structure """
    def __init__(self):
        super().__init__()
        self.max_mode = True

    def insert(self, node, data) -> None:
        """
        insert an new node from left to right
        """
        inserted = False
        if (node.data == None and not inserted):
            node.update_data(data)
            inserted = True

        if (node.left == None and not inserted):
            # first try to insert at left child
            node.insert_left(data)
            inserted = True
            # return None
        elif (node.right == None and not inserted):
            node.insert_right(data)
            # return None
            inserted = True
        elif (not inserted):
            self.insert(node.left, data)
            self.insert(node.right, data) 

    def remove_at(self, given_node: Node):
        """delete an node object from the tree/erase the data if it's the root."""
        if (given_node is self.root):
            self.root.update_data(None)
        else:
            if (given_node.parent.left is given_node):
                given_node.parent.left = None
                given_node = None
            elif (given_node.parent.right is given_node):
                given_node.parent.right = None
                given_node = None

    def __swap_data(self,src: Node,dest: Node ) -> None:
        src.data, dest.data = dest.data, src.data

    def insert_max(self, data: int ,node: Node):
        """ insert new nodes by following the rule: value(parent) >= value(child) """
        inserted = False
        # NOTE FOR TOMORROW : I CAN IMPLEMENT MAX AND MIN AT THE SAME FUNCTION
        if (node.data == None and not inserted):
            node.update_data(data)
            inserted = True

        if (node.left == None and not inserted):
        # first try to insert at left child and check their values, swap if needed
            node.insert_left(data)
            inserted = True
            if (node.data <=  data):
                self.__swap_data(node, node.left)
        # than try to insert at right child and check their values swap them if needed
        elif (node.right == None and not inserted):
            node.insert_right(data)
            if (node.data <=  data):
                self.__swap_data(node, node.right)
            
            inserted = True
        elif (not inserted):
            self.insert(node.left, data)
            self.insert(node.right, data) 


if __name__ == "__main__":
    heap = Heap()
    print(heap.__dict__)