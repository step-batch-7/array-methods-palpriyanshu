#ifndef __TEST_LIB_H
#define __TEST_LIB_H

typedef char *String;
typedef void *Void_ptr;

void assert_int_equal(int actual, int expected);
void it(String text);
void describe(String text);

#endif