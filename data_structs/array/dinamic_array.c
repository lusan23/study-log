#include<stdio.h>
#include<stdlib.h>
#include"da.h"
#include<stdbool.h>
#include<string.h>
// implement
/*
Appending an element to the end of the array. done
Inserting an element at a specific index in the array. done
Removing an element at a specific index in the array. done
Getting the element at a specific index in the array. done
Getting the size of the array. done
*/

dinamic_array* setDA(int size)
{   /*
    creates the heap (allocates memory dinamically)on memory for the and returns its pointers.
    space complexity O(1)
    */
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
{   /*
    //return a index of the closest empty element if the array is full just return -1
    running time complexity O(n)
    */
    int i =0;
    if (!isFull(da))
    {
        if (da->size == 0)
        {
            return -1;
        }
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

bool isEmpty(dinamic_array* da)
{   //verifies if there any other value different than 0

    int is_empty = true;
    if (da->size == 0)
    {
        return is_empty;
    }
    else
    {
        
        for (int j = 0; j <= da->size-1; j++)
        {
            printf("verifying %d, index:%d...\n",da->i[j], j );
            if (da->i[j] !=  0)
            {   
                is_empty = false;
                return is_empty;
            }
        }
    
        return is_empty;
    }
   

}

bool isFull (dinamic_array* da)
{   /*
        Verifies if there's any empty element (0 value) on the DA/heap/allocated memory
        Linear time complexity
    */
    bool is_full = true;
    if (da->size == 0)
    {
        is_full = false;
        return is_full;
    }
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
    /*
        Adds a new element to the end of the array.

        Worst case scenario O(n) : if there's a empty element after the last not 
        empty element (in linear order), so it just changes its value to 'dt'.
        (it's linear time because of searchEmpty())

        Best case scenario Omega(1): There's no empty element, so reallocate the heap 
        with the size of cuurent size + int size 

    */
     if ((*da)->size == 0)
     {
        (*da)->i = (int *)realloc((*da)->i, (sizeof(int) * (*da)->size) + (sizeof(int)));
        (*da)->i[0] = dt;
        (*da)->size++;
     }
     else
     
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
}

void insert(dinamic_array ** da,int index, int new_value)
{
    
    if (!isEmpty)
        printf("size:%d\n", (*da)->size-1);
    {   printf("inserting %d in ar[%d]\n", new_value, index);
        if (index == (*da)->size-1)
        {   
            printf("best case\n");
            
            (*da)->i = (int *)realloc((*da)->i,  (sizeof(int) * (*da)->size) + sizeof(int));
            
            (*da)->size++;
            int tmp = (*da)->i[index];
            printf("teste\n");
            (*da)->i[index] = new_value;
            (*da)->i[index+1] = tmp;
        }
        else 
        {   //realloc heap-overflowing
            printf("worst case\n");
              printArr((*da));
            (*da)->i = (int *)realloc((*da)->i,  (sizeof(int) * (*da)->size) + sizeof(int));

            (*da)->size++;
            
            int tmp = (*da)->i[index];
            
            (*da)->i[index] = new_value;
            printArr((*da));
            for (int j = size((*da)) - 1; j >= index+2; j--)
            {  
                (*da)->i[j] = (*da)->i[j-1];
            }
            (*da)->i[index] = tmp;
                          

        }
    }
}

int delete(dinamic_array** da, int index)
{
    /*
        Best case scenario (Constant time / Linear space complexity): 
            the given index is the last element in the heap/memory.
            Set the value to zero and allocate new heap of current size - the sizeof int
            and move the previous content to there            

        Worst case scenario (Linear time): the given index it's not the last element in the heap.
            replace da->i[index] by da->i[index + 1] until index + 1 is equal to da->size. 
            it would take index - size instructions, therefore it's linear.
    */
   if (!isEmpty((*da)))
   {

        if ((*da) != NULL && (*da)->i != NULL)
        {
        
            if (index == (*da)->size-1)
                /*
                   takes all the data to a temp heap, free the old one and moves 
                   from the temp to the new heap.
                */
            {
                (*da)->i[index] = 0;
                (*da)->size--;
                (*da)->i = (int *)realloc((*da)->i,  sizeof(int) * (*da)->size);

            }
            else
            {
                //implement worst case scnario
                printf("worst case\n");
                int j = 0;
                while (j <= (*da)->size-2)
                {
                    (*da)->i[j] = (*da)->i[j+1]; 
                    j++; 
                }
                printf("print\n");
                (*da)->i[j] = 0;
                (*da)->size--;
                (*da)->i = (int *)realloc((*da)->i,  sizeof(int) * (*da)->size);
                printf("realloc((*da)->i,  %ld * %d);\n", sizeof(int), (*da)->size);
                
            }
        }
    }
    else
    {
        printf("Delete failed! It's a empty array!!!\n");
    }
    
   
   
}
int peek(dinamic_array *da, int index)
{
    if (!isEmpty(da))
    {
        if (da->i[index] != 0)
        {
            return da->i[index];
        }
        else
        {
            printf("the index %d is empty!!!!\n", index);
            return -1;
        }
    }
}
int size(dinamic_array *da)
{   /*
        It gets the size value in the no pointer member of dinamic_array
        Constant time
    */
    return (da != NULL && da->i != NULL) ? da->size : -1;
}

void printArr(dinamic_array* da)
    /*
        Prints the whole heap/allocated memory on the console.
        Linear time
    */
    
{   printf("-----------------\n");
    if (!isEmpty(da))
    {
        {
            for (int i=0; i <= da->size-1; i++)
            {
                printf("arr[%d] = %d\n", i, da->i[i]);
            }
        }
    }
}