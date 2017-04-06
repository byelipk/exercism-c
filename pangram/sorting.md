# Sorting a bstring

```C
static inline int compare(const void *a, const void *b)
{
  char char_a = *(char*)a;
  char char_b = *(char*)b;

  if (char_a != char_b) { return char_a - char_b; }
  else                  { return 0; }
}

// Sort
qsort(bdata(b_sentence), blength(b_sentence), sizeof(char), compare);
```
