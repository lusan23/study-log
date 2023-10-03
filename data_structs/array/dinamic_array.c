#include<stdio.h>
#include<stdlib.h>
#include"da.h"
#include<stdbool.h>
// implement
/*
Appending an element to the end of the array. done
Inserting an element at a specific index in the array.
Removing an element at a specific index in the array.
Getting the element at a specific index in the array.
Getting the size of the array.
*/

dinamic_array* setDA(int size)
{   
    dinamic_array* da = (dinamic_array*)calloc(1,sizeof(dinamic_array));
    if (da == NULL)
    {
        printf("allocation failed.\n");
    }
    da->i = (int*)calloc(size, sizeof(int));
    if (da->i == NULL)
    {
        printf("allocation failed.\n");
    }
    da->size = size;
    return da;
    
}

int searchEmpty(dinamic_array * da)
{   //return a index of the closest empty element if the array is full just return -1
    int i =0;
    if (!isFull(da))
    {
        while (i <= da->size-1)
        {
            if (da->i[i] != 0 )
            {
                i++;
            }
            else
            {
                return i;
            }
        }
    }
}

bool isFull (dinamic_array* da)
{
    bool is_full = true;
    for (int i=0; i <= da->size-1; i++)
    {  
        if (da->i[i] == 0)
        {
            is_full = false; 
            return is_full;
        }
    }
    return is_full;
}

void append(dinamic_array ** da, int dt)
{
    if (isFull((*da)))
    {
        (*da)->i = (int *)realloc((*da)->i, (sizeof(int) * (*da)->size) + (sizeof(int)));
        ((*da)->i == NULL) ? printf("allocation failed.\n") : printf("allocation succeed.\n");
        (*da)->size++; 
        (*da)->i[(*da)->size-1] = dt;
        printf("it's full!!\n");
    }
    
    (*da)->i[searchEmpty((*da))] = dt;
    
}

void printArr(dinamic_array* da)
{   printf("-----------------\n");
    for (int i=0; i <= da->size-1; i++)
    {
        printf("arr[%d] = %d\n", i, da->i[i]);
    }
}