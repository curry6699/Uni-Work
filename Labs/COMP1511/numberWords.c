#include <stdio.h>

int main(void){
printf("Please enter an integer:");

int number;

scanf("%d", &number);

if (number ==  1){
printf("You entered one.\n");
}
else if (number ==  2){
printf("You entered two.\n");
}
else if (number ==  3){
printf("You entered three.\n");
}
else if (number == 4){
printf("You entered four.\n");
}
else if(number ==  5){
printf("You entered five.\n");
}
else if (number>5) {
printf("You entered a number greater than five.\n");
}

else {
printf("You entered a number less than one.\n");
}


return 0;
}
