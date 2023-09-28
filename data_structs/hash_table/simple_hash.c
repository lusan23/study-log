#include<stdio.h>
#include"hash.h"
#include<stdlib.h>
#include<string.h>

void prepareTable(hash_node * table, int size)
{
  for (int i = 0; i <= size-1; i++)
  {
      table[i].hash_code = i+1; 
      strncpy(table[i].key, "", sizeof(table[i].key));
      strncpy(table[i].value, "", sizeof(table[i].value));
      
    printf("new hash code:%s\n", table[i].key);
  }

}

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
      int result; 
      printf("division method\n");
      result = (getInt(new_key) % 30) + 1;
      
      return result;
    }
}

void insert(hash_node * table, int hash_code, 
char key[200], char value[200])
{//if there's no colisions insert the key and value to the list
  if (!table[hash_code].next)
  {
    strncpy(table[hash_code].key, key, sizeof(table[hash_code].key));
    strncpy(table[hash_code].value, value, sizeof(table[hash_code].key));
  } else
  {
    chain * current = table[hash_code].next;
      while (current->next != NULL)
	    {
	      current = current->next;
	    }
      
  }
  
}