#include <stdio.h>
#include "hamming.h"
#include "bstrlib.h"
#include "bstraux.h"
#include "dbg.h"

static inline int min(int a, int b)
{
	if (a <= b)
		{ return a; }
	else
		{ return b; }
}

int compute(const char *seq_a, const char *seq_b)
{
	// Better string
	bstring b_seq_a = bfromcstr(seq_a);
	bstring b_seq_b = bfromcstr(seq_b);

	// Find the min length
	int len_a = blength(b_seq_a);
	int len_b = blength(b_seq_b);
	int min_len = min(len_a, len_b);

	// Initialize the hamming distance
	int diff = 0;

	// TODO
	// Use a bstring method to search the seqs.
	for (int i = 0; i < min_len; i++) {
		if (b_seq_a->data[i] != b_seq_b->data[i]) {
			diff += 1;
		}
	}

	// Cleanup
	bdestroy(b_seq_a);
	bdestroy(b_seq_b);

	return diff;
}
