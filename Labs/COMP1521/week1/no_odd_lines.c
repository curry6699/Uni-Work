#include <stdio.h>
#include <string.h>

int main(void) {
	char input[1024];
	    while (fgets(input,1024, stdin) != NULL) {	    

	    if (strlen(input) % 2 == 0) {

	        fputs(input, stdout);
	    }
	}
	return 0;
}
