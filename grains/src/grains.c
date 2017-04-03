#include "grains.h"

unsigned long square(int n)
{
  if (n < SQUARE_MIN || n > SQUARE_MAX) { return 0; }

  return 1ul << (n - 1);
}

unsigned long total()
{
  return square(64);
}
