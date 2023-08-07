// COMP1521 21T2 ... final exam, question 5

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void
print_utf8_count (FILE *file)
{
	unsigned long amount_1_byte = 0;
	unsigned long amount_2_byte = 0;
	unsigned long amount_3_byte = 0;
	unsigned long amount_4_byte = 0;

	// TODO

	int input;
	while((input = fgetc(file)) != EOF) {
		if ((input & 0xFFFFFFFF) == 0xFFFFFFFF) {
			amount_4_byte++;	
		}
		else if ((input & 0xFFFFFF) == 0xFFFFFF) {
			amount_3_byte++;
		}
		else if((input & 0xFFFF) == 0xFFFF) {
			amount_2_byte++;
		}
		else {
			amount_1_byte++;
		}
		
	}
     	
	

	printf("1-byte UTF-8 characters: %lu\n", amount_1_byte);
	printf("2-byte UTF-8 characters: %lu\n", amount_2_byte);
	printf("3-byte UTF-8 characters: %lu\n", amount_3_byte);
	printf("4-byte UTF-8 characters: %lu\n", amount_4_byte);
}
