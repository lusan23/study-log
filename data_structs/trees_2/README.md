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

## Traversal Operations

This set of functions are the implementation of the traversal order, which follow these two rules:
* the LEFT of a given node is BEFORE its parent.
* the RIGHT of a given node is AFTER its parent.

### Insert a node Before and After
These two functions create and add a new node before and after a given node (respecting the traversal order)


It will insert a new node with a data integer of value 30 as the left child of `root`.
```C
    subtree_insert_before(&t->root, 30);
```

It will insert a new node with a data integer of value 70 as the right child of `root`.
```C
    subtree_insert_after(&t->root, 70);
```

If root already had a left or right the place where the new node would be inserted is difference, but it still would respect traversal order.

#### Removing a Node

to remove a node you could simply call:
```C
  subtree_delete(&t->root);
```
it will free the the node, but the pointer might get an random number so there's the `is_freed` flag that sinalize if the node was deleted or not.

## Binary search Tree
On the top of all the functions previously mentioned, there are two functions that Implement the concept of BST. A binary that insert,delete and search for nodes in a running time of O(h) h = the height a tree.  

### BST as a Sorted Set
It's possible s to create and ordered Set by inserting numbers by calling `bst_subtree_insert`:

```C
    binary_tree* t;
    malloc_binary_tree(&t, 50);
    bst_subtree_insert(&t->root, 30);
    bst_subtree_insert(&t->root, 80);
```
* 30 will be inserted as the left child of root, because 30 > 50
* 50 will be inserted as the right child of root, because 80 > 50

What this function does it is call the function `subtree_find_key` which does a binary search to look for a place where the new node should be inserted.

### Look for a element by its index.
It's possible to look for the ith item of a tree (following thr traversal order) by calling `subtree_find_ith`.
where the index is in the range (0 to tree's size-1)
```C

    binary_tree* t;
    malloc_binary_tree(&t, 50);
    bst_subtree_insert(&t->root, 30);
    bst_subtree_insert(&t->root, 80);

    tree_node* node_index_zero = subtree_find_ith(&t, 0); // returns the the node of value 30
    tree_node* node_index_one = subtree_find_ith(&t, 1); // returns the the node of value 50
    tree_node* node_index_two = subtree_find_ith(&t, 2); // returns the the node of value 80
    tree_node* node_index_four = subtree_find_ith(&t, 4); // error message "given index ot of range!!!"
```
Behind the scenes what this function does is a binary search by verifying sizes.

AVL Tree maybe will be implemented in the future!

Thanks for reading!


