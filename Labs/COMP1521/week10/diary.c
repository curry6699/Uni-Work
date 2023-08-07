#include <sys/types.h>

#include <sys/stat.h>
#include <sys/wait.h>

#include <assert.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
            return 0;
        }
    
    char *path_environment = getenv("HOME");
    
    int path_length = (strlen(path_environment) + strlen("/.diary") + 1);
    char str[path_length];

    snprintf(str, sizeof(str), "%s/.diary", path_environment);

    FILE *stream = fopen(str, "a");
    int i = 1;
    while (argv[i] != NULL) {
        fprintf(stream, "%s ", argv[i]);
        i++;
    }
    fprintf(stream, "\n");
    fclose(stream);
    return 0;
}