#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int add(int num1, int num2);
int increment(int num);
Bool is_even(int num);

int add(int num1, int num2){
  return num1 + num2;
};

int increment(int num){
  return num + 1;
};

Bool is_even(int num){
  return num % 2 == 0;
};

int main() {
  int list[] = {1,2,3,4};
  int length = sizeof(list) / sizeof(list[0]);
  Array_ptr numbers = get_array(list, length);
  int sum = reduce(numbers, 0, add);
  Array_ptr mapped_numbers = map(numbers, increment);
  Array_ptr filtered_numbers = filter(numbers, is_even);
  display_array(mapped_numbers);
  display_array(filtered_numbers);
  printf("sum is %d\n",sum);
  free(numbers);
  free(mapped_numbers);
  free(filtered_numbers);
  return 0;
}