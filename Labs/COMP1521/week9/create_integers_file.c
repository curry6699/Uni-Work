#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Open file
    FILE *stream = fopen(argv[1], "w+");
    if (stream == NULL) {
        perror("hello.txt");
        return 1;
    }  

    // Get values for arguments
    int i = atoi(argv[2]);
    int j = atoi(argv[3]);
    while (i <= j) {
        // save to a new file
        fprintf(stream, "%d", i);
        fprintf(stream, "\n");
        i++;
    }
    
    // Finished, now close
    fclose(stream);
    return 0;    

}