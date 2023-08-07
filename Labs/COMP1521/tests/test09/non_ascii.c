#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

        FILE *stream = fopen(argv[1], "r");

        int j = 0;
        
        if (stream == NULL) {return 1;}
        
        while (1) {
                // Taking input single character at a time
                int i = fgetc(stream);
        
                // see if end of file
                if (feof(stream))
                break;

                if (isascii(i) == 0) {
                printf("%s: byte %d is non-ASCII\n", argv[1], j);
                fclose(stream);
                return 0;
                } 
                j++;
        }  
        
        printf("%s is all ASCII\n", argv[1]);
        fclose(stream);
        return 0;

}