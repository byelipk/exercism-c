#include "anagram.h"


struct Vector anagrams_for(char *input, struct Vector vector)
{

  // We declare an array of character pointers and assign it to a variable
  // named `output`. Since it's possible for all strings in the vector
  // to be an anagram, we make the size of the character array equal to
  // the number of strings in the vector using `vector.size`.
  //
  // We allocate memory for the vector using `calloc` so that we
  // contiguously allocating enough space for all potential anagrams.
  //
  // NOTE: We do not have to free this memory because it will be freed by the test case.
  char (*output)[MAX_STR_LEN] = calloc(vector.size, sizeof(char *));

  // This is the Vector struct we will return from the function. We initialize
  // it to the chunk of memory we allocated on the heap for the array of strings,
  // and set the size property to 0.
  //
  // This struct is stored on the stack, not in the heap so we don't need to
  // worry about freeing this memory.
  struct Vector output_vector = { output, 0 };

  for (int i = 0; i < vector.size; i++) {
    // prepare the input string
    bstring b_input = bfromcstr(input);
    bLowercase(b_input);

    // Prepare the comparison string
    bstring b_compare = bfromcstr(vector.vec[i]);
    bLowercase(b_compare);



    // We do not allow identical terms to be anagrams
    if (bstrcmp(b_input, b_compare) == 0) {
      continue;
    }

    // Sort both b-strings. This can be refactored to use a more
    // efficient sorting algorithm or to only sort the input string
    // once.
    BubbleSort(bdata(b_input), blength(b_input));
    BubbleSort(bdata(b_compare), blength(b_compare));

    // TODO: print out codepoints to show if bonus test `test_unicode_anagrams`
    //       uses an incorrect expected output.
    // printf("UNICODE for %s -> ", input);
    // for (int n = 0; n < blength(b_input); n++) {
    //   printf("%x ", bchar(b_input, n));
    // }
    // printf("\n");
    //
    // printf("UNICODE for %s -> ", vector.vec[i]);
    // for (int n = 0; n < blength(b_compare); n++) {
    //   printf("%x ", bchar(b_compare, n));
    // }
    // printf("\n");
    // printf("\n");

    if (bstrcmp(b_input, b_compare) == BSTR_OK) {
      char *dst = output_vector.vec[output_vector.size];
      char *src = vector.vec[i];

      strcpy(dst, src);
      output_vector.size++;
    }

    bdestroy(b_input);   // cleanup
    bdestroy(b_compare);
  }

  return output_vector;
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
