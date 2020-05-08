#ifndef __ARRAY_H
#define __ARRAY_H

typedef void *Void_ptr;
typedef int *int_ptr;

typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int_ptr array;
  int length;
} Array;

typedef Array *Array_ptr;

Array_ptr get_array(int list[], int length);

Array_ptr  map(Array_ptr src, Mapper mapper);
Array_ptr filter(Array_ptr src, Predicate predicate);
int reduce(Array_ptr src, int init, Reducer reducer);

void display_array(Array_ptr src);

#endif
