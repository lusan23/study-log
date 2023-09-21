#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "stack.h"

START_TEST(test_push)
{
  ll_stack stack;

  stack.top = NULL;
  stack.size = 0;

  push(&stack, 10);

  ck_assert_int_eq(stack.top->val, 10);
  ck_assert_int_eq(stack.size, 1);
}
END_TEST

int main(void)
{
  Suite *s = suite_create("Stack Tests");

  TCase *tc_push = tcase_create("Push");
  tcase_add_test(tc_push, test_push);
  suite_add_tcase(s, tc_push);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);

  int num_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return num_failed;
}
