#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
      
    FILE *stream = fopen(argv[1], "r");
        
    if (stream == NULL) {
            return 1;
    }
    
    int i = 0;
    while (1) {
        // Taking inputs of characters
        int c = fgetc(stream);
 
        // See if its the end of the file and break
        if (feof(stream))
            break;

        if (isprint(c) == 0) {
            printf("byte %4d: %3d 0x%02x\n", i, c, c);
        } else {
        printf("byte %4d: %3d 0x%02x '%c'\n", i, c, c, c);
        }
        i++;
    } 
    // Close file once finished
    fclose(stream);
    return(0);
}