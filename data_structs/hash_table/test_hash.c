//a set of tests for a simple hashing algorithm.
#include<stdio.h>
#include<assert.h>
#include"hash.h"
#include<stdlib.h>
#include<string.h>

const int HASH_TABLE_SIZE = 30;
//tomorrow test the prehashing using the random words file

void test_alg_componentes(void)
{
  printf("test_alg_componentes\n");
  int i = 0;
  hash_node hash_table[HASH_TABLE_SIZE];
  prepareTable(hash_table, HASH_TABLE_SIZE);
  //strcpy(hash_table[5].key, "food");
  while (i<= 29)
    {
      assert(hash_table[i].hash_code > 0 &&  hash_table[i].hash_code <= HASH_TABLE_SIZE);
      printf("hash code:%d\n", hash_table[i].hash_code);
      assert(strcmp(hash_table[i].key, "") == 0);
      assert(strcmp(hash_table[i].value, "") == 0);
	  i++;
    //break
    
    }
}

int test_prehashing(char filename[300])
{
   printf("test_prehashing\n");
  int max_line_length = 1000;
    FILE    *textfile;
    char    line[max_line_length];
     
    textfile = fopen(filename, "r");
    if(textfile == NULL)
        return 1;

    while(fgets(line, max_line_length, textfile))
    {
        printf("the hash of %s is: %d\n", line, preHashing(line, 'd'));
    }

    fclose(textfile);
}


void test_preh(void)

{
  //from file prehashing.c
  test_prehashing("random-words.txt");
  
}

void test_colisions(void)
{
  printf("test_colisions\n");
  char test_key[] = "sodifhsodf";
  char test_value[] = "dijpok";
  hash_node  hash_table[HASH_TABLE_SIZE];
  prepareTable(&hash_table, HASH_TABLE_SIZE);
  insert(&hash_table, preHashing(test_key, 'd'), test_key, test_value);
  assert(strcmp(*hash_table[preHashing(test_key,'d')-1].key, test_key) == 0);
  assert(strcmp(*hash_table[preHashing(test_key,'d')-1].value, test_value) == 0);
  printf("inserted\n");
  //first colision test
  insert(&hash_table, preHashing(test_key, 'd'), test_key, test_value);
  printf("aaa:%s\n", hash_table[preHashing(test_key, 'd')-1].next->key);
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].next->key, test_key) == 0);
  //assert(strcmp(*hash_table[preHashing(test_key,'d')-1].next->value, test_value) == 0);

}


/*

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
  test_alg_componentes();
  test_preh();
  test_colisions();
  
  
  return 0;
}
