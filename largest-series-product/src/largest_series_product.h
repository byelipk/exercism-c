#ifndef _largest
#define _largest

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "bstrlib.h"
#include "bstraux.h"
#include "dbg.h"

#define CHECK_IS_DIGIT(C) if (isdigit((C)) == 0) { return -1; }

#define TO_DIGIT(C) (C) - '0'

#define GET_DIGIT(A,B) bchar(A, B)

#define HANDLE_DIGIT(A, B) \
  if ((A) == 0)      { (B) = 0; break; } \
  else if ((B) != 0) { (B) *= (A); } \
  else               { (B) = (A); }


uint64_t largest_series_product(char *string, int series);

#endif
