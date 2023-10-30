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
  int is_freed;
  unsigned int height;
  unsigned int size;

}tree_node;

typedef struct  binary_tree
{ int size;
  tree_node *root;
}binary_tree;

//Primitive Operations
void malloc_binary_tree(struct binary_tree **bt, int first_value);
tree_node* recursive_free(tree_node** root);
void free_tree(binary_tree** tree);

//Traversal Operations
tree_node* subtree_first(tree_node** given_node);
tree_node* subtree_last(tree_node** given_node);
tree_node* predecessor(tree_node** given_node);
tree_node* sucessor(tree_node** given_node);

//Insert
tree_node* create_tree_node(tree_node** parent, int given_value);
void subtree_insert_before(tree_node** given_node, int new_value);
void subtree_insert_after(tree_node** given_node, int new_value);

//Delete
void swap_nodes(tree_node** node_src, tree_node** node_dest);
void subtree_delete(tree_node** given_node);

//BST Operations
tree_node* subtree_find_key(tree_node** given_node, int given_value, bool static_mode);
void bst_subtree_insert(tree_node** given_node, int new_value);

//subtree properties operations
void add_size(tree_node** given_node);

//Boolean Functions
bool is_leaf(tree_node** given_node);
#endif
