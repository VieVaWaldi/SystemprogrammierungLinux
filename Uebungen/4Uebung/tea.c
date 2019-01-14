#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <getopt.h>

extern int errno;

static struct option long_opts[] = {
    {"fileOpen", required_argument, NULL, 'o'},
    {"fileFOpen", required_argument, NULL, 'f'},
    {NULL, no_argument, NULL, 0}
};

int main(int argc, char ** argv) {

    // options
    char *optstring = "f:o:";
    char *fileNameO = "stdO";
    char *fileNameF = "stdF";
    int ch;

    while((ch = getopt_long(argc, argv, optstring, long_opts, NULL)) != -1 ) {

        printf("ch = %d\n", ch);
        printf("optarg = %s \n\n", optarg);

        if(ch == -1) {
            printf("Standart file name will be provided... \n");
            printf("./tea -oFILE || -fFILE to specify file name \n");
            //break;
        }
        
        switch(ch) {
    
            case 'o': 
                fileNameO = optarg;
                break;
            case 'f':
                fileNameF = optarg;
                break;
        }
    }

    // getopt for new files

    int fd = open(fileNameO, O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IXOTH);
    printf("File descriptor: %d\n", fd);

    FILE *filePtr;
    
    filePtr = fopen(fileNameF, "w");

    // error when not available
    if((fd == 2) || (fd < 0)) {
        perror("Well, ups an error occured . I am sorry :-(");
    }

    if(filePtr == NULL) {
        perror("Well, ups an error occured . I am sorry :-(");
    }

    // read until ctrl d
    char s[50] = {'\0'};
    printf("write stuff, end with newLine ...\n");
    
    scanf("%[^\n]%*c", s);

    // write
    printf("Trying to write: \n%s\n", s);
    int i = sizeof(s);

    write(fd, s, i);  
    fwrite(s, 1, sizeof(s), filePtr);

    //fprintf(filePtr, "UERBERSCHREIBEN okay \n");
    fprintf(stdout, "UERBERSCHREIBEN okay \n");

    // close
    fclose(filePtr);

    return EXIT_SUCCESS;
}
