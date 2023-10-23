#ifndef DA_H_
#define DA_H_
#include<stdbool.h>

typedef struct  tree_node
{
    int value;
  struct tree_node* parent;
  struct tree_node* left;
  struct tree_node* right;

  
}tree_node;

typedef struct  binary_tree
{ int size;
  int depth;
  tree_node *root;
}binary_tree;

tree_node* recursive_free(tree_node** root);
void free_tree(binary_tree** tree);

tree_node* sucessor(struct tree_node *any_node);
tree_node* predecessor(struct tree_node *any_node);

bool is_leaf(struct tree_node* node);
bool alloc_succeed(tree_node *bt);


void malloc_binary_tree(struct binary_tree **bt, int first_value);
tree_node* subtree_first(struct tree_node * subtree_root);
tree_node* subtree_last(tree_node* node);
void subtree_insert_before(binary_tree** tree, tree_node** entry_node, int new_value);
void subtree_insert_after(binary_tree** tree, tree_node** entry_node, int new_value);
void printAll(binary_tree* tree);

void insert(binary_tree** tree, int new_value);

#endif
