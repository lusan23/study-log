""" representation of a heap data structure """
from binary_tree import BinaryTree
from node import Node

# create a heap class 
    # create insert and delete methods
    
class Heap(BinaryTree):
    """ Represent an max/min heap data structure """
    def __init__(self):
        super().__init__()
        self.max_mode = True

    def insert(self, node, data, ) -> None:
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


    def __insert_root(self, data: int ,node: Node):
        """ if the root node is empty it will update its data  """
 
        node.update_data(data)
        return True

    
    
    def __insert_left_max(self, data: int, node: Node):
        # first try to insert at left child and check their values, swap if needed
        current_node = node
        node.insert_left(data)
        # go up the tree until the root or find the parent is bigger than the new node value.    
        self.__update_ancestor(node.left)
        return True
          
                
    def __insert_right_max(self, data: int, node: Node):
        current_node = node
        node.insert_right(data)
        # go up the tree until the root or find the parent is bigger than the new node value.    
        self.__update_ancestor(node.right)
        return True
        
     
    def __update_ancestor(self, new_node):
        """ bubble up the highest node on the tree """
        current_node = new_node

        while (current_node.data > current_node.parent.data):
            self.__swap_data(current_node, current_node.parent)

            current_node = current_node.parent

            if (not current_node.parent):
                break
     
        
    def insert_max(self, data: int, node: Node) :
        """ insert new nodes by following the rule: value(parent) >= value(child) """

        # make a loop to iterate through all the levels in a the heap
        # try to insert at all the nodes at level i

        while True:
            

        
        """ verifies the next node at the same level """
            
        

             
                


if __name__ == "__main__":
    heap = Heap()
    print(heap.__dict__)