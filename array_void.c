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
  ArrayVoid_ptr newArray = malloc(sizeof(ArrayVoid));
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

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate){
  Object temp_array[src->length];
  int count = 0;
  for (int index = 0; index < src->length; index++)
  {
    Bool is_true =  (*predicate)(src->array[index]);
    if(is_true){
      temp_array[count] = src->array[index];
      count++;
    }
  } 
  ArrayVoid_ptr filtered_src = get_array_void(temp_array, count);
  return filtered_src;
};

void display_int_void(Object element){
  printf("%d ", *(int_ptr)element);
}

void display_char_void(Object element){
  printf("%c ", *(char_ptr)element);
}

void display_array_void(ArrayVoid_ptr src, Displayer displayer){
  for (int index = 0; index < src->length; index++)
  {
    (*displayer)(src->array[index]);
  }
  printf("\n");
};

void clear_array_void(ArrayVoid_ptr src){
  for (int index = 0; index < src->length; index++)
  {
    free(src->array[index]);
  }
  free(src->array);
  free(src);
};