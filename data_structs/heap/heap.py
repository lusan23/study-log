""" representation of a heap data structure """
from binary_tree import BinaryTree
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


if __name__ == "__main__":
    heap = Heap()
    print(heap.__dict__)