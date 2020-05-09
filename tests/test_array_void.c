#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "test_lib.h"
#include "../array_void.h"

void test_copy_int(void){
  describe("# COPY_INT");
  it("* should copy int value");
  int numbers[4] = {1,2,3,4};
  assert_equal(*(int_ptr)copy_int(numbers, 2), 3);
}

void test_copy_char(void){
  describe("# COPY_CHAR");
  it("* should copy char value");
  char letters[4] = {'a','b','c','d'};
  assert_equal(*(char_ptr)copy_char(letters, 2), 'c');
}

void test_for_create_int_array(void){
  it("* should create int array");
  int numbers[4] = {1,2,3,4};
  Object_ptr array = create_array_void(numbers, 4, copy_int);
  assert_void_int_equal(*array, numbers);
  assert_void_int_equal(*(array + 1), numbers + 1);
  assert_void_int_equal(*(array + 2), numbers + 2);
  assert_void_int_equal(*(array + 3), numbers + 3);
}

void test_for_create_char_array(void){
  it("* should create char array");
  char letters[4] = {'a','b','c','d'};
  Object_ptr array = create_array_void(letters, 4, copy_char);
  assert_void_char_equal(*array, letters);
  assert_void_char_equal(*(array + 1), letters + 1);
  assert_void_char_equal(*(array + 2), letters + 2);
  assert_void_char_equal(*(array + 3), letters + 3);
}

void test_create_array_void(void){
  describe("# CREATE_ARRAY_VOID");
  test_for_create_int_array();
  test_for_create_char_array();
}

void test_for_int_array(void){
  it("* should return a pointer of structure having an int array address and its length");
  int numbers[4] = {1,2,3,4};
  Object_ptr list = create_array_void(numbers, 4, copy_int);
  ArrayVoid_ptr src = get_array_void(list , 4);
  assert_equal(src->length, 4);
  assert_void_int_equal(src->array[0], numbers);
  assert_void_int_equal(src->array[1], numbers+1);
  assert_void_int_equal(src->array[2], numbers+2);
  assert_void_int_equal(src->array[3], numbers+3);
  free(src);
}

void test_for_char_array(void){
  it("* should return a pointer of structure having an char array address and its length");
  char letters[4] = {'a','b','c','d'};
  Object_ptr list = create_array_void(letters, 4, copy_char);
  ArrayVoid_ptr src = get_array_void(list , 4);
  assert_equal(src->length, 4);
  assert_void_char_equal(src->array[0], letters);
  assert_void_char_equal(src->array[1], letters+1);
  assert_void_char_equal(src->array[2], letters+2);
  assert_void_char_equal(src->array[3], letters+3);
  free(src);
}

void test_get_array_void(void){
  describe("# GET_ARRAY_VOID");
  test_for_int_array();
  test_for_char_array();
};
