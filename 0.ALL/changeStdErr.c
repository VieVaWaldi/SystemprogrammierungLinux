#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <error.h>
#include <getopt.h>

int main(int argc, char **argv) {

    char *logfile = "error.log";
    int fd;

    if((fd = open(logfile, O_CREAT | O_WRONLY | O_APPEND, 0754)) == -1) error(0, errno, "File sux");

    dup2(fd, 2);

    int ch;
    char short_opt[] = "a:b:c:";

    while((ch = getopt(argc, argv, short_opt)) != -1 ) {

        switch(ch) {
            case 'a':
                if(optarg == NULL) error(1, errno, "AException");
                break;
            case 'b':
                if(optarg == NULL) error(1, errno, "BException");
                break;
            case 'c':
                if(optarg == NULL) error(1, errno, "CException");
                break;
        }
    }

    error(2, errno, "Error: Finished succesfully");

    return EXIT_SUCCESS;
}
