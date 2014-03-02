#include <stdio.h>
#include "../lib/minunit.h"

#include "../src/list.h"
//#include "../src/list.c"

int tests_run = 0;

static char * test_list_insert() {
  int max = 10;
  List list;

  list_new(&list, sizeof(int), NULL);
  for(int i = 0; i < max; i++){
    list_append(&list, &i);
  }


  int head;
  list_head(&list, &head, true);
  mu_assert("error, head != 0", head == 0);

  list_head(&list, &head, true);
  mu_assert("error, head != 1", head == 1);

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

