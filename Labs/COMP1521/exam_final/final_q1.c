// COMP1521 21T2 ... final exam, question 1

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS 8

void
and (bool x[BITS], bool y[BITS], bool result[BITS])
{
	int i = 0;
	while (i < 8) {
		if (x[i] == 1 && y[i] == 1) {
			result[i] = 1;
		}
		else {
			result[i] = 0;
		}
		i++;
	}
}

void
or (bool x[BITS], bool y[BITS], bool result[BITS])
{
	int i = 0;
	while (i < 8) {
		if (x[i] == 1 && y[i] == 1) {
			result[i] = 1;
		}
		else if(x[i] == 1 && y[i] == 0) {
			result[i] = 1;
		}
		else if (y[i] == 1 && x[i] == 0) {
			result[i] = 1;
		}
		else {
			result[i] = 0;
		}
		i++;
	}
}

void
xor (bool x[BITS], bool y[BITS], bool result[BITS])
{
	int i = 0;
	while (i < 8) {
		if (x[i] != y[i]) {
			result[i] = 1;
		}
		else {
			result[i] = 0;
		}
		i++;

	}
}

void
not (bool x[BITS], bool result[BITS])
{
	int i = 0;
	while (i < 8) {
		if (x[i] == 1) {
			result[i] = 0;
		}
		else {
			result[i] = 1;
		}
		i++;
	}
}
