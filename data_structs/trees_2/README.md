# Trees

This is an implementation of a Binary Tree.

* Primitives
* Traversal Operations
* Binary Search Tree

## Primitive Functions

These are a set of functions that represent a binary tree.

### Creating a Binary Tree

```C
binary_tree* t;
malloc_binary_tree(&t, 5);
```

`malloc_binary_tree` allocates dynamic memory for the structure `binary_tree`.

Definition of `binary_tree`:

```C
typedef struct  binary_tree
{
  tree_node *root;
} binary_tree;
```

The argument `5` is the data that will be inserted into the `tree_node` struct, at `int value`.

```C
typedef struct  tree_node
{
  int value;
  struct tree_node* parent;
  struct tree_node* left;
  struct tree_node* right;
  int is_freed;
  // subtree properties
  unsigned int height;
  unsigned int size;
} tree_node;
```

- `parent`: a pointer to its node ancestor. (By default, the root node doesn't have a parent node.)
- `left` and `right`: Pointers to child nodes.
- `is_freed`: a 'deleted flag'.
- `height` and `size`: subtree properties that are updated as the tree is changed (nodes being inserted and deleted).

You can verify the value:

```C
printf("My root's value is %d\n", t->root->value);
```

### Deleting a Binary Tree

To avoid memory leaks, you can also free the binary tree by calling:

```C
free_tree(&t);
```

It calls a private function to free all the child nodes below `root` and then it frees the binary tree.

## Traversal Operations

This set of functions implements the traversal order, which follows these two rules:

* The LEFT of a given node is BEFORE its parent.
* The RIGHT of a given node is AFTER its parent.

### Insert a Node Before and After

These two functions create and add a new node before and after a given node (respecting the traversal order).

It will insert a new node with a data integer of value 30 as the left child of `root`.

```C
subtree_insert_before(&t->root, 30);
```

It will insert a new node with a data integer of value 70 as the right child of `root`.

```C
subtree_insert_after(&t->root, 70);
```

If root already had a left or right child, the place where the new node would be inserted is different, but it still would respect the traversal order.

#### Removing a Node

To remove a node, you could simply call:

```C
subtree_delete(&t->root);
```

It will free the node, but the pointer might get a random number so there's the `is_freed` flag that signals if the node was deleted or not.

## Binary Search Tree

On top of all the functions previously mentioned, there are two functions that implement the concept of BST. A binary tree that can insert, delete, and search for nodes in a running time of O(h), where h = the height of a tree.

### BST as a Sorted Set

It's possible to create an ordered Set by inserting numbers. You can call `bst_subtree_insert`:

```C
binary_tree* t;
malloc_binary_tree(&t, 50);
bst_subtree_insert(&t->root, 30);
bst_subtree_insert(&t->root, 80);
```

* 30 will be inserted as the left child of root because 30 < 50.
* 50 will be inserted as the right child of root because 80 > 50.

This function calls the function `subtree_find_key`, which does a binary search to look for a place where the new node should be inserted.

### Look for an Element by its Index

It's possible to look for the ith item of a tree (following the traversal order) by calling `subtree_find_ith`, where the index is in the range (0 to tree's size-1).

```C
binary_tree* t;
malloc_binary_tree(&t, 50);
bst_subtree_insert(&t->root, 30);
bst_subtree_insert(&t->root, 80);

tree_node* node_index_zero = subtree_find_ith(&t, 0); // returns the node with value 30
tree_node* node_index_one = subtree_find_ith(&t, 1);  // returns the node with value 50
tree_node* node_index_two = subtree_find_ith(&t, 2);  // returns the node with value 80
tree_node* node_index_four = subtree_find_ith(&t, 4); // error message "given index out of range!!!"
```

Behind the scenes, what this function does is a binary search by verifying sizes.

AVL Tree may be implemented in the future!

Thanks for reading!
