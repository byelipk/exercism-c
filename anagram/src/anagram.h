#ifndef _ANAGRAM_H
#define _ANAGRAM_H

#include <stdlib.h>
#include <string.h>
#include "dbg.h"

// See: http://bstring.sourceforge.net
#include "bstrlib.h"
#include "bstraux.h"

#define MAX_STR_LEN 20

// A Vector is composed of:
//   => a 32-bit integer value
//   => an array of char pointers, where the length of the value
//      being pointed at is MAX_STR_LEN
struct Vector {
   char (*vec)[MAX_STR_LEN];
   int size;
};

struct Vector anagrams_for(char *input, struct Vector vector);


// ALGORITHM  BubbleSort(A[0..n - 1])
//
// Desc:   Sorts a given array by bubble sort,
//         where n is the number of elements in the array.
//
// Input:  A zero-index array of n orderable elements.
//
// Output: Array A[0..n - 1] sorted in ascending order.
//
// def BubbleSort() do
//   for i <- 0 to n - 2 do
//     for j <- 0 to n - 2 - i do
//       if A[j + 1] < A[j]
//         swap A[j] and A[j + 1]
// end
int BubbleSort(char *array, int size);

#endif
