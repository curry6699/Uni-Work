#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv) {
	(void) argc, (void) argv; // keep the compiler quiet, should be removed
	int array[argc];
	int i = 1;
	while (i < argc) {
	    array[i-1] = atoi(argv[i]);    
	    i++;
	}	
	
	// FINDING min value
    i = 1;
    int min = array[i-1];    
    while (i < argc - 1) {
        if (min > array[i]) {
            min = array[i];
        }    
        i++;
    }
	printf("MIN:  %d \n", min);
	
	// FINDING max value
	i = 1;
    int max = array[i-1];    
    while (i < argc - 1) {
        if (max < array[i]) {
            max = array[i];
        }    
        i++;
    }
	printf("MAX:  %d \n", max);
	
	// FINDING sum
	i = 1;
	int sum = array[i-1];
	while (i < argc - 1) {
	    sum += array[i];	
	    i++;
	}
	printf("SUM:  %d \n", sum);
	
	// FINDING prod
	i = 1;
	int prod = array[i-1];
	while (i < argc - 1) {
	    prod = prod * array[i];	
	    i++;
	}
	printf("PROD: %d \n", prod);	
	
	// FINDING mean
    int mean = sum;
    mean = sum / i;
	printf("MEAN: %d \n", mean);
	return 0;
}


