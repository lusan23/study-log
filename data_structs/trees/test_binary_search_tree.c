#include<stdio.h>
#include"trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

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

void test_bt(void)
{
  binary_tree *tree;
  malloc_binary_tree(&tree, 1);
  assert(tree != NULL);
  assert(tree->root != NULL);
  
  free_tree(&tree);
}

void test_insert(void)
{
  printf("insert after test...\n");
  binary_tree *t;
  malloc_binary_tree(&t,1);

   if (alloc_succeed(t->root))
   {
    /*
    tests based on the inorder transversal rule:
    the right child node x of node y == x node is after y
    the left child node x of node y ==  x node is before y

    */
      printf("worked!\n");

      subtree_insert_after(&t,&t->root, 10);
      assert(t->root->right->value == 10);
      printf("----\n");

      subtree_insert_after(&t,&t->root, 20);
      assert(t->root->right->left->value == 20);

      subtree_insert_after(&t, &t->root->right, 30);
      assert(t->root->right->right->value == 30);

      subtree_insert_after(&t, &t->root, 40);
      assert(t->root->right->left->left->value == 40);

      subtree_insert_after(&t, &t->root->right, 50);
      assert(t->root->right->right->left->value == 50);
    printAll(t); 
      for (int j = 0; j <= 5; j++)
      {
        int value = rand() % 100;
        tree_node* random_node = choose_rand_node(&t, 3);
        printf("inserting %d. after %d..\n", value, random_node->value);
        subtree_insert_after(&t, &random_node, value);
      }
   }

  //printAll(t);
  free_tree(&t);
}

void  test_last(void)
{
  binary_tree *t;
  malloc_binary_tree(&t,1);

   if (alloc_succeed(t->root))
   {
    /*
    tests based on the inorder transversal rule:
    the right child node x of node y == x node is after y
    the left child node x of node y ==  x node is before y

    */
  
      subtree_insert_after(&t, &t->root, 10);
      assert(t->root->right->value == 10);
      printf("LAST TEST\n");

      for (int j =  0; j <= 5; j++)
      { 
        int value = rand() % 10;
        tree_node* random_node = choose_rand_node(&t, 3);
        printf("inserting %d. after %d..\n", value, random_node->value);
        subtree_insert_after(&t, &random_node, value);
      }
   }
  printf("the last node is %d.\n", subtree_last(&t)->value);
  printAll(t);
  free_tree(&t);
}

void test_predecessor(void)
{
  printf("-------starting predecessor test...-------\n");
  binary_tree* t;
  malloc_binary_tree(&t, 100);
  
  subtree_insert_after(&t,&t->root, 10);
  
  assert(t->root->right->value == 10);
  printf("----\n");

  subtree_insert_after(&t,&t->root, 20);
  assert(t->root->right->left->value == 20);

  subtree_insert_after(&t, &t->root->right, 30);
  assert(t->root->right->right->value == 30);

  subtree_insert_after(&t, &t->root, 40);
  assert(t->root->right->left->left->value == 40);

  subtree_insert_after(&t, &t->root->right, 50);
  assert(t->root->right->right->left->value == 50);

  for (int j = 0; j <= 10; j++)
  { tree_node* random_node = choose_rand_node(&t, 3);
    tree_node* pdcs = predecessor(random_node);

    printf("The predecessor of %d is %d.\n", random_node->value, pdcs->value);  
  }
  printAll(t);
  free_tree(&t);
}


int main(void)
{ srand(time(0));
  test_bt();
  test_insert();
  test_last();
  test_predecessor();
  return 0;
}
