#include <stdio.h>

int main(void){

    int range;
    int counter=1;
    int sum=0;
    
    printf("Enter number:");
    scanf("%d", &range);
    printf("The factors of %d are:\n", range);
    
    while (range >= counter){
        if (range % counter == 0){
            printf("%d\n", counter);
            sum += counter;
        }
        counter = counter + 1;
    }
    
    printf("Sum of factors = %d\n", sum );
    
    if (sum / 2 == range) {
    printf("%d is a perfect number\n", range);
    }
    else {
    printf ("%d is not a perfect number \n", range);
    }
    
    
return 0;
}
