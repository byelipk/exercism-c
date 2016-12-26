#include "anagram.h"


struct Vector anagrams_for(char *input, struct Vector vector)
{
  printf("ANAGRAM: %s\n", input);
  printf("VECTOR SIZE: %d\n", vector.size);
  printf("INPUTS IN VECTOR:\n");
  for (int i = 0; i < vector.size; i++) {
    printf("\t%s\n", vector.vec[i]);
  }
  printf("\n");


  bstring str = bfromcstr(input);        // bstring's are safer than c-strings
  BubbleSort(bdata(str), blength(str));  // sort the underlying c-string

  printf("SORTED ANAGRAM: %s -> %s\n\n", input, str->data);

  // NOTE: http://stackoverflow.com/questions/2614249/dynamic-memory-for-2d-char-array
  char **ptr_array = (char**) calloc(vector.size, sizeof(char *));
  for (int i = 0; i < vector.size; i++) {
    ptr_array[i] = (char *) calloc(MAX_STR_LEN, sizeof(char));
  }

  // for (int i = 0; i < vector.size; i++) {
  //   strcpy(ptr_array[i], vector.vec[i]);
  //   printf("%p -> %s\n", (void *)ptr_array[i], ptr_array[i]);
  // }

  printf("%lu\n", sizeof(char *));

  int matches = 0;
  for (int i = 0; i < vector.size; i++) {
    bstring bstr = bfromcstr(vector.vec[i]);                   // convert
    int length   = blength(bstr);
    BubbleSort(bdata(bstr), length);                           // sort
    if (bstrcmp(str, bstr) == 0) {                             // compare
      printf("MATCH: %d\n", matches);
      printf("LOOP: %d\n", i);
      printf("LENGTH: %d\n", i);
      printf("STRING: %p -> %s\n", (void *)vector.vec[i], vector.vec[i]);
      printf("DEST:   %p\n", (void *)ptr_array[matches]);
      printf("\n");

      strcpy(ptr_array[matches], vector.vec[i]);
      matches++;                                               // increment
    }
    bdestroy(bstr);                                            // cleanup
  }
  bdestroy(str);      // cleanup

  // CHECK
  for (int i = 0; i < matches; i++) {
    printf("CHECK %d: %p -> %s\n", i, (void *)ptr_array[i], ptr_array[i]);
  }
  printf("\n\n");

  struct Vector vout = { ptr_array, matches };
  //
  // // CHECK
  // for (int i = 0; i < matches; i++) {
  //   printf("CHECK %d B: %s\n", i, vout.vec[i]);
  // }

  // // Cleanup
  // for (int i = 0; i < vector.size; i++) {
  //   free(ptr_array[i]);
  // }
  // free(ptr_array);

  return vout;
}


int BubbleSort(char *array, int size)
{
  int i = 0;
  int j = 0;

  if (size <= 1) { return 0; }              // Already sorted.

  for (i = 0; i < (size - 1); i++) {        // outer loop
    for (j = 0; j < (size - 1 - i); j++) {  // inner loop
      if (array[j + 1] < array[j]) {        // swap
        char temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }

  return 0;
}
