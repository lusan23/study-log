#include<stdio.h>
#include"hash.h"
#include<stdlib.h>
#include<string.h>


struct hash_node hash_table[10];

int getInt (char key[200])
{//increments  the code point of each char of the string
  int val;
  for (int i = 0; i <strlen(key); i++)
    {
      val+= (int)key[i];
    }
}

int preHashing(char new_key[200], char hashing_function)
{//creates a hashing code for the given key
  if (hashing_function ==  'd')
    {//use division method as default
      printf("division method\n");
      return getInt(new_key) % 10;
    }
}
