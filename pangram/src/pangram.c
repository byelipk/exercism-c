#include "pangram.h"

int is_pangram(const char *sentence)
{
  bstring b_sentence = bfromcstr(sentence);

  int result = 1;
  int letters[ALPHABET_LENGTH] = {0};

  // Filter
  for (int i = 0; i < blength(b_sentence); i++) {
    char c = bchar(b_sentence, i);

    if (isascii(c)) {
      // If we subtract the decimal value of the char from the lower bound
      // we'll get the index position.
      int index = tolower((unsigned char) c) - ASCII_LOWER_BOUND;

      // Check off the presence of the char.
      letters[index] = 1;
    }
  }

  // Check for absence of any letter
  for (int i = 0; i < ALPHABET_LENGTH; i++) {
    if (letters[i] != 1) { result = 0; break; }
  }

  // Cleanup
  bdestroy(b_sentence);

  return result;
}
