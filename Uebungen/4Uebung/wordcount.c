#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

// Read letters, word, and lines
// use struct

// option to read from stdin

static struct option long_opts[] = {
    {"filename", required_argument, NULL, 'f'},
    {NULL, no_argument, NULL, 0}
};

int main(int argc, char **argv) {

    char *short_opts = "f:";
    int ch;
    char *fileName;

    if((ch = getopt_long(argc, argv, short_opts, long_opts, NULL)) != -1) {
        if(optarg != NULL) {
            fileName = optarg;
        }
        else {
            perror("give me a file\n");
            exit(EXIT_FAILURE);
        }
    }
    else {
        perror("give me a file\n");
        exit(EXIT_FAILURE);
    }

    // Implementation
   
    FILE *fptr;
    fptr = fopen(fileName, "r");
    
    if(fptr == NULL) {
        perror("Cant open file\n");
        exit(EXIT_FAILURE);
    }

    // read file with max size
    int n=512;
    char buffer[512] = {'\0'};
    fgets(buffer, n, fptr);

    // count
    int max = 0;

    // seek file size
    fseek(fptr, 0L, SEEK_END);  // count
    max = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);  // reset

    int spaces = 0;
    int letters = 0;
    int newlines = 0;

    for(int i=0; i<max; ++i) {
        int c = getc(fptr);
        
        if(c == 32) {
            spaces++;
            continue;
        }

        if((c == 10) || (c == 13)) {
            newlines++;
            continue;
        }
    
        letters++;
    }

    printf("number of letters: %d\nnumber of spaces:%d\nnumber of newlines: %d\n", letters, spaces, newlines);

    return EXIT_SUCCESS;
}
