#include <stdio.h>

int main(void){
    
    int range;
    int counter=1;
    printf("Enter number: ");
    scanf("%d", &range);
 
    while (range > counter) { 
    
        if (counter % 3 == 0 || counter % 5 == 0){    
            printf("%d\n", counter);
        
        }    
        counter = counter + 1;     
    }
 
 }   
 
 
