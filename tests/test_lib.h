#ifndef __TEST_LIB_H
#define __TEST_LIB_H

typedef char *String;
typedef void *Void_ptr;
typedef int *int_ptr;

void assert_void_int_equal(Void_ptr actual, Void_ptr expected);
void assert_void_char_equal(Void_ptr actual, Void_ptr expected);
void assert_equal(int actual, int expected);
void it(String text);
void describe(String text);

#endif