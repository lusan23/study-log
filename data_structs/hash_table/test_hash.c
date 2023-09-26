//a set of tests for a simple hashing algorithm.
#include<stdio.h>
#include<assert.h>
#include"hash.h"
#include<stdlib.h>
#include<string.h>
struct hash_node hash_table[10];

//tomorrow test the prehashing using the random words file
void test_alg_componentes(void)
{
  //10 sized array
  /*

    [ 
      struct hash_node{hash_code; key; value; }, struct hash_node{hash_code; key; value; LL; }, ... , xm-1
    ]
    x
   */
  int i = 0;

  //strcpy(hash_table[5].key, "food");
  while (i<= 9)
    {
      printf("node:%s\n",hash_table[i].key);
      assert(hash_table[i].hash_code == 0);
      assert(strcmp(hash_table[i].key, "") == 0);
      assert(strcmp(hash_table[i].value, "") == 0);
      
	  i++;
    }
}

void test_prehashing(void)

{
  int hash = preHashing("asd90a", 'd');
  for (int i = 0; i<= 100; random)
}

/*

  //prehashing algorithm

   
    for (int i = 0; i <= 2; i++)
    {
      for (in t j = 0; i <= 9; j++)
	{
	  int hashGenerated;
	  assert(hashGenerated  == key % 10);
	}
    }
  //can i deal with collisions?

    //struct structname name[10] 
    add("food", "lasagne");
    add("food", "baozi");
    
  while (i<= 10)
    {
      if (hash_node.key == "food")
	{
	  assert(hash_node.LL != NULL);
	}
      i++;
    }

 */
int main (void)
{
  //test_alg_componentes();
  test_prehashing();

  
  
  return 0;
}
