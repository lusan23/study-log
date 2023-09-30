#ifndef HASH_H_
#define HASH_H_
typedef struct chain
{

  char key[200];
  char value[200];
  struct chain * next;
} chain;

typedef struct hash_node
{
  int hash_code;
  char key[200];
  char value[200];
  chain * next;
} hash_node;

void prepareTable(hash_node (*table)[5], int size);
int getInt (char key[200]);
int preHashing(char new_key[200], char hashing_function);
int insert(hash_node (*table)[5], int hash_code, char new_key[200], char new_value[200]);

#endif
