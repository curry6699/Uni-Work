#include <stdio.h>

int main(void){

int students;
int tutors;
printf("Please enter the number of students and tutors:");

scanf("%d", &students);
scanf("%d", &tutors);

printf("%d" " + " "%d", students, tutors);

int result;
result = (students + tutors);
printf(" = %d\n", result);



return 0;

}
