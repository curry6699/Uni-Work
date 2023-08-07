#include <stdio.h>
#include <stdlib.h>

void recurse(int num);

int main(int argc, char **argv)
{
	(void) argc, (void) argv; // keep the compiler quiet, should be removed
	int num = atoi(argv[1]);
	printf("%d \n", num);
	
    if (num == 1) {
        return 0;
    } else {
        recurse(num);
    }	
	return EXIT_SUCCESS;
}

void recurse(int num) {
    if (num % 2 == 0 && num != 1) {
        num = num / 2;
        printf("%d \n", num);
        recurse(num);   
    }
    else if (num % 2 != 0 && num != 1) {
        num = num * 3 + 1;
        printf("%d \n", num);
        recurse(num);   
    }

}
