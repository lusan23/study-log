#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"


tree_node* choose_rand_node(binary_tree** tree, int numb_steps)
{ //returns a random node, numb_steps determines how deep the choosen  
  // numb_steps needs to be <= tree->size
  tree_node* current_node = (*tree)->root;
  for (int j = 1; j <= numb_steps; j++)
  {//0 == left, 1 == right, 
    int direction = rand() % 2;
    printf("direction choseen:%d\n", direction);
    if (direction == 0)
    {
      if(current_node->left != NULL)
      {       
        current_node = current_node->left;
      }
      else
      { 
        return current_node;
      }
      
    }
    else
    {
      if(current_node->right != NULL)
      {
        current_node = current_node->right;
      }
      else
      {
        return current_node;
      }
    }
  }
    return current_node;
}
