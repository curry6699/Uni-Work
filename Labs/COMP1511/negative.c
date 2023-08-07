#include <stdio.h>
#define MIN_VALUE 0



int main(void){

int input;
scanf("%d\n",&input) ;

if (input>MIN_VALUE){
printf("You have entered a positive number.\n") ;
}

else if (input<MIN_VALUE){
printf("Don't be so negative!\n");
}
else{
printf("You have entered zero.\n");
}
return 0;
}
