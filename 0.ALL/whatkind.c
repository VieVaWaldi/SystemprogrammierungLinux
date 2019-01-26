#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <errno.h>
#include <getopt.h>

int main(int argc, char **argv) {

    char short_opt[] = "f:";
    char *file = "error.log";
    int ch;

    ch = getopt(argc, argv, short_opt);

    if(ch == 'f')
        if(optarg != NULL)
            file = optarg;
    
    int fd;

    if((fd = open(file, O_RDONLY)) == -1) error(1, errno, "file sux");

    struct stat filestat;
    fstat(fd, &filestat);

    if(S_ISREG(filestat.st_mode)) printf("%s is a reg file\n", file);
    if(S_ISDIR(filestat.st_mode)) printf("%s is a dir\n", file);
    if(S_ISFIFO(filestat.st_mode)) printf("%s is a fifo\n", file);
    if(S_ISLNK(filestat.st_mode)) printf("%s is a link\n", file);

    return EXIT_SUCCESS;
}
