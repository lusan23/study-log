#ifndef HASH_H_
#define HASH_H_

typedef struct hash_node
{
  char key[200];
  char value[200];
} hash_node;


typedef struct hash_tbl
{
  hash_node* table;
  int size;
} hash_tbl;


hash_tbl* createHashTable(int size);
int preHashing(char new_key[200], char hashing_function, int size);
int insert(hash_tbl* table , char new_key[200], char new_value[200]);
char * search(hash_tbl * table, char key[200]);
char * delete(hash_tbl * table, char key[200]);
void print_all(hash_tbl* table);
void free_table(hash_tbl* table);
#endif