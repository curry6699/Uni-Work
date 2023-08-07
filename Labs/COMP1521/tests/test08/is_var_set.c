#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char *argv[]) {
        if (argc < 2) {
                printf("0\n");
        }

        char *path = getenv(argv[1]);

        if (path == NULL || strlen(path) == 0) {
                printf("0\n");
        }

        else {
                printf("1\n");
        }

        return 0;
}