#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

static const char *RANDOMFILE="/dev/random";

void *alloc(int size) {
    char *ptr[size];
    return ptr;
}

int main(int argc, char **argv) {

    int max = 6;
    if(argc == 3) max = atoi(argv[2]);

    int fd;
    
    if((fd = open(RANDOMFILE, O_RDONLY)) < 0) {
        printf("error open");
        exit(0);
    }

    printf("max = %d\n", max);

    char *buf = (char*) alloc(max); // = (char *) malloc(sizeof(char) * max);
    int rng;
    size_t result;
   
    printf("size of %ld\n", sizeof(buf));

    if((result = read(fd, &rng, 1)) < 0 ) {
        printf("error read");
        exit(0);
    }

    printf("Random = %d\n", rng);

    return EXIT_SUCCESS;
}
