#include <stdio.h>


int main(void){
printf("Enter year:");

int year;

scanf("%d",&year);

if (year==2100){
printf("2100 is not a leap year.\n");
}

else if (year==1900){
printf("1900 is not a leap year.\n");
}

else if (year==1800){
printf("1800 is not a leap year.\n");
}

else if (year==1000){
printf("1000 is not a leap year.\n");
}

else {
int xar;
xar=(year % 100);

if (xar==0){
int xo;
xo=(year % 4);

if (xo == 0){
printf("%d is a leap year.\n", year);
}
else {
printf("%d is not a leap year.\n",year);
}

return 1;
}

else {
int var;
var=(year % 4);

if (var==0){
printf("%d is a leap year.\n",year);
}

else {
printf("%d is not a leap year.\n", year);
}}


return 0;
}}
