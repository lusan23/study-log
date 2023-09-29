#include<stdio.h>
#include"hash.h"
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
const int TABLE_SIZE = 30;

void prepareTable(hash_node (*table)[TABLE_SIZE], int size)
{
  for (int i = 0; i <= size-1; i++)
  {
      (*table)[i].hash_code = i+1; 
      strncpy((*table)[i].key, "", sizeof((*table)[i].key));
      strncpy((*table)[i].value, "", sizeof((*table)[i].value));
    
  }
  printf("Setting up default values...\n");
  

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
      printf("getting hash code...\n");
      result = (getInt(new_key) % TABLE_SIZE) + 1;
      
      return result;
    }
}

/*
bool is_empty(hash_node table), int index)
{
  return (strcmp(table[index].key, "") == 0 && strcmp(table[index].value, "") == 0) ? true : false;
}
*/

void insert(hash_node (*table)[TABLE_SIZE], int hash_code, char new_key[200], char new_value[200])
{//if there's no colisions insert the key and value to the list
  int index = hash_code-1;
  if (strcmp((*table)[index].key, "") == 0 && strcmp((*table)[index].value, "") == 0)
  {
    printf("No collision case\n");
    strncpy((*table)[index].key, new_key, sizeof((*table)[index].key));
    strncpy((*table)[index].value, new_value, sizeof((*table)[index].value));
    (*table)[index].next = NULL;

  } else
  {  
    if ((*table)[index].next == NULL)
    {//if it's the first collision...
      printf("First colission case.\n");

      chain * current = (*table)[index].next;
      
      current = (chain *)malloc(sizeof(chain));
      strncpy(current->key, (*table)[index].key, sizeof(current->key));
      strncpy(current->value, (*table)[index].value, sizeof(current->value));
      
      current->next = (chain *)malloc(sizeof(chain));
      strncpy(current->next->key, new_key, sizeof(current->next->key));
      strncpy(current->next->value, new_value, sizeof(current->next->value));

      strncpy((*table)[index].key, "#", sizeof((*table)[index].key));
      strncpy((*table)[index].value, "#", sizeof((*table)[index].value));

      (*table)[index].next = current;
    } 
    else
    { //if is not the first collision....
      printf("Second or more collision case\n");
      chain * current = (*table)[index].next;

      while (current->next != NULL)
      {
        current = current->next;
      }
      assert(current->next == NULL);
      current->next = (chain *)malloc(sizeof(chain));
      strncpy(current->next->key, new_key, sizeof(current->next->key));
      strncpy(current->next->value, new_value, sizeof(current->next->value));
      current->next->next = NULL;
    }
  }
}