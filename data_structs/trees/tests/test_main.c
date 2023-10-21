#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"

void test_primitive_opr(void)
{
  //test case for the primitive functions
  test_bt();
  test_first();
  test_last();
  test_predecessor();
  test_sucessor();

}

void test_basic_opr(void)
{
  //test case for the basic operations
  test_insert_before();
  //test_insert_after();  
}

void test_global_opr(void)
{
  //test case for the global operations
    test_global_insert();
    
}


int main(void)
{ srand(time(0));
  //test_primitive_opr();
  test_basic_opr();
  //test_global_opr();
  return 0;
}
