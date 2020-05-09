#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr get_array_void(Object_ptr list, int length){
  ArrayVoid_ptr src = malloc(sizeof(ArrayVoid_ptr));
  src->length = length;
  src->array = malloc(sizeof(*(*list)) * length);
  for(int index = 0; index < length; index++){
    src->array[index] = list+index;
  }
  return src;
};


