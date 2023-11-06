# Trees

This is a implementation of Binary Tree

* Primitives
* Traversal Operations
* Changing a Tree


## Primitive Functions

This a set of functions that represent a binary tree.

### Creating a BT

```C
binary_tree* t;
malloc_binary_tree(&t, 5);
```
`malloc_binary_tree` allocates dinamic memory for the structure `binary_tree`.

Definition of binary_tree:
```C

typedef struct  binary_tree
{
  tree_node *root;

}binary_tree;

```
The argument 5 it's the data that will be insert the the `tree_node` struct, at `int value`.

```C
typedef struct  tree_node
{
  int value;
  struct tree_node* parent;
  struct tree_node* left;
  struct tree_node* right;
  int is_freed;
  //subtree properties
  unsigned int height;
  unsigned int size;

}tree_node;

```
* `parent` the the pointer of its node ancestor. (by default, the root node doesn't have an parent node.)
* `left` and `right` Pointers of child nodes.
* `is_freed` is a 'deleted flag'.
* `height` and `size` subtree properties that are updated as the tree it's changed (nodes being inserted and deleted)

it's possible to verify the value: 
```C
printf("my root's value is %d\n",t->root->value);
```

### Deleting a Binary Tree

To avoid memory leak you also can free the binary tree by calling:

```C
free_tree(&t);
```
it calls a private function to free all the child nodes below `root` and then it frees the binary tree.

 the 
