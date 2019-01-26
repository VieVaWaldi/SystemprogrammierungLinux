#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int doStuff(const char*filepath, const struct stat *fstat, int flags) {
    printf("%s\n", filepath);
}

int main(int argc, char **argv) {

    if(argc < 2) {
        printf("gimme a file");
        exit(0);
    }

    ftw(argv[1], doStuff, 100);

    return EXIT_SUCCESS;
}
