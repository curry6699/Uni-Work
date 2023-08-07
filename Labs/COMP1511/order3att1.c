#include <stdio.h>

int main(void){
    int Int1;
    int Int2;
    int Int3;

    printf("Enter an integer:");
    scanf("%d", &Int1);
    printf("Enter an integer:");
    scanf("%d", &Int2);
    printf("Enter an integer:");
    scanf("%d", &Int3);
    
    int highest_number=0;
    int middle_number=0;
    int lowest_number=0;
    
    if (Int1 > Int2 && Int1 > Int3){
    Int1=highest_number ;
    }
    if (Int2 > Int1 && Int2 > Int3){
    Int2=highest_number ;
    }
    if (Int3 > Int2 && Int3 > Int1){
    Int3=highest_number ;
    }
    
    if (Int1 < Int2 && Int1 < Int3){
    Int1=lowest_number ;
    }
    if (Int2 < Int1 && Int2 < Int3){
    Int2=lowest_number ;
    }
    if (Int3 < Int2 && Int3 < Int1){
    Int3=lowest_number ;
    }
    
    if (Int1 == highest_number && Int2 == lowest_number){
    Int3=middle_number ;
    }
    if (Int1 == highest_number && Int3 == lowest_number){
    Int2=middle_number ;
    }
    if (Int2 == highest_number && Int1 == lowest_number){
    Int3=middle_number ;
    }
    if (Int2 == highest_number && Int3 == lowest_number){
    Int1=middle_number ;
    }
    if (Int3 == highest_number && Int1 == lowest_number){
    Int2=middle_number ;
    }
    if (Int3 == highest_number && Int2 == lowest_number){
    Int2=middle_number ;
    }
    
    printf("The integers in order are: %d %d %d \n", lowest_number, middle_number, highest_number);

}








