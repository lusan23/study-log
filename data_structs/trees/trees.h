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
{ int size;
  int depth;
  tree_node *root;
}binary_tree;

tree_node* recursive_free(tree_node** root);
tree_node* sucessor(struct tree_node *any_node);
bool is_leaf(struct tree_node* node);


bool alloc_succeed(tree_node *bt);
void malloc_binary_tree(struct binary_tree **bt, int first_value);
void free_tree(binary_tree** tree);
tree_node* subtree_last(binary_tree** tree);
tree_node* subtree_first(struct tree_node * subtree_root);
void subtree_insert_after(binary_tree** tree, tree_node** entry_node, int new_value);
void printAll(binary_tree* tree);
tree_node* predecessor(struct tree_node *any_node);
#endif
