#ifndef TREE_H_
#define TREE_H_
#include<stdbool.h>

//Primitives

/*
  ########## TREE_NODE ##########

  Define the nodes in a tree
  and stores subtree properties. 

  Members:
    
    value - stores the node's data.
    is_freed - a deleted flag, setted as true when its node is freed.
    
    Subtree properties:
      parent, left and child - points to its respective ancerstor, 
      left and right childs.
      size - the number of nodes in its node's subtree.
    
*/
typedef struct  tree_node
{
  int value;
  struct tree_node* parent;
  struct tree_node* left;
  struct tree_node* right;
  int is_freed;
  //subtree properties
  unsigned int height;
  unsigned int size;

}tree_node;

/*
  ########## BINARY_TREE ##########
  Define the binary where the nodes will be stored.

  root - the root node of binary tree.

*/
typedef struct  binary_tree
{
  tree_node *root;

}binary_tree;

//Primitive Operations
/*
  It allocates dinamic memory for the Binary Tree

  @param bt - A binary_tree struct defined before (need to the passed
  by reference.)
  @param first_value - The data that will be stored at the root tree_node.
    
*/
void malloc_binary_tree(struct binary_tree **bt, int first_value);


/*
  (Private Function)

  Recursively frees all the nodes in a subtree.
  
  @param root - the subtree's root.
*/
tree_node* recursive_free(tree_node** root);

/*
  Calls recursive_free and frees the binary_tree from the heap.
  
  @param tree - Binary tree to be freed.
*/
void free_tree(binary_tree** tree);

//Traversal Operations

/*
  (Private Function)

  It goes down the subtree until hit the most left child

  @param given_node - the subtree. 
*/
tree_node* subtree_first(tree_node** given_node);

/*
  (Private Function)

  It goes down the subtree until hit the most right child.

  @param given_node - the subtree itself.

  @return - The first node of the subtree in traversal order. 
*/
tree_node* subtree_last(tree_node** given_node);

/*
  (Private Function)

  Looks for the previous node of a given node
  in traversal order.

  @param given_node - the given node itself.

  @return - The last node of the subtree in traversal order

*/
tree_node* predecessor(tree_node** given_node);

/*
  (Private Function)
  
  Looks for the next node of a given node
  in traversal order.

  @param given_node - the given node itself.

  @return - The next node of the given node in traversal order

*/
tree_node* sucessor(tree_node** given_node);

//Insertions

/*
  (Private Function)

  Allocates a new node to memory and link it to a existent
  node.

  @param parent - the tree_node where the new node will be
  linked to.

  @return - the created node itself.

*/
tree_node* create_tree_node(tree_node** parent, int given_value);

/*
  (Private Function)

  Insert a created node into the predecessor of a given node.

  @param given_node - the given node itself.

  @return - the created node itself.

*/
void subtree_insert_before(tree_node** given_node, int new_value);

/*

  (Private Function)

  Insert a created node into the sucessor of a given node.

  @param given_node - the given node itself.

  @return - the created node itself.

*/
void subtree_insert_after(tree_node** given_node, int new_value);


//Delete

/*
  (Private Function)

  Moves a none-leaf node down the tree (by swaping it with its predecessor or sucessor) until it becomes a leaf.
  (Similar to the bubble sort algorithm)

  @param given_node - the node to be swaped down.

  @return - the given_node node, now as a leaft on its own subtree.

*/
void swap_nodes(tree_node** node_src, tree_node** node_dest);

/*

  Frees a leaf node from its subtree.
  (Here the is_freed flag is changed to true.)

  @param given_node - the node to be deleted.

  @return - the given_node node, now as a leaft on its own subtree.

*/
void subtree_delete(tree_node** given_node);

//BST Operations

/*
  Looks for a node in a subtree by doing a binary search on its node's data.

  @param given_node - The root of the subtree.
  @param given_value - The integer to be searched on the binary tree.
  @param given_static - 
    - when true if there's such interger in 
    the subtree returns the closests node to that value.
    when

    - when false if the given interger was not found on the subtree just return NULL.]

  @return - the node if the given value or NULL

*/
tree_node* subtree_find_key(tree_node** given_node, int given_value, bool static_mode);

/*
  Insert a new node to the given subtree as anscendent order set.

  @param new_value - the data that will stored in the new node.
*/
void bst_subtree_insert(tree_node** given_node, int new_value);

/*
  Recalcules the size of all the ancestors of a given node until the binary tree's root.
  
  @param given_node -It can be a new created leaf or the parent of a deleted leaf.
  @param del_mode:
    - when true it won't set the size of the given node as 1.
    - when true the given node's size will the defined as 1.
*/
void update_size(tree_node** given_node, bool del_mode);

/*
  Looks for the index of subtree's node in the range (0 to subtree's size-1)

  @param given_node - the root of a subtree where it will look for.
  @param ith - the index of the node.

  @return - The Ith node that corresponds to the given index.

*/
tree_node* subtree_find_ith(tree_node** given_node, unsigned int ith);

//Boolean Functions

/*
  Verifies if a given node is leaf by looking its parents and childs.
  @param given_node - the node to be verified

  @return - True if it's a leaf.
*/
bool is_leaf(tree_node** given_node);

/*

  Verifies if  one of the given unsinged integers is bigger or equal than other
  Used to calculate the height of a node.

  @param a the left child's height
  @param b the right child's height

  @return the biggest height
  
*/
unsigned int max_equal(unsigned int a, unsigned int b);

/*
  Verifies if  a given node is the root of the binary tree

  @param the given node.

  @return True if it's the root.
*/
bool is_root(tree_node** given_node);

#endif
