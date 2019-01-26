#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <errno.h>
#include <getopt.h>

int main(int argc, char **argv) {

    char *short_opt = "f:";
    int ch;
    char *file = "error.log";
    FILE *fd;

    if((ch = getopt(argc, argv, short_opt)) != -1)
        file = optarg;

    if((fd = fopen(file, "r")) == NULL) error(1, errno, "file sux");

    struct stat filestat;
    if(stat(file, &filestat) < 0) error(2, errno, "STAT Exception");
    printf("%c\n", filestat.st_mode);

    mode_t mymode = 0754;

    if(chmod(file, mymode) == -1) error(3, errno, "chmod Exce");

    if(stat(file, &filestat) < 0) error(2, errno, "STAT Exception");
    printf("%c\n", filestat.st_mode);
    
    return EXIT_SUCCESS;
}
