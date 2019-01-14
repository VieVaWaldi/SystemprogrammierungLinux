#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>

static struct option long_opts[] = {
    {"file", required_argument, NULL, 'f'}
};

int main(int argc, char **argv) {

    char *short_opt = "f:";
    char *file;
    int ch;

    if(argc < 2) {
        printf("./reverse -f file");
        exit(EXIT_FAILURE); 
    }

    if((ch = getopt_long(argc, argv, short_opt, long_opts, NULL)) != -1) {
        if(optarg != NULL) {
            file = optarg;
        }
    } 

    // Implementation
    // tempstring right length ?

    FILE *source = fopen(file, "r");
    int length;

    fseek(source, 0L, SEEK_END);
    length = ftell(source);
    fseek(source, 0L, SEEK_SET);

    char *bufferSource = (char *) malloc(length);
    char *bufferTarget = (char *) malloc(length);
    char tempStr[200];
    int idx = 0;

    // aaaN         4
    // aN           2
    // aaaaaaaN     8
    //
    //

    while(fgets(tempStr, 100, source) != NULL) {

        int size = strlen(tempStr);
        int base = idx;

        // printf("size: %d\n", size);

        for(int i=0; i<size; ++i) {
            bufferTarget[base + i] = tempStr[size-i];
            // printf("line: %-10d  '%-10c' at %d\n", base+i, tempStr[size-1-i], size-i);
            idx++;
        }
        bufferTarget[base+size-1] = '\n';
        idx++;
    }

    for(int i=0; i<length; ++i) {
        printf("%c", bufferTarget[i]);
    }

    free(bufferSource);
    free(bufferTarget);

    return EXIT_SUCCESS;
}
