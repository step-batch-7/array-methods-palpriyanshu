#include <stdio.h>
#include "test_lib.h"

void assert_void_int_equal(Void_ptr actual, Void_ptr expected){
  printf("%s", *(int *)actual == *(int *)expected ? " ✅" : " ❌");
};

void assert_void_char_equal(Void_ptr actual, Void_ptr expected){
  printf("%s", *(char *)actual == *(char *)expected ? " ✅" : " ❌");
};

void assert_equal(int actual, int expected){
  printf("%s", actual == expected ? " ✅" : " ❌");
};

void it(String text){
  printf("\n  %s :",text);
};

void describe(String text){
  printf("\n\n%s",text);
};
