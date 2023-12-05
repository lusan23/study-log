from node import Node

class BinaryTree:
    def __init__(self):
        self.root = Node()
        self.name = ""

    def set_name(self, name: str):
        self.name = name

    def __add_to_level(given_node, levels, curt_level, i):
        if (not given_node in curt_level):
            if (levels[i]):
                levels[i].add(curt_level)
            else:
                levels[i] = {given_node}
        else:
            print(f"{given_node} has already been added!")



    def find_level(self, root, value) -> [set]:
        """Return a list of all nodes of the same level of the given node"""

        if (not root is self.root ):
            return -1
  
        # initialize a queue at level 0/root level
        queue = [(self.root, 0)]

        # keep search until there are no nodes to self or the given node was found    
        while  True:
            current_node, current_level = queue.pop(0)

            if current_node.data == value:
                return current_level
            
            if (current_node.left):
                queue.append((current_node.left, current_level + 1))
            if (current_node.right):
                queue.append((current_node.right, current_level + 1))

        # node not found
        return -1

    def find_levels(self, given_level: int) -> [Node]:
        """ return all the nodes in a tree that belong to the given level """
        nodes = set()
        queue = [(self.root, 0)]
        while queue:
            current_node, current_level = queue.pop(0)

            if (current_level == given_level) and (not current_node in nodes):
                nodes.add(current_node)
            
            if (current_node.left):
                queue.append((current_node.left, current_level + 1))

            if (current_node.right):
                queue.append((current_node.right, current_level + 1))
        
        
        return nodes



if __name__ == "__main__":
    bt = BinaryTree()
    print(bt.__dict__)