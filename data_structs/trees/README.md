# Binary Tree

This is a simple implementation of [Binary Tree](/data_structs/array/dinamic_array.c) in C for learning porpuses 

## How is it structured?
![C struct ](https://github.com/lusan23/study-log/assets/142463065/e19f63c5-4685-481c-a7a7-394531a33d94)

### The BT itself is implemented as two structs C struct:

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
  int heigh;
  tree_node *root;
}binary_tree;
```
`binary_tree` stores a `tree_node` type pointer ( it will be  dynamically allocated, similar to linked lists).

