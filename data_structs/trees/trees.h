#ifndef DA_H_
#define DA_H_
#include<stdbool.h>

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

bool alloc_succeed(tree_node *bt);
void malloc_binary_tree(struct binary_tree **bt, int first_value);
void free_tree(binary_tree** tree);
static tree_node* subtree_last(binary_tree** tree);
tree_node* subtree_first(struct tree_node * subtree_root);
void subtree_insert_after(tree_node** entry_node, int value);
#endif
