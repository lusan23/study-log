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
    
    for (int j = 0; j<= 1000; j++)
    {
        int value =  rand() % 1000 *-1;
        
        append(&arr, value);
        
        assert(arr->i[arr->size-1] == value);
    }
    printArr(arr);
    free(arr->i);
    free(arr);
    
}
void test_case_da(void)
{
    test_unit_da_body();
    test_append();
    test_append_rand();
}

int main(void)
{
    test_case_da();
    return 0;
}