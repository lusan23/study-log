/*
A simple hashing function sample for learning porpuses,
It's a hashing division function that handle collisions using opening address/probing. 
*/
#include<stdio.h>
#include<stdlib.h>
#include"hash.h"
#include<string.h>
#include<stdbool.h>
#include<assert.h>

static inline void check_alloc(hash_tbl* table) {(table == NULL && table->table == NULL) ? printf("allocation failed.\n") : printf("allocation succeed.\n");}
inline void free_table(hash_tbl* table) {free(table->table); free(table);}
static inline bool string_equals(char* a, char* b) { return strcmp(a,b) == 0; }
hash_tbl* createHashTable(int size)
{
  hash_tbl* table = malloc(sizeof(hash_tbl));
  check_alloc(table);
  table->table = malloc(sizeof(hash_node) * size);
  check_alloc(table->table);
  table->size = size;
  
  for (int i = 0; i < size; i++)
  {
    strncpy(table->table[i].key, "", sizeof(table->table[i].key));
    strncpy(table->table[i].value, "", sizeof(table->table[i].value));
  }
  return table;
}

int getInt (char key[200])
{//increments  the code point of each char of the string
  unsigned int val;
  for (int i = 0; i <strlen(key); i++)
    {
      val+= (int)key[i];
    }

}

 int preHashing(char new_key[200], char hashing_function, int size)
{//creates a hashing code for the given key
  if (hashing_function ==  'd')
    {//use division method as default
      int result; 
      printf("getting hash code...\n");
      result = (getInt((new_key)) % size);
      
      return result;
    }
}

int linearProb(int hash_code, int size)
{
  hash_code++;
  hash_code %=  size;
  return hash_code;
}

int insert(hash_tbl* table ,  char new_key[200], char new_value[200])
{ /*
    if the insertion is sucessfull return the hash/index of the key.
    if not return -1
    Handling collisisons through open addressing
  */

  int hash_value = preHashing(new_key, 'd', table->size);
  printf("key:%s\n", table->table[hash_value].key);
  while (!string_equals(table->table[hash_value].key, "") && !string_equals(table->table[hash_value].key, "\0"))
  {
    hash_value = linearProb(hash_value, table->size);
  }
  if (hash_value == table->size-1 && !string_equals(table->table[hash_value].key, ""))
  {
    printf("unable to insert. table is full.\n");
    return -1;
  }
  {
    strncpy(table->table[hash_value].key, new_key, sizeof(table->table[hash_value].key));
    strncpy(table->table[hash_value].value, new_value, sizeof(table->table[hash_value].value));
    return hash_value;
  }
}

    
    


char * search(hash_tbl * table, char key[200])
{
  /*
    searches for the given key, if found returns the value
    otherwise return # to indicate not found
  */
  int   hash_value = preHashing(key, 'd', table->size);
    
  while (!string_equals(table->table[hash_value].key, key))
  {
    printf("teste1:%d\n", hash_value);

    hash_value =  linearProb(hash_value, table->size);
    
    if (hash_value+=1 == 10)
    {
      printf("Key not Found!!!\n");
      return NULL;
    }
    
  }

  printf("teste2\n");
 
  return table->table[hash_value].value;
 
}

char * delete(hash_tbl * table, char key[200])
{ 
  int   hash_value = preHashing(key, 'd', table->size);
  while (!string_equals(table->table[hash_value].key, key))
  {


    hash_value = linearProb(hash_value, table->size);
    if (hash_value+=1 == 10)
    {
      printf("Key not Found!!!\n");
      return NULL;
    }
    
  }
  char * retval = table->table[hash_value].value; 
  strncpy(table->table[hash_value].key, "\0", sizeof(table->table[hash_value].key));
  strncpy(table->table[hash_value].value, "\0", sizeof(table->table[hash_value].value));
  return retval;
}

void print_all(hash_tbl* table)
{
  printf("-------------print all--------------\n");
  for (int i = 0; i <= table->size-1; i++)
  {
    printf("table[%d]:\nkey:%s\nvalue:%s\n",i, table->table[i].key, table->table[i].value);
  }

}