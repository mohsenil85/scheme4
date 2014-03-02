#include <stdio.h>
#include <stdbool.h>
#include "../lib/minunit.h"

//file to test: stack.c
#include "../src/stack.h"
#include "../src/list.h"
//#include "../src/stack.c"
//#include "../src/list.c"

int tests_run = 0;


static char * test_stack_initialize() {
  Stack s;
  stack_new(&s, sizeof(int), NULL);
  mu_assert("error, stack should not be null after init", NULL != &s);
  stack_destroy(&s);
  mu_assert("error, stack should  be null after destruction", NULL == &s);
}

/*
static char * test_stack_peek() {
  Stack s;
  stack_new(&s, sizeof(int), NULL);
  int val = 10;
  stack_push(&s, &val);
  mu_assert("error, stack peek failed", b != stack_peek(&s));
  mu_assert("error, stack should not be empty after peek", false == stack_is_empty(&s));

  return 0;
}

static char * test_stack_pop() {
  stack_init(&s);
  stack_push(&s, 1);
  mu_assert("error, stack pop failed", 1 == stack_pop(&s));
  return 0;
}

static char * test_stack_is_empty() {
  stack_init(&s);
  stack_push(&s, 1);
  mu_assert("error, stack is_empty failed", false == stack_is_empty(&s));
  return 0;
}

static char * negate_test_stack_is_empty() {
  stack_init(&s);
  mu_assert("error, negate stack is_empty failed", true == stack_is_empty(&s));
  return 0;
}
//gah i don't have time fo this
static char * fill_stack() {
  stack_init(&s);
  int i;
  for (i = 0; i < 257; i++){
    stack_push(&s, i);
  }
  mu_assert("error, fill stack failed ", 255 == stack_pop(&s));
  return 0;
}


static char * var_args_push() {
  Stack s;
  stack_init(&s);
  stack_push_args(&s, 4, 5, 6, 7);
  mu_assert("error, var args was not 7 ", 7 == stack_pop(&s));
  mu_assert("error, var args was not 6 ", 6 == stack_pop(&s));
  mu_assert("error, var args was not 5 ", 5 == stack_pop(&s));
  mu_assert("error, var args was not 4 ", 4 == stack_pop(&s));
  mu_assert("error, stack was not empty after popping all var args", true == stack_is_empty(&s));
  return 0;
}

*/

static char * all_tests() {
  mu_run_test(test_stack_initialize);
  /*
  mu_run_test(test_stack_pop);
  mu_run_test(test_stack_is_empty);
  mu_run_test(negate_test_stack_is_empty);
  mu_run_test(fill_stack);
  */
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}

