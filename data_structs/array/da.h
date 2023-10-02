#ifndef DA_H_
#define DA_H_

typedef struct dinamic_array
{
    int size;
    int * i;
}dinamic_array;

dinamic_array* setDA(int size);
void append(dinamic_array ** da, int dt);
void printArr(dinamic_array* da);

#endif