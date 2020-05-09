#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H

#include "array.h"

typedef void *Object;
typedef char *char_ptr;
typedef Object *Object_ptr;

typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);

typedef struct
{
  Object_ptr array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;
typedef Void_ptr (*Copier_void)(Object , int);

Object_ptr create_array_void(Object list, int length, Copier_void copier);
ArrayVoid_ptr get_array_void(Object_ptr array, int length);
Void_ptr copy_int(Object numbers, int index);
Void_ptr copy_char(Object letters, int index);

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper);
ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer);

#endif
