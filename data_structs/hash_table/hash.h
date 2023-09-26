#ifndef HASH_H_
#define HASH_H_

typedef struct hash_node{
  int hash_code;
  char key[200];
  char value[200];
} hash_node;


int preHashing(char new_key[200], char hashing_function);
int getInt (char key[200]);
#endif
