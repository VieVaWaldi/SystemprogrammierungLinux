#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    char *file[1];
    file[0] = "error.log";

    char ch;
    char *optsttring = "a:";
    struct option long_opt[] = { {"file", required_argument, NULL, 'a'}, {0} };

    if((ch = getopt_long_only(argc, argv, optsttring, long_opt, NULL)) != -1) {
        if(optarg != NULL) file[0] = optarg;
    }

    printf("%s\n", file[0]);

    int fd;
    if((fd = open(file[0], O_RDWR)) < 0) {
        printf("error");
        exit(0);
    }

    sync();
    
    _exit(0);
    
    fsync(fd);

    return 0;
}
