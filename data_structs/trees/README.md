# Binary Tree

This is a simple implementation of [Binary Tree](/data_structs/trees/binary_search_tree.c) in C for learning purposes.

## How is it structured?

```C
typedef struct tree_node
{
  struct tree_node* parent;
  struct tree_node* left;
  struct tree_node* right;
  int depth;
  int value;
  
} tree_node;

typedef struct binary_tree
{
  int size;
  int height;
  tree_node *root;
} binary_tree;
```
`tree_node` calls itself recursively by defining `parent`, `left`, and `right`.

`binary_tree` stores a `tree_node` type pointer (it will be dynamically allocated, similar to linked lists).

![graphviz(6)](https://github.com/lusan23/study-log/assets/142463065/4f766d46-f0b3-4022-8a94-c73457b5760a)

You might declare it as a pointer and then call `malloc_binary_tree(&tree, node_value)` to set up the root node like in the example:

```C
binary_tree *tree; 
malloc(&tree, 1);
```
Just like the standart `malloc` in C, `malloc_binary_tree` needs to have a corresponding `free` function to avoid memory leak, wich is `free_tree`. It frees the nodes recursively.

```C
free_tee(&tree);
```

## Operations

### Primitive Functions 

These are the functions that define the concept of traversal order by following these rules:

1. The **left** child of a node is **before** its parent.

2. The **right** child of a node is **after** its parent.

#### [Find first](https://github.com/lusan23/study-log/blob/master/data_structs/trees/private_func.c#L17)

It starts at the root node and looks for the first node in the tree by **going to the left until it reaches the last node**, 
and no matter how big the tree is, it will always be the leftmost node.

![graphviz(5)](https://github.com/lusan23/study-log/assets/142463065/2728f757-84b6-4b89-b902-90b28f057970)
![graphviz(4)](https://github.com/lusan23/study-log/assets/142463065/75f5a113-50c8-4a93-b78b-0d616ee36376)

```C
tree_node* first_node = subtree_first(tree->root);
```


#### [Find last](https://github.com/lusan23/study-log/blob/master/data_structs/trees/private_func.c#L33)
![graphviz(7)](https://github.com/lusan23/study-log/assets/142463065/0a8a9dda-cb65-42cb-bad2-c05552a2fa6c)

The opposite of `subtree_last()`, it looks for the last node in the tree by **going to the right until there are no more right children.**


```C
tree_node* last_node = subtree_last(tree->root);
```

#### Predecessor
It returns the node before the given node (in traversal order). If the given node is the first one, it returns the same node.

```C
tree_node* previous_node = predecessor(tree->root);
```

#### Successor
The opposite of Predecessor, if the given node is the last one it returns the last node 

```C
tree_node* next_node = successor(tree->root);
```
---

#### is_last, is_first and is_leaf
These are boolean functions, mostly used internally make the code shorter.
This functions verify if a given node is the first and last node on the tree. `is_leaf` verifies with the given node as no children nodes.

```C
if (is_first(tree->root->right-->left))
{
  //do something
}
```
