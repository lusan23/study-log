#include<stdio.h>
#include"da.h"
#include"assert.h"

const int ARR_SIZE = 5;
void test_unit_da_body(void)
{   
 
    dinamic_array* numbers = setDA(ARR_SIZE);

    assert(numbers->i != NULL);
    printArr(numbers);
}

void test_append (void)
{   printf("teste append\n");
    dinamic_array* numbers = setDA(ARR_SIZE);
    append(&numbers, 2938);
    append(&numbers, 28);
    append(&numbers, -1999);
    append(&numbers, 2938);
    append(&numbers, 2938);
    append(&numbers, 2938);
    
    printArr(numbers);
    
}

void test_case_da(void)
{
    test_unit_da_body();
    test_append();
}

int main(void)
{
    test_case_da();
    return 0;
}