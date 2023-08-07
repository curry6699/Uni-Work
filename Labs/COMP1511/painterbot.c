#include <stdio.h>
#define MAX_DIGITS 36

void print_array(int array[MAX_DIGITS]);
int main(void){
    int indices;
    int array[MAX_DIGITS]={0};
    
    
    while(scanf("%d", &indices) == 1){    
    array[indices]= 1;  
    
    }
    
    print_array(array);  


return 0;
}

void print_array(int array[MAX_DIGITS]){
    int i = 0;
    while(i < MAX_DIGITS) {
        printf("%d ", array[i]);
        
        i++;
    
    }
    printf("\n");
}
