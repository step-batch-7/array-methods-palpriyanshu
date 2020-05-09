#include <stdlib.h>
#include <string.h>
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

Bool is_even_void(Object num){
  return *(int_ptr)num % 2 == 0;
}

Bool is_vowel_void(Object letter){
  char alphabet = *(char_ptr)letter;
  Bool lower_case_vowels = alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u';
  Bool upper_case_vowels = alphabet == 'A' || alphabet == 'E' || alphabet == 'I' || alphabet == 'O' || alphabet == 'U';
  return lower_case_vowels || upper_case_vowels;
}; 

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
  clear_array_void(src);
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
  clear_array_void(src);
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
  clear_array_void(src);
}

void test_for_reducing_int_array(void){
  it("* should return pointer to sum of numbers");
  int numbers[4] = {1,2,3,4};
  int init = 0;
  Object_ptr list = create_array_void(numbers, 4, copy_int);
  ArrayVoid_ptr src = get_array_void(list , 4);
  Object sum = reduce_void(src, &init, sum_void);
  assert_equal(*(int_ptr)sum, 10);
  clear_array_void(src);
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
  clear_array_void(mapped_src);
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
  clear_array_void(mapped_src);
};

void test_map_void(void){
  describe("# MAP_VOID");
  test_for_increment_numbers();
  test_for_to_lower_case();
}

void test_for_all_value_false(void){
  it("* should give pointer to empty Void array when all values are false");
  int numbers[4] = {1,7,3,9};
  Object_ptr list = create_array_void(numbers, 4, copy_int);
  ArrayVoid_ptr src = get_array_void(list , 4);
  ArrayVoid_ptr filtered_src = filter_void(src, is_even_void);
  assert_equal(filtered_src->length, 0);
  clear_array_void(src);
};

void test_for_all_value_true(void){
  it("* should give pointer to same Void array when all values are true");
  int numbers[4] = {2,4,6,8};
  Object_ptr list = create_array_void(numbers, 4, copy_int);
  ArrayVoid_ptr src = get_array_void(list , 4);
  ArrayVoid_ptr filtered_src = filter_void(src, is_even_void);
  assert_equal(filtered_src->length, 4);
  assert_equal(*(int_ptr)(filtered_src->array[0]), 2);
  assert_equal(*(int_ptr)(filtered_src->array[1]), 4);
  assert_equal(*(int_ptr)(filtered_src->array[2]), 6);
  assert_equal(*(int_ptr)(filtered_src->array[3]), 8);
  clear_array_void(src);
};

void test_for_is_even_present(void){
  it("* should filter even numbers");
  int numbers[4] = {1,4,7,8};
  Object_ptr list = create_array_void(numbers, 4, copy_int);
  ArrayVoid_ptr src = get_array_void(list , 4);
  ArrayVoid_ptr filtered_src = filter_void(src, is_even_void);
  assert_equal(filtered_src->length, 2);
  assert_equal(*(int_ptr)(filtered_src->array[0]), 4);
  assert_equal(*(int_ptr)(filtered_src->array[1]), 8);
  clear_array_void(src);
};

void test_for_is_vowel(void){
  it("* should filter vowels");
  char letters[4] = {'A','C','d','i'};
  Object_ptr list = create_array_void(letters, 4, copy_char);
  ArrayVoid_ptr src = get_array_void(list , 4);
  ArrayVoid_ptr filtered_src = filter_void(src, is_vowel_void);
  assert_equal(filtered_src->length, 2);
  assert_equal(*(char_ptr)(filtered_src->array[0]), 'A');
  assert_equal(*(char_ptr)(filtered_src->array[1]), 'i');
  clear_array_void(src);
};

void test_filter_void(void){
  describe("# FILTER_VOID");
  test_for_all_value_false();
  test_for_all_value_true();
  test_for_is_even_present();
  test_for_is_vowel();
}