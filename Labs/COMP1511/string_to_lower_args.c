#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4096

int swap_case(int c);

int main(int argc, char *argv[]) {
    int c = 0;
    int ch = argv[1][c];
    while (ch >= 'a' && ch <= 'z') {     
        ch = argv[1][c];
        putchar(ch);
        int capital = swap_case(c);
        putchar(capital);
        c++;
    }
        

}

int swap_case(int c) {
    if(c >= 'a' && c <= 'z') {
        int offset = c - 'a';
        return offset + 'A';       
    } 
    return c;   
}
