#include <stdlib.h>
#include <string.h>
#include "test_lib.h"
#include "../array.h"

int multiply(int, int);
int increment(int);
int square(int);
Bool is_odd(int);
Bool is_even(int);

int multiply(int num1, int num2){
  return num1 * num2;
}

int increment(int num){
  return num + 1;
}

int square(int num){
  return num * num;
}

Bool is_odd(int num){
  return num % 2 ;
};

Bool is_even(int num){
  return !is_odd(num) ;
};

void test_get_array(void){
  describe("# GET_ARRAY");
  it("* should return a pointer of structure having an array and its length");
  int list[4] = {1,2,3,4}; 
  Array_ptr src = get_array(list , 4);
  assert_equal(src->length, 4);
  assert_equal(src->array[0], 1);
  assert_equal(src->array[1], 2);
  assert_equal(src->array[2], 3);
  assert_equal(src->array[3], 4);
  free(src);
}

void test_for_positive_nums(void){
  it("* should give product of positive numbers");
  int list[4] = {1,2,3,4}; 
  Array_ptr src = get_array(list, 4);
  assert_equal(reduce(src, 1, multiply), 24);
  free(src);
}

void test_for_negative_nums(void){
  it("* should give product of negative numbers");
  int list[5] = {-1,-2,-3,-4,-5}; 
  Array_ptr src = get_array(list, 5);
  assert_equal(reduce(src, 1, multiply), -120);
  free(src);
}

void test_for_zero_as_num_value(void){
  it("* should give zero when any number is zero");
  int list[4] = {-1, 0, -3, -4}; 
  Array_ptr src = get_array(list, 4);
  assert_equal(reduce(src, 1, multiply), 0);
  free(src);
}

void test_for_empty_array(void){
  it("* should give initial value for empty array");
  int list[] = {};
  Array_ptr src = get_array(list, 0);
  assert_equal(reduce(src, 1, multiply), 1);
  free(src);
};

void test_reduce(){
  describe("# REDUCE");
  test_for_positive_nums();
  test_for_negative_nums();
  test_for_zero_as_num_value();
  test_for_empty_array();
};

void test_for_increment_values(){
  it("* should increment each element by 1");
  int list[4] = {1,2,3,4}; 
  Array_ptr src = get_array(list , 4);
  Array_ptr mapped_src = map(src, increment);
  assert_equal(mapped_src->length, src->length);
  assert_equal(mapped_src->array[0], 2);
  assert_equal(mapped_src->array[1], 3);
  assert_equal(mapped_src->array[2], 4);
  assert_equal(mapped_src->array[3], 5);
  free(src);
  free(mapped_src);
}

void test_for_square_values(){
  it("* should give square of each element");
  int list[4] = {1,2,3,4}; 
  Array_ptr src = get_array(list , 4);
  Array_ptr mapped_src = map(src, square);
  assert_equal(mapped_src->length, src->length);
  assert_equal(mapped_src->array[0], 1);
  assert_equal(mapped_src->array[1], 4);
  assert_equal(mapped_src->array[2], 9);
  assert_equal(mapped_src->array[3], 16);
  free(src);
  free(mapped_src);
}

void test_map(){
  describe("# MAP");
  test_for_increment_values();
  test_for_square_values();
};

void test_for_is_odd(void){
  it("* should filter odd numbers");
  int list[4] = {1,2,3,4}; 
  Array_ptr src = get_array(list , 4);
  Array_ptr filtered_src = filter(src, is_odd);
  assert_equal(filtered_src->length, 2);
  assert_equal(filtered_src->array[0], 1);
  assert_equal(filtered_src->array[1], 3);
  free(src);
  free(filtered_src);
}

void test_for_is_even(void){
  it("* should filter even numbers");
  int list[4] = {1,2,3,4}; 
  Array_ptr src = get_array(list , 4);
  Array_ptr filtered_src = filter(src, is_even);
  assert_equal(filtered_src->length, 2);
  assert_equal(filtered_src->array[0], 2);
  assert_equal(filtered_src->array[1], 4);
  free(src);
  free(filtered_src);
}

void test_for_no_true(void){
  it("* should give empty array when no value is true");
  int list[4] = {1,7,3,5}; 
  Array_ptr src = get_array(list , 4);
  Array_ptr filtered_src = filter(src, is_even);
  assert_equal(filtered_src->length, 0);
  free(src);
  free(filtered_src);
}

void test_filter(){
  describe("# FILTER");
  test_for_is_odd();
  test_for_is_even();
  test_for_no_true();
};