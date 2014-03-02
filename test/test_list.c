#include <stdio.h>
#include "../lib/minunit.h"

#include "../src/list.h"
#include "../src/list.c"

int tests_run = 0;

static char * test_list_insert() {
  int max = 10;
  List list;

  for(int i = 0; i < max; i++){
    list_append(&list, &i);
  }


  void* head;
  list_head(&list, &head, true);
  //int j = 1;
  //head = &j;

  mu_assert("error, head != 1", *(int *)head == 1);
  return 0;
}
/*
   static char * test_bar() {
   mu_assert("error, bar != 5", bar == 5);
   return 0;
   }
   */
static char * all_tests() {
  mu_run_test(test_list_insert);
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

