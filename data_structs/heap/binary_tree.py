from node import Node
class BinaryTree:
    def __init__(self):
        self.root = Node()
        self.name = ""

    def set_name(self, name: str):
        self.name = name

if __name__ == "__main__":
    bt = BinaryTree()
    print(bt.__dict__)