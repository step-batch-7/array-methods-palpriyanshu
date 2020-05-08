#include <stdio.h>
#include "test_lib.h"

void assert_int_equal(int actual, int expected){
  printf("%s", actual == expected ? " ✅" : " ❌");
};

void it(String text){
  printf("\n  %s :",text);
};

void describe(String text){
  printf("\n\n%s",text);
};
