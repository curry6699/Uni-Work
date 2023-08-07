// COMP1521 21T2 ... final exam, question 3

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void
cp (char *path_from, char *path_to)
{
	FILE *input = fopen(path_from, "r");
	FILE *output = fopen(path_to, "w+");

	while(1) {
		int c = fgetc(input);

		if (c == EOF) {
			break;
		}

		fputc(c, output);
	}
}

