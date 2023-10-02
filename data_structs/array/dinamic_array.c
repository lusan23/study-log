#include<stdio.h>
#include<stdlib.h>
#include"da.h"
#include<stdbool.h>
dinamic_array* setDA(int size)
{   
    dinamic_array* da = (dinamic_array*)malloc(sizeof(dinamic_array));


    da->i = (int*)malloc(sizeof(int) * size);
    da->size = size;
    return da;
    
}

int searchEmpty(dinamic_array * da)
{
    int i =0;
    while (da->i[i] != 0)
    {
        i++;
    }
    return i;

}
bool isFull (dinamic_array* da)
{
    bool is_full = true;
    for (int i=0; i <= da->size-1; i++)
    {
        if (da->i[i] == 0){is_full = false  };
    }
    return is_full;
}
void append(dinamic_array ** da, int dt)
{
    if (isFull((*da)))
    {
        //use realloc here.
    }
    (*da)->i[searchEmpty((*da))] = dt;
    
}

void printArr(dinamic_array* da)
{
    for (int i=0; i <= da->size-1; i++)
    {
        printf("arr[%d] = %d\n", i, da->i[i]);
    }
}