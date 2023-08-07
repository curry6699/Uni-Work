#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

void stat_file(char *path);
long int count(char *path);

int main(int argc, char *argv[]) {
    // Long long to ensure we dont overflow
    long long int i = 0;

    // Print file name and stats

    int argument = 1;
    while (argument < argc) {
        printf("%s", argv[argument]);
        stat_file(argv[argument]);
        
        i = i + count(argv[argument]);

        argument++;
    }
    
    printf("Total: %lld bytes\n", (long long)i);
    return 0;
}


void stat_file(char *path) {
    
    struct stat s;
    
    if (stat(path, &s) != 0) {
        perror(path);
        exit(1);
    }   
    printf(": %ld bytes\n", (long)s.st_size);
    
}

long int count(char *path) {

    struct stat s;

    if (stat(path, &s) != 0) {
        perror(path);
        exit(1);      
    }
    long int i = (long)s.st_size;
    return i;
        
}
