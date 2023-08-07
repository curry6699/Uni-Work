#include <stdio.h>
#include <math.h>


int main(void){
    int instruction;
    int number;
    int power_number;
    int answer;
    
    printf("Enter instruction: ");   
    scanf("%d %d %d", &instruction, &number, &power_number);
    
        if (instruction == 1) {      
        answer = (number * number);
        }
        else {
        answer = pow(number, power_number);
        }
        
     printf("%d", answer);
    
/*    
    while(scanf("%d %d %d", &instruction, &number, &power_number) == 1 ||scanf("%d %d %d",      &instruction, &number, &power_number) == 3){
    printf("Enter instruction: ");
    scanf("%d %d %d", &instruction, &number, &power_number);
    
    if (instruction == 1) {
        answer = (number * number);
    }
    else {
        answer = pow(number, power_number);
    }
    printf("%d", answer);
    }
}
*/
}
