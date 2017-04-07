#ifndef _sieve
#define _sieve
// Implements the sieve of Eratosthenes
// INPUT: An integer n >= 2
// OUTPUT: Array L of all prime numbers less than or equal to n
//
// for p <- 2 to n do A[p] <- p
// for p <- 2 to floor(sqrt(n)) do
//   if A[p] != 0         // p hasn't been eliminated on previous passes
//     j <- p * p
//     while j <= n do
//       A[j] <- 0        // mark element as eliminated
//       j <- j + p
//
// Copy the remaining elements of A to array L of the primes
// i <- 0
// for p <- 2 to n do
//   if A[p] != 0
//     L[i] <- A[p]
//     i <- i + 1
//
// return L
int * sieve(int n);

#endif
