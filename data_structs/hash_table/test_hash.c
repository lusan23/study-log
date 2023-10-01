/*
Test case that verify the integrety of the table and the core functionality of insert, search and remove.
 
*/
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include"hash.h"

const int HASH_TABLE_SIZE = 10;
//tomorrow test the prehashing using the random words file


void test_alg_componentes(void)
{
  printf("test_alg_componentes\n");

  int i = 0;
  hash_tbl* table = createHashTable(HASH_TABLE_SIZE);
  
  while (i <= HASH_TABLE_SIZE-1)
    {
      assert(strcmp(table->table[i].key, "") == 0);
      assert(strcmp(table->table[i].value, "") == 0);
	  i++;
    //break
    }
    printf("Integrety test sucessful!!!\n");
}

int test_prehashing(char filename[300])
{
  hash_tbl * table = createHashTable(10);

   printf("test_prehashing\n");
  int max_line_length = 1000;
    FILE    *textfile;
    char    line[max_line_length];
     
    textfile = fopen(filename, "r");
    if(textfile == NULL)
        return 1;

    while(fgets(line, max_line_length, textfile))
    {
        printf("the hash of %s is: %d\n", line, insert(table, line, line));
    }

    fclose(textfile);
}


void test_preh(void)

{
  //from file prehashing.c
  test_prehashing("../hash_table/random-words.txt");
  
}

void test_colisions(void)
{
  printf("------------------------------COLIISIONS TEST------------------------------\n");
  hash_tbl* table = createHashTable(HASH_TABLE_SIZE);
  int hash_value = preHashing("test", 'd', table->size);
  printf("teste hash code:%d\n", hash_value);
  insert(table, "test", "random value");
  

  int hash_value_two = preHashing("test", 'd', table->size);
  insert(table, "test", "value");
  printf("teste hash code two:%d\n", hash_value_two);
  
  int hash_value_three = preHashing("test", 'd', table->size);
  insert(table, "test", "three");
  printf("teste hash code two:%d\n", hash_value_three);
  
  assert(strcmp(table->table[hash_value].key, "test") == 0);
  assert(strcmp(table->table[hash_value].value, "random value") == 0);
  
  assert(strcmp(table->table[hash_value_two+1].key, "test") == 0);
  assert(strcmp(table->table[hash_value_two+1].value, "value") == 0);

  assert(strcmp(table->table[hash_value_two+2].key, "test") == 0);
  assert(strcmp(table->table[hash_value_two+2].value, "three") == 0);

  print_all(table);
}

void test_search(void)
{
  printf("------------------------------SEARCH TESTE!!!!------------------------------\n");
  hash_tbl* table = createHashTable(HASH_TABLE_SIZE);
  int hash_value = preHashing("test", 'd', table->size);
  insert(table, "test", "random value");
  insert(table, "sdf", "asdf value");
  insert(table, "sdfsdf", "sei lá");
  
  print_all(table);
  printf("aaaa:%s\n", search(table, "sdf"));
  assert(strcmp(search(table, "sdf"), "asdf value") == 0);
  assert(strcmp(search(table, "test"), "random value") == 0);
  assert(strcmp(search(table, "sdfsdf"), "sei lá") == 0);
  assert(search(table, "oiasjfijsdf") == NULL);


  print_all(table);
}

void test_delete(void)
{
  printf("------------------------------DELETE TESTE!!!!------------------------------\n");
  hash_tbl* table = createHashTable(HASH_TABLE_SIZE);
  int a = insert(table, "test", "random value");
  insert(table, "sdf", "asdf value");
  insert(table, "sdfsdf", "sei lá");

  delete(table, "test");
  assert(strcmp(table->table[a].key, "\0") == 0 );
  assert(strcmp(table->table[a].value, "\0") == 0 );


}

int main (void)
{
  test_alg_componentes();
  //test_preh();
  test_colisions();
  test_search();
  test_delete();
  //test_massive_collisions("../hash_table/random-words.txt", "aisjd",1);
  //test_random_keys();
  
  return 0;
}
