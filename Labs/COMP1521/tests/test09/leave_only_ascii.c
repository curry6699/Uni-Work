#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

        FILE *stream = fopen(argv[1], "r");
        FILE *copy_one = fopen("copy_one", "w+");

        while (1) {
                // Taking input
                int c = fgetc(stream);
        
                // see if at end
                if (feof(stream))
                break;

                // see if 0 
                if (isascii(c) != 0) {
                fprintf(copy_one, "%c", c);
                } 
        
        
        }  


        fclose(stream);
        
        FILE *input_stream = fopen(argv[1], "w");
        fseek(copy_one, 0, SEEK_SET);
        // close files and compare ^^

        while (1) {
                // Taking input 
                int c = fgetc(copy_one);
        
                // see if end of file
                if (feof(copy_one))
                break;
                
                // Save the file
                fprintf(input_stream, "%c", c);
        }  

    // Close files
    fclose(input_stream);
    fclose(copy_one);
    return 0;

}