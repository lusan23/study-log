//a set of tests for a simple hashing algorithm.
#include<stdio.h>
#include<assert.h>
#include"hash.h"
#include<stdlib.h>
#include<string.h>

const int HASH_TABLE_SIZE = 30;
//tomorrow test the prehashing using the random words file

void log_data(hash_node (*table)[30], int hash)
{
  hash_node node = (*table)[hash];
  printf("\n\n\nhash_code:%d\n", node.hash_code);
  printf("key:%s\n", node.key);
  printf("value%s\n", node.value);
  printf("next:%d\n\n\n", node.next);
}

void test_alg_componentes(void)
{
  printf("test_alg_componentes\n");
  int i = 0;
  hash_node  hash_table[HASH_TABLE_SIZE];
  prepareTable(&hash_table, HASH_TABLE_SIZE);
  //strcpy(hash_table[5].key, "food");
  while (i<= 29)
    {
      assert(hash_table[i].hash_code > 0 &&  hash_table[i].hash_code <= HASH_TABLE_SIZE);
      assert(strcmp(hash_table[i].key, "") == 0);
      assert(strcmp(hash_table[i].value, "") == 0);
	  i++;
    //break
    }
    printf("Integrety test sucessful!!!\n");
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
int test_massive_collisions(char filename[300])
{
  printf("setting up file input for massive test...\n");
  //reading file block
  int max_line_length = 1000;
  FILE    *textfile;
  char    line[max_line_length];
     
  textfile = fopen(filename, "r");
  if(textfile == NULL)
    
    return 1;

  printf("Starting massive collisions test...\n");
  char test_key[] = "sodifhsodf";
  char test_value[] = "dijpok";
  hash_node  hash_table[HASH_TABLE_SIZE];
  prepareTable(&hash_table, HASH_TABLE_SIZE);

  log_data(&hash_table, preHashing(test_key,'d')-1);

  insert(&hash_table, preHashing(test_key, 'd'), test_key, test_value);
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].key, test_key) == 0);
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].value, test_value) == 0);

  log_data(&hash_table, preHashing(test_key,'d')-1);

  //first colision test
  insert(&hash_table, preHashing(test_key, 'd'), test_key, "twoo");
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].next->next->key, test_key) == 0);
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].next->next->value, "twoo") == 0);

  log_data(&hash_table, preHashing(test_key,'d')-1);
  int count;
  while(fgets(line, max_line_length, textfile))
  {
    printf("\n%d: Testing key: %s and value:%s\n",count ,test_key, line);
    insert(&hash_table,preHashing(test_key, 'd'),test_key,line);
      log_data(&hash_table, preHashing(test_key,'d')-1);

    chain * current = hash_table[preHashing(test_key,'d')-1].next;
    
    //reaching last node on the chain
    while (current->next != NULL)
    {
      current = current->next;
    }
    //printf("teste:%s\n", current->next->value);
    assert(strcmp(current->key, test_key) == 0);
    assert(strcmp(current->value, line) == 0);
    count++;
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
  hash_node   hash_table[HASH_TABLE_SIZE];
  prepareTable(&hash_table, HASH_TABLE_SIZE);
  
  insert(&hash_table, preHashing(test_key, 'd'), test_key, test_value);
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].key, test_key) == 0);
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].value, test_value) == 0);
  

  //first colision test
  insert(&hash_table, preHashing(test_key, 'd'), test_key, "twoo");
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].next->next->key, test_key) == 0);
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].next->next->value, "twoo") == 0);

  //second colision test
  insert(&hash_table, preHashing(test_key, 'd'), test_key, "threee");
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].next->next->next->key, test_key) == 0);
  assert(strcmp(hash_table[preHashing(test_key,'d')-1].next->next->next->value, "threee") == 0);

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
  test_massive_collisions("../hash_table/random-words.txt");
  
  return 0;
}
