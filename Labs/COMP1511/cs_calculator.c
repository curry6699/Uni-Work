#include <stdio.h>
#include <math.h>
#define MAX_DIGITS 3

int main(void){
/*
    int instruction;
    int number;
    int power;
    
 */ 
    int i = 0;
    int array[MAX_DIGITS]={0};
   
    printf("Enter Instruction: ");
    scanf("%d", &array[i]);
    
    i++;
    scanf("%d", &array[i]);
    
    i++;
    scanf("%d", &array[i]);
    
    i++;
    
    if (array[0] == 1) {
        int temp;    
        temp = array[1] * array[1];
        printf("%d", temp);
    
    }
    
    else {
        int temp;
        temp = pow(array[1], array[2]);
        printf("%d", temp);
    
    }
    
    
    
    
    
    
    
    
    
/*    
        printf("Enter Instruction: ");
        scanf("%d %d %d", &instruction, &number, &power);
        
        if (scanf("%d %d %d", &instruction, &number, &power) == 2){
        power = 1;
        
        }
        
        if (instruction == 1) {
            int temp;
       
            temp = number*number+power;
            printf("%d \n", temp);
        }

        else {
            int temp;
            temp = pow(number, power);
            printf("%d \n", temp);
        }
    
    
    
*/    
}
