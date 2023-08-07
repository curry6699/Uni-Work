#include <stdio.h>
int main(void){
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    int length = size;
    int height = size;
    int counter = 0;
   
    
    while (length >= counter){
        printf("*");
            while (length-1 >= counter){
            printf("_");           
            }
        printf("*");
    counter = counter + 1;
    }
}
