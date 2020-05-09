#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "test_lib.h"
#include "../array_void.h"

void test_int_array(void){
  it("* should return a pointer of structure having an int array address and its length");
  int num1 = 1, num2 = 2, num3 = 3, num4 = 4;
  Object list[4] = {&num1, &num2, &num3, &num4};
  ArrayVoid_ptr src = get_array_void(list , 4);
  assert_equal(src->length, 4);
  assert_void_int_equal(src->array[0], list);
  assert_void_int_equal(src->array[1], list+1);
  assert_void_int_equal(src->array[2], list+2);
  assert_void_int_equal(src->array[3], list+3);
  free(src);
}

void test_char_array(void){
  it("* should return a pointer of structure having an char array address and its length");
  char num1 = 'a', num2 = 'b', num3 = 'c', num4 = 'd';
  Object list[4] = {&num1, &num2, &num3, &num4};
  ArrayVoid_ptr src = get_array_void(list , 4);
  assert_equal(src->length, 4);
  assert_void_char_equal(src->array[0], list);
  assert_void_char_equal(src->array[1], list+1);
  assert_void_char_equal(src->array[2], list+2);
  assert_void_char_equal(src->array[3], list+3);
  free(src);
}

void test_get_array_void(void){
  describe("# GET_ARRAY_VOID");
  test_int_array();
  test_char_array();
};