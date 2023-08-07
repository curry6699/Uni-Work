// Prints the first n digits of pi, where n is specified 
// by the user

#include <stdio.h>

#define MAX_DIGITS 10

//proto type function
void print_array(int digits, int pi[MAX_DIGITS]);

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int digits;
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &digits);


    print_array(digits, pi);   
    
       
    return 0;
}

//defining function
void print_array(int digits, int pi[MAX_DIGITS]){
    int i = 0;
    while (digits > i) {
        printf("%d", pi[i]);
        if(digits > 1 && i == 0) {
            printf(".");
        }   
        i++;
    } 
    printf("\n");
}
