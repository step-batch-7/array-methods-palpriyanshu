#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array_ptr get_array(int_ptr list, int length){
  Array_ptr src = malloc(sizeof(Array_ptr));
  src->length = length;
  src->array = malloc(sizeof(int) * length);
  for(int index = 0; index < length; index++){
    src->array[index] = list[index];
  }
  return src;
};

int reduce(Array_ptr src, int init, Reducer reducer){
  for (int index = 0; index < src->length; index++)
  {
    init = (*reducer)(init, src->array[index]);
  }
  return init;
};

Array_ptr map(Array_ptr src, Mapper mapper){
  Array_ptr mapped_src = get_array(src->array, src->length);
  for (int index = 0; index < src->length; index++)
  {
    mapped_src->array[index] = (*mapper)(src->array[index]);
  }
  return mapped_src;
};

Array_ptr filter(Array_ptr src, Predicate predicate){
  int temp_array[src->length];
  int count = 0;
  for (int index = 0; index < src->length; index++)
  {
    Bool is_true =  (*predicate)(src->array[index]);
    if(is_true){
      temp_array[count] = src->array[index];
      count++;
    }
  } 
  Array_ptr filtered_src = get_array(temp_array, count);
  return filtered_src;
}

void display_array(Array_ptr src){
  for (int index = 0; index < src->length; index++)
  {
    printf("%d ",src->array[index]);
  }
  printf("\n");
};