#include <stdio.h>
#include "test_lib.h"
#include "../array.h"
#include "../array_void.h"
#include "tests.h"
#include "test_array_void.h"

void runTests(void);

void runTests(void){
  test_get_array();
  test_reduce();
  test_map();
  test_filter();
  test_copy_int();
  test_copy_char();
  test_create_array_void();
  test_get_array_void();
  test_reduce_void();
  test_map_void();
  test_filter_void();
}

int main() {
  printf("TESTS_START_______________\n");
  runTests();
  printf("\n\nTESTS_END_______________\n");
  return 0;
}