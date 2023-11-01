#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../../tree.h"
#include"test_bst.h"

const int TEST_NUMB = 5;

void test_find_th(void)
{
    binary_tree* t;
    //NOT BST FUNCTIONS.
    malloc_binary_tree(&t, 50);

    // RANDOM TEST
    printf("Starting random inserting randomly...\n");

    int expected_array[TEST_NUMB];
    int output_array[TEST_NUMB];
       
    for (int i = 0; i < TEST_NUMB; i++)
    {
        int j = rand() % 100;
        bst_subtree_insert(&t->root, j);
      expected_array[i] = j;
    }

    int tmp;
    for (int i = 0; i < TEST_NUMB; i++)
    {
      tmp =  subtree_find_ith(&t->root, i)->value;
      output_array[i] = tmp;
      
    }
    free_tree(&t);
   
}