#include "nth_prime.h"
#include <math.h>

// See: http://stackoverflow.com/questions/9625663/calculating-and-printing-the-nth-prime-number

// A prime number is divisible by itself and 1. The first prime
// number is 2. A straightforward way to find the nth prime is
// to start from 2 and count all the prime numbers until you
// reach n.
int nth(int n)
{
  if (n == 0) { return 0; }

  int candidate = 2; // the integer we're testing to see if it is prime
  int count     = 0; // the number of prime integers we've discovered

  for (count = 0, candidate = 2; count < n; candidate++) {
    if (trial_division_fast(candidate)) { count++; }
  }

  return candidate - 1;
}

int trial_division_slow(int candidate)
{
  for (int i = 2; i < candidate; i++) {
    // if the candidate is divisible by another number, it is not prime
    if (candidate % i == 0) { return 0; }
  }
  return 1;
}

int trial_division_fast(int candidate)
{
  if (candidate % 2 == 0) { return candidate == 2; }
  if (candidate % 3 == 0) { return candidate == 3; }

  int step = 4;
  int m = (int)sqrt(candidate) + 1;

  for (int i = 5; i < m; step = 6 - step, i += step) {
    if (candidate % i == 0) { return 0; }
  }

  return 1;
}
