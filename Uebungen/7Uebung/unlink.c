#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <error.h>
#include <getopt.h>
#include <time.h>
// Unlink veraendert die letzte aenderung im inode der datei

struct option long_opt[] = { 
    {"link1", required_argument, NULL, 'd'},
    {"link2", required_argument, NULL, 'f'},
    {"help", no_argument, NULL, 'h'},
    {NULL, no_argument, NULL, 0}
};

int main(int argc, char ** argv) {

    if(argc < 2) error(1, errno, "Aufruf: -delete file1 -file file2 \n-help");

    char *short_opt = "d:f:h";
    int ch;

    char *file1;
    char *file2;
    struct stat fstat2;

    while((ch = getopt_long(argc, argv, short_opt, long_opt, NULL)) != -1) {

        switch(ch) {
            case 'd':
                if(optarg == NULL) error(2, errno, "Cant open file");
                file1 = optarg; 
                break;
            case 'f':
                if(optarg == NULL) error(2, errno, "Cant open file");
                file2 = optarg; 
                break;
            case 'h':
                printf("Create 2 linked filed with 'ln'. Enter 2 files to this function to see if the changetime of the second file changes when the first one gets unlinked. (It does)");
        }
    }

    if(stat(file2, &fstat2) < 0) error(3, errno, "Stat exception");
    printf("Alte Zeit von %s:\n\t%s", file2, ctime(&fstat2.st_ctime));

    if(unlink(file1) == -1) error(4, errno, "Unlink exception");
    printf("Linked file '%s' was deleted\n", file1);

    if(stat(file2, &fstat2) < 0) error(3, errno, "Stat exception");
    printf("Neue Zeit von: %s:\n\t%s", file2, ctime(&fstat2.st_ctime));

    return EXIT_SUCCESS;
}
