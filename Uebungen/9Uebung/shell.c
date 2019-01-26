#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <getopt.h>
#include <errno.h>
#include <error.h>

#include "search.h"

static struct option long_opt[] = {
    {"directory", required_argument, NULL, 'd'},
    {"file", required_argument, NULL, 'f'},
    {0}
};

int main(int argc, char **argv) {

    if(argc < 2 ) error(1, errno, "./shell --dir d --file f");

    char ch;
    char *short_opt = ":d:f:";
    
    char *dir, *fil;

    while((ch = getopt_long(argc, argv, short_opt, long_opt, NULL)) != -1) {
        switch(ch) {
            case 'd':
                if(optarg == NULL) error(2, errno, "GIVE ME COMMAND");
                dir = optarg;
                break;
            case 'f':
                if(optarg == NULL) error(2, errno, "GIVE ME FILE");
                fil = optarg;
                break;
        }
    }

    int chid;
    if((chid = fork()) == -1) error(1, errno, "Fork Exception");


    if(chid == 0) {
        printf("CHILD PID = %d starts search\n", getpid());
        int retStatus = searchFile(dir, fil);
        printf("search done\n");
        exit(retStatus);
    }

    int *status;
    wait(status);

    return *status;
}
