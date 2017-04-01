#include "bob.h"

#include <stdio.h>

static inline int check_alpha(bstring sequence)
{
  for (int i = 0; i < blength(sequence); i++) {
    int b_char   = bchar(sequence, i);
    int is_upper = (b_char >= 65 && b_char <= 90);  // Uppercase
    int is_lower = (b_char >= 97 && b_char <= 122); // Lowercase

    if (is_lower || is_upper) { return 1; }
  }

  return 0;
}

char *hey_bob(char *message)
{
  bstring b_msg   = bfromcstr(message);
  bstring b_upper = bstrcpy(b_msg); btoupper(b_upper);
  bstring b_lower = bstrcpy(b_msg); btolower(b_lower);
  bstring b_reply = bfromcstr("");

  // Trim off whitespace
  btrimws(b_msg);

  // Some useful variables
  int msg_length                         = blength(b_msg);
  int last_char_is_question_mark         = bchar(b_msg, msg_length - 1) == '?';
  int no_diff_between_upper_and_original = biseq(b_msg, b_upper) == 1;
  int has_alphanumeric                   = check_alpha(b_msg);

  // Respond...
  if (no_diff_between_upper_and_original && has_alphanumeric) {
    bassigncstr(b_reply, "Whoa, chill out!");
  }

  else if (last_char_is_question_mark) {
    bassigncstr(b_reply, "Sure.");
  }

  else if (msg_length == 0) {
    bassigncstr(b_reply, "Fine. Be that way!");
  }

  else {
    bassigncstr(b_reply, "Whatever.");
  }


  // Cleanup
  bdestroy(b_msg);
  bdestroy(b_upper);
  bdestroy(b_lower);

  // This code has a memory leak because we cannot deallocate b_reply
  return bdata(b_reply);
}
