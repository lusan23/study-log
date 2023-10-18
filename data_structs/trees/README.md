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

### Example Code

![graphviz(6)](https://github.com/lusan23/study-log/assets/142463065/4f766d46-f0b3-4022-8a94-c73457b5760a)
You might declare it as pointer and the call `malloc_binary_tree(&tree, node_vale)` to setup the root node like the example:

```C
binary_tree *tree; 
malloc(&tree, 1);
```
## Operations

### Primitive functions 

Those are the functions that state the concept of traversal order by following these rules:

1.the **left** child of a node it's **before** its parent.

2.the **right** child of a node it's **after** its parent.

#### [Find first](https://github.com/lusan23/study-log/blob/master/data_structs/trees/private_func.c#L17)

It start in the root node and, and looks for the first node in the tree by **going to the left until get to the last node**, 
and doesn't matter how big the tree is, it always will be the most left node.

![graphviz(5)](https://github.com/lusan23/study-log/assets/142463065/2728f757-84b6-4b89-b902-90b28f057970)
![graphviz(4)](https://github.com/lusan23/study-log/assets/142463065/75f5a113-50c8-4a93-b78b-0d616ee36376)
### Example
```C
binary_tree *tree; 
malloc(&tree, 1);

tree* first_node = subtree_first(tree->root);

```


#### [Find last](https://github.com/lusan23/study-log/blob/master/data_structs/trees/private_func.c#L33)
![graphviz(7)](https://github.com/lusan23/study-log/assets/142463065/0a8a9dda-cb65-42cb-bad2-c05552a2fa6c)

The oppose of `subtree_last()`, looks for the last node in the tree by **going to the right until there's no more right child.**
### Example


```C
binary_tree *tree; 
malloc(&tree, 1);
tree* first_node = subtree_last(tree->root);

```

### Predecessor
It return the node before the given (in traversal order). if the given node is the last one, it return the same node.



