#include <stdio.h>
#include <stdlib.h>

#define SERIES_MAX 46

int recurse(int value, int already_computed[], int max);

int main(void) {
    int already_computed[SERIES_MAX + 1] = { 0, 1 };
    int value;
    while (scanf("%d", &value) == 1) {
        int final = recurse(value, already_computed, SERIES_MAX + 1);
        printf("%d\n", final);
    }
	
    return EXIT_SUCCESS;
}

int recurse(int value, int already_computed[], int max) {
    if (value == 0) return EXIT_SUCCESS;
    else if (already_computed[value] != 0) return already_computed[value];

    int final = recurse((value - 1), already_computed, max) + recurse((value - 2), already_computed, max);
    already_computed[value] = final;
    return final;
}