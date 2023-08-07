// COMP1521 21T2 ... final exam, question 0

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int
count_leading_zeroes (uint32_t x)
{
	int i = 31;
	int leading = 0;
	while (i >= 0) {
		if ((x >> i) == 0) {
			leading++;
		}
		else {
			break;
		}
		i--;
	}
	return leading;
}

