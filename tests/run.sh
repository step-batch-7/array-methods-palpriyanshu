#! /bin/bash
executable=$1
rm -rf *.o
gcc -c *.c ../array.c ../array_void.c
gcc -o $1 *.o
./$1
rm -rf *.o test