#include <stdio.h>

int main(int argc, char **argv) {
	(void) argc, (void) argv; // keep the compiler quiet, should be removed
	printf("Program name: %s \n", argv[0]);
	
	if (argc == 1) {
	    printf("There are no other arguments\n");
	    return 0;
	}
	printf("There are %d arguments:\n", argc-1);
	int i = 1;
	while (i < argc) {
	    printf("	Argument %d is \"%s\" \n", i, argv[i]);
	    i++;
	}
	return 0;
}
