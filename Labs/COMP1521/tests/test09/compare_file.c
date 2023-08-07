#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

        FILE *stream = fopen(argv[1], "r");
        FILE *stream2 = fopen(argv[2], "r");

        int current_byte = 0;
        while (1) {

        // Taking input 
        int i = fgetc(stream);
        int j = fgetc(stream2);
 
        if (feof(stream) && feof(stream2)) {
                break;
        }
        
        // see if at and
        if (feof(stream)) {
                printf("EOF on %s\n", argv[1]);
                fclose(stream);
                fclose(stream2);
                return 0;
        }

        if (feof(stream2)) {
                printf("EOF on %s\n", argv[2]);
                fclose(stream);
                fclose(stream2);
                return 0;
        }

        if (j != i) {
                printf("Files differ at byte %d\n", current_byte);
                fclose(stream);
                fclose(stream2);
                return 0;

        }

        current_byte++;
    }  
        
        // Close files
        printf("Files are identical\n");
        fclose(stream);
        fclose(stream2);
        return 0;

}