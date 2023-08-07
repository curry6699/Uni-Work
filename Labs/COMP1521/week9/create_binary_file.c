#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Load file
    FILE *stream = fopen(argv[1], "w+");

    // See if it exists 
    if (stream == NULL) {
        return 1;
    }

    // Read into file
    for (int arg = 2; arg < argc; arg++) {
            fputc(atoi(argv[arg]), stream);
    }

    return 0;
}
