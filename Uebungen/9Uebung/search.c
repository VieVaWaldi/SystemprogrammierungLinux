#include <unistd.h>
#include <ftw.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "search.h"

static char *search;

int traverse(const char *pfad, const struct stat *fstat, int typeflags) {

    char *file = strrchr(pfad, '/')+1;

    if( strcmp(search, file) ==  0) {
        printf("file is at %s\n", pfad);
        return(2);
    }

    return 0;
}

int searchFile(char *dir, char *file) {

    search = (char*) malloc(sizeof(file)+10);
    strcpy(search, file);

    int status = ftw(dir, &traverse, 10);
    
    if(status != 2) return EXIT_SUCCESS;
    else return EXIT_FAILURE;
}
