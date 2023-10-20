#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"btdigraph.h"
#include"../trees.h"


 tree_node* recursive_search(tree_node** root, char cmd[1000])
{   //generates the graphviz code for the given tree.
  if ((*root) == NULL)
  { //base case
    return (*root);
  }
  else
  { //recursive calls
    
    recursive_search(&((*root)->left), cmd);
    recursive_search(&((*root)->right), cmd);

    //deicision code here

    if ((*root)->left != NULL && (*root)->right != NULL)
    {
        char left_val[256];
        char node_val[256];
        char right_val[256];

        sprintf(left_val, "%d", (*root)->left->value);
        sprintf(node_val, "%d", (*root)->value);
        sprintf(right_val, "%d", (*root)->right->value);
       add_double_connection(cmd, node_val, left_val, right_val);
    }

    else
    {
        if ((*root)->left != NULL)
        {       char left_val[256];
            char node_val[256];
            sprintf(left_val, "%d", (*root)->left->value);

            sprintf(node_val, "%d", (*root)->value);
            add_connection(cmd, node_val, left_val);
        }
        else if ((*root)->right != NULL)
        {

            
            char right_val[256];
            char node_val[256];
            sprintf(right_val, "%d", (*root)->right->value);
            sprintf(node_val, "%d", (*root)->value);
            add_connection(cmd, node_val, right_val);
            
        }
        else
        {
            char node_val[256];
            sprintf(node_val, "%d", (*root)->value);
            
            add_leaf(cmd, node_val);
        }
    }
  }
  
}


void create_digraph(binary_tree* tree)
{
    

    if (alloc_succeed(tree->root))
    {
        tree_node* root = tree->root;
        char* command = calloc(1000, sizeof(char));
        define_digraph(command);
        recursive_search(&root, command);
        end_digraph(command);

        char* fn = create_file(command, "nodess");
        //create_img(fn, "tree");
    }
}

int main(void)
{
  binary_tree *tree;
  malloc_binary_tree(&tree, 5);

  tree->root->right = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->right->value = 7;
  tree->root->right->parent = tree->root;

  tree->root->right->right = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->right->right->value = 9;
  tree->root->right->right->parent = tree->root;
  

  tree->root->right->left = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->right->left->value = 6;
  tree->root->right->left->parent = tree->root;
  
  
  tree->root->left = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->left->value = 3;
  tree->root->left->parent = tree->root;

  tree->root->left->right = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->left->right->value = 4;
  tree->root->left->right->parent = tree->root;
  

  tree->root->left->left = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->left->left->value = 2;
  tree->root->left->left->parent = tree->root;


  tree->root->left->left->left = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->left->left->left->value = 1;
  tree->root->left->left->left->parent = tree->root;
  
 

  create_digraph(tree);
return 0;
}