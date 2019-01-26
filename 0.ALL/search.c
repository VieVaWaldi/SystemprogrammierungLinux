#include <unistd.h>
#include <ftw.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *search;

int traverse(const char *pfad, const struct stat *fstat, int typeflags) {

    printf("%s\n", pfad);

    char *file = strrchr(pfad, '/')+1;

    if( strcmp(search, file) ==  0) {
        printf("file is at %s\n", pfad);
    }

    return 0;
}

int main(int argc, char **argv) {

    char *dir = "~";

    if(argc < 3) {
        printf("gimme dir and file");
        exit(0);
    }

    dir = argv[1]; 
    search = argv[2];

    printf("PWD: %s\n", getcwd(NULL, 0));

    if(ftw(dir, &traverse, 10) == -1) printf("Error!");

    return EXIT_SUCCESS;
}
