#ifndef _pangram
#define _pangram

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bstrlib.h"
#include "bstraux.h"
#include "dbg.h"

#define ASCII_LOWER_BOUND 97
#define ASCII_UPPER_BOUND 122
#define ALPHABET_LENGTH ASCII_UPPER_BOUND - ASCII_LOWER_BOUND

int is_pangram(const char *sentence);

#endif
