#include <stdio.h>
#include "test_lib.h"
#include "../array.h"
#include "tests.h"

void runTests(void);

void runTests(void){
  test_get_array();
  test_reduce();
  test_map();
  test_filter();
}

int main() {
  printf("TESTS_START_______________\n");
  runTests();
  printf("\n\nTESTS_END_______________\n");
  return 0;
}