#include<stdio.h>
#include"da.h"
#include"assert.h"
#include<stdlib.h>
const int ARR_SIZE = 5;
void test_unit_da_body(void)
{   
    printf("Integrity test\n");
    dinamic_array* numbers = setDA(ARR_SIZE);
    assert(searchEmpty(numbers) == 0);
    assert(numbers->i != NULL);
    printArr(numbers);
    assert(size(numbers) == ARR_SIZE);

    
    free(numbers->i);
    free(numbers);
    
}

void test_append (void)
{   printf("teste append\n");
    dinamic_array* numbers = setDA(ARR_SIZE);
    printArr(numbers);
    append(&numbers, 2938);
    append(&numbers, 28);
    append(&numbers, -1999);
    append(&numbers, 2938);
    append(&numbers, 2938);
    printArr(numbers);
    assert(numbers->i[numbers->size-1] == 2938);
    append(&numbers, 10);
    printArr(numbers);
    //assert(numbers->i[numbers->size-1] == 10);
    
    free(numbers->i);
    free(numbers);
    
}

void test_append_rand(void)
{
    printf("teste random append\n");
    dinamic_array* arr = setDA(5);
    printf("test\n");
    append(&arr, 2938);
    append(&arr, 28);
    append(&arr, -1999);
    append(&arr, 2938);
    append(&arr, 2938);
    
    for (int j = 0; j<= 10; j++)
    {
        
        int value =  rand() % 1000 *-1;
        
        append(&arr, value);
        
        assert(arr->i[arr->size-1] == value);
    }
    printArr(arr);
    free(arr->i);
    free(arr);
    
}

void test_insert(void)
{
  dinamic_array* arr = setDA(5);
    append(&arr, 12);
    append(&arr, 28);
    append(&arr, -99);
    printArr(arr);
    insert(&arr, 2, 1000);
    printArr(arr);
    insert(&arr, 0, 200);
    printArr(arr);
    insert(&arr, 0, -200);
    printArr(arr);


    
    printf("starting random delete...\n");
    for (int j = 0; j<= 5; j++)
    {
        
        int value =  rand() % 1000;
	int index = size(arr)/2;
        insert(&arr, index ,value);
        
        assert(arr->i[index] == value);
    }
    
    printArr(arr);
}


void test_delete(void)
{
  dinamic_array* arr = setDA(5);
    append(&arr, 12);
    append(&arr, 28);
    append(&arr, -99);
    insert(&arr, 2, 1000);
    insert(&arr, 0, 200);
    insert(&arr, 4, 200);
    
    printArr(arr);

    printf("starting random delete...\n");
    for (int j = 0; j<= 10; j++)
    {
        
      int index =  rand() % size(arr);
       delete(&arr, index);
	printArr(arr);
        //assert(arr->i[index] != value);
    }

    printArr(arr);
}

void test_peek(void)
{
    dinamic_array* arr = setDA(100);

    for (int i = 0; i<= size(arr)-1; i++)
      {
	int value = rand() % 10;
	insert(&arr, i, value);
	assert(peek(arr, i) == value);
      }
    printArr(arr);
}

void test_case_da(void)
{
    test_unit_da_body();
    test_append();
    test_append_rand();
    test_insert();
    test_delete();
    test_peek();
}

int main(void)
{
    test_case_da();
    return 0;
}
