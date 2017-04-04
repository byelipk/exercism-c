#include "largest_series_product.h"

uint64_t largest_series_product(char *string, int series)
{
  uint64_t largest = 0; // We need the extra space to deal with large numbers

  bstring b_string = bfromcstr(string);
  int b_length     = blength(b_string);

  // Guard clauses
  if (b_length == 0 && series > b_length) { return -1; }
  if (series > b_length)                  { return -1; }
  if (b_length == 0 || series == 0)       { return 1;  }

  // Because in multiplication A * B = B * A and there is a specific
  // sliding window our algorithm has to search, we don't need the outer loop
  // to pass through each element in the sequence.
  int outer_loop_limit = (b_length - (series - 1));

  for (int i = 0; i < outer_loop_limit; i++) {

    uint64_t product = 0; // See above ^^

    for (int j = 0; j < series; j++) {

      // Find digit - returns ascii value between 48-57
      int digit = GET_DIGIT(b_string, i + j);

      // Quit if input is not 0-9
      CHECK_IS_DIGIT(digit);

      // Convert 48-57 to 0-9
      digit = TO_DIGIT(digit);

      // Process it
      HANDLE_DIGIT(digit, product);
    }

    // Update
    if (product > largest) { largest = product; }
  }

  // Cleanup
  bdestroy(b_string);

  return largest;
}
