#ifndef TREE_H_
#define TREE_H_
#include<stdbool.h>

//Primitives
typedef struct  tree_node
{
    int value;
  struct tree_node* parent;
  struct tree_node* left;
  struct tree_node* right;

}tree_node;

typedef struct  binary_tree
{ int size;
  tree_node *root;
}binary_tree;

void malloc_binary_tree(struct binary_tree **bt, int first_value);
tree_node* create_tree_node(tree_node** parent, int given_value);
tree_node* recursive_free(tree_node** root);

//Traversal Operations
tree_node* subtree_first(tree_node** given_node);
tree_node* subtree_last(tree_node** given_node);
tree_node* predecessor(tree_node** given_node);
tree_node* sucessor(tree_node** given_node);
#endif
