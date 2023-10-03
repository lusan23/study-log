#ifndef DA_H_
#define DA_H_
#include<stdbool.h>

typedef struct dinamic_array
{
    int size;
    int * i;
}dinamic_array;
bool isFull (dinamic_array* da);
dinamic_array* setDA(int size);
void append(dinamic_array ** da, int dt);
void printArr(dinamic_array* da);
int searchEmpty(dinamic_array * da);
#endif