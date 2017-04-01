#include "raindrops.h"
#include "bstrlib.h"
#include "bstraux.h"

#include <stdio.h>

char *convert(char *buffer, int size, int number)
{
  // Get the compiler to be quiet
  if (size && buffer) {}

  bstring b_buffer = bfromcstr("");
  bstring b_pling  = bfromcstr("Pling");
  bstring b_plang  = bfromcstr("Plang");
  bstring b_plong  = bfromcstr("Plong");

  if (number % 3 == 0) { CHECK(bconcat(b_buffer, b_pling) == BSTR_OK); }
  if (number % 5 == 0) { CHECK(bconcat(b_buffer, b_plang) == BSTR_OK); }
  if (number % 7 == 0) { CHECK(bconcat(b_buffer, b_plong) == BSTR_OK); }

  if (blength(b_buffer) == 0) {
    CHECK(bformata(b_buffer, "%d", number) == BSTR_OK);
  }

  // NOTE
  // This code could be causing memory leaks!
  // We're not destroying the bstring, just returning the data.
  return bdata(b_buffer);

error:
  return buffer;
}
