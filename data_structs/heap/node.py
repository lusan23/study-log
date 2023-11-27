""" representation of the node of  a binary tree data structure """

class Node:
    def __init__(self, data=None):
        """
        Attributes of an node that belongs to a binary tree
        >>> node.parent
        >>> node.left
        >>> node.right
        >>> node.data
        """
        self.parent = None
        self.left = None
        self.right = None
        self.data = data

    def update_data(self, new_data):
        """Overwrites the attribute data"""
        self.data = new_data


    def insert_left(self, data):
        """
            creates a new node object on the self.left attribute
        """ 
        if self.left == None:
            self.left = Node(data)
            self.left.parent  = self
        else:
            Exception(f"A node already exist at {self}")
  

    def insert_right(self, data):
        """
            creates a new node object on the self.right attribute
        """ 
        if self.right == None:
            self.right = Node(data)
            self.right.parent  = self
            
        else:
            Exception(f"A node already exist at {self}")

    def remove_left(self):
        if (self.left != None):
            del self.left 
            
        else:
            raise Exception("The left child is already empty.")

    def remove_right(self):
        if (self.right != None):
            del self.right
    
        else:
            raise Exception("The left child is already empty.")

if __name__ == "__main__":
    node = Node(1)
    print(node.__dict__)