#include <stdio.h>
#include <ctype.h>

int swap_case(int character);

int main(void) {
    int character;
    character = getchar();
    while(character != EOF){
    
        int other_case = swap_case(character);
        putchar(other_case);
        character = getchar();
    }        
    return 0;
}

int swap_case(int character) {
    if(character >= 'A' && character <= 'Z') {
        int offset = character - 'A';
        return offset + 'a';    
    
    }
    else {
        return character;
    } 
}
