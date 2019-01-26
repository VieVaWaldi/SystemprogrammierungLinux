#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv) {
    
    if(argc < 2) error(1, errno, "gimme file");

    char *file = argv[1];
    char oldfile[256];

    strcpy(oldfile, "../");
    strcat(oldfile, file);

    chdir("fuck");

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));


    for(int i=0; i<20; i++) {
     
        char buff[64];
        char *num;
        sprintf(num, "%d", i);

        strcpy(buff, file);
        strcat(buff, num); 

        link(oldfile, buff);
    }

    return EXIT_SUCCESS;
}
