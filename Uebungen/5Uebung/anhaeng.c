#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <fcntl.h>

static struct option long_opts[] = {
    {"fileSrc", required_argument, NULL, 's'},
    {"fileTar", required_argument, NULL, 't'},
    {NULL, required_argument, NULL, 0}
};

int main(int argc, char ** argv) {

    char *short_opts = "s:t:";
    char *fileSrc;
    char *fileTar;
    int ch;

    if(argc < 3) {
        printf("Choose two files:\n./anhaeng -s file1 -t file2\n");
        exit(EXIT_FAILURE);
    }

    while((ch = getopt_long(argc, argv, short_opts, long_opts, NULL)) != -1) {

        printf("ch = %c", ch);

        switch(ch) {

            case 's':
                if(optarg != NULL) 
                    fileSrc = optarg;
                break;
            case 't':
                if(optarg != NULL)
                    fileTar = optarg;
                break; 
        }
    }

    if((fileSrc == NULL) || (fileTar == NULL) || (fileTar == fileSrc)) {
        printf("provide a target and a source file!");
        exit(EXIT_FAILURE);
    }
    
    // implementation

    FILE *source = fopen(fileSrc, "r");
    FILE *target = fopen(fileTar, "a");
    
        // length of source
    fseek(source, 0L, SEEK_END);
    int length = ftell(source);
    fseek(source, 0L, SEEK_SET);
    
    char readBuffer[length];

    fread(readBuffer, length, 1, source);
    fwrite(readBuffer, length, 1, target);

    fclose(source);
    fclose(target);

    return EXIT_SUCCESS;
}
