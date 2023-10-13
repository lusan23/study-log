# Binary Tree

This is a simple implementation of [Binary Tree](/data_structs/trees/binary_search_tree.c) in C for learning porpuses 

## How is it structured?

```C
typedef struct  tree_node
{
  struct tree_node* parent;
  struct tree_node* left;
  struct tree_node* right;
  int deph;
  int value;
  
}tree_node;

typedef struct  binary_tree
{
  int size;
  int height;
  tree_node *root;
}binary_tree;
```
`tree_node` calls itself recursively by defining `parent`, `left` and `right`.

`binary_tree` stores a `tree_node` type pointer ( it will be  dynamically allocated, similar to linked lists).

## Operations

