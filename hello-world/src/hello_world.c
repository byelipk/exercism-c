#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hello(char *buffer, int buffer_length, const char * string)
{
  size_t string_len = strlen(string);

  if (string_len && string_len <= buffer_length) {
    strncpy(buffer, "Hello, ", buffer_length);
    strncat(buffer, string, buffer_length);
    strncat(buffer, "!", buffer_length);
  } else {
    strncpy(buffer, "Hello, World!", buffer_length);
  }
}
