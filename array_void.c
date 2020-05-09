#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

Object copy_int(Object numbers, int index){
  int_ptr element = malloc(sizeof(int));
  *element = ((int_ptr)numbers)[index];
  return element;
}

Object copy_char(Object letters, int index){
  char_ptr element = malloc(sizeof(char));
  *element = ((char_ptr)letters)[index];
  return element;
}

Object_ptr create_array_void(Object list, int length, Copier_void copier){
  Object_ptr array = malloc(sizeof(Object) * length);
  for (int index = 0; index < length; index++)
  {
    array[index] = (*copier)(list, index);
  }
  return array;
};

ArrayVoid_ptr get_array_void(Object_ptr src, int length){
  ArrayVoid_ptr newArray = malloc(sizeof(ArrayVoid_ptr));
  newArray->length = length;
  newArray->array = src;
  return newArray;
};

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer){
  for (int index = 0; index < src->length; index++)
  {
    init = (*reducer)(init, src->array[index]);
  }
  return init;
};

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper){
  ArrayVoid_ptr mapped_src = get_array_void(src->array, src->length);
  for (int index = 0; index < src->length; index++)
  {
    mapped_src->array[index] = (*mapper)(src->array[index]);
  }
  return mapped_src;
};