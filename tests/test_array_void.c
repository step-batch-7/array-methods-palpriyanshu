#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "test_lib.h"
#include "../array_void.h"

Object sum_void(Object num1, Object num2){
  int_ptr sum = malloc(sizeof(int));
  *sum = *(int_ptr)num1 + *(int_ptr)num2;
  return sum;
};

Object increment_void(Object num){
  int_ptr incremented = malloc(sizeof(int));
  *incremented = *(int_ptr)num + 1;
  return incremented;
}

Object to_lower_case_void(Object letter){
  char alphabet = *(char_ptr)letter;
  char_ptr lower_cased = malloc(sizeof(char));
  *lower_cased = alphabet >= 65 && alphabet <= 90 ? alphabet + 32 : alphabet;
  return lower_cased;
}

void test_copy_int(void){
  describe("# COPY_INT");
  it("* should copy int value");
  int numbers[4] = {1,2,3,4};
  Object element = copy_int(numbers, 2);
  assert_equal(*(int_ptr)element, 3);
  free(element);
}

void test_copy_char(void){
  describe("# COPY_CHAR");
  it("* should copy char value");
  char letters[4] = {'a','b','c','d'};
  Object element = copy_char(letters, 2);
  assert_equal(*(char_ptr)element, 'c');
  free(element);
}

void test_for_create_int_array(void){
  it("* should create int array");
  int numbers[4] = {1,2,3,4};
  Object_ptr array = create_array_void(numbers, 4, copy_int);
  assert_void_int_equal(*array, numbers);
  assert_void_int_equal(*(array + 1), numbers + 1);
  assert_void_int_equal(*(array + 2), numbers + 2);
  assert_void_int_equal(*(array + 3), numbers + 3);
  free(array);
}

void test_for_create_char_array(void){
  it("* should create char array");
  char letters[4] = {'a','b','c','d'};
  Object_ptr array = create_array_void(letters, 4, copy_char);
  assert_void_char_equal(*array, letters);
  assert_void_char_equal(*(array + 1), letters + 1);
  assert_void_char_equal(*(array + 2), letters + 2);
  assert_void_char_equal(*(array + 3), letters + 3);
  free(array);
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
  free(list);
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
  free(list);
}

void test_get_array_void(void){
  describe("# GET_ARRAY_VOID");
  test_for_int_array();
  test_for_char_array();
};

void test_for_empty_array_void(void){
  it("* should return pointer to initial value for empty array");
  int numbers[] = {};
  int init = 1;
  Object_ptr list = create_array_void(numbers, 0, copy_int);
  ArrayVoid_ptr src = get_array_void(list , 0);
  Object sum = reduce_void(src, &init, sum_void);
  assert_equal(*(int_ptr)sum, 1);
  free(src);
  free(list);
}

void test_for_reducing_int_array(void){
  it("* should return pointer to sum of numbers");
  int numbers[4] = {1,2,3,4};
  int init = 0;
  Object_ptr list = create_array_void(numbers, 4, copy_int);
  ArrayVoid_ptr src = get_array_void(list , 4);
  Object sum = reduce_void(src, &init, sum_void);
  assert_equal(*(int_ptr)sum, 10);
  free(src);
  free(list);
}

void test_reduce_void(void){
  describe("# REDUCE_VOID");
  test_for_empty_array_void();
  test_for_reducing_int_array();
}

void test_for_increment_numbers(void){
  it("* should increment each number by 1");
  int numbers[4] = {1,2,3,4};
  Object_ptr list = create_array_void(numbers, 4, copy_int);
  ArrayVoid_ptr src = get_array_void(list , 4);
  ArrayVoid_ptr mapped_src = map_void(src, increment_void);
  assert_equal(mapped_src->length, 4);
  assert_equal(*(int_ptr)(mapped_src->array[0]), 2);
  assert_equal(*(int_ptr)(mapped_src->array[1]), 3);
  assert_equal(*(int_ptr)(mapped_src->array[2]), 4);
  assert_equal(*(int_ptr)(mapped_src->array[3]), 5);
  free(src);
  free(mapped_src);
  free(list);
}

void test_for_to_lower_case(void){
  it("* should convert to lower case each alphabet");
  char letters[4] = {'A','K','m','Z'};
  Object_ptr list = create_array_void(letters, 4, copy_char);
  ArrayVoid_ptr src = get_array_void(list , 4);
  ArrayVoid_ptr mapped_src = map_void(src, to_lower_case_void);
  assert_equal(mapped_src->length, 4);
  assert_equal(*(char_ptr)(mapped_src->array[0]), 'a');
  assert_equal(*(char_ptr)(mapped_src->array[1]), 'k');
  assert_equal(*(char_ptr)(mapped_src->array[2]), 'm');
  assert_equal(*(char_ptr)(mapped_src->array[3]), 'z');
  free(src);
  free(mapped_src);
  free(list);
};

void test_map_void(void){
  describe("# MAP_VOID");
  test_for_increment_numbers();
  test_for_to_lower_case();
}
