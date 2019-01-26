#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>

int main(int argc, char **argv) {

    char *short_opt = "f:";
    char *file = "filedes.c";

    if(getopt(argc, argv, short_opt) != -1) {
        if(optarg != NULL) {
            file = optarg;
        }
    }
    
    int ch = open(file, O_RDWR);       
    if( ch == -1 ) {
        printf("Wrong filename");
        exit(1);
    }

    struct stat mstat;
    fstat(ch, &mstat);
    int sz = mstat.st_size;

    // fseek(ch, 0L, SEEK_END);
    // int sz = ftell(ch);
    // fseek(ch, 0L, SEEK_SET);
    
    char *buff = (char*) malloc(sizeof(char) * sz);
    read(ch, buff, sz);

    int i = 0;
    do {
        printf("%c", buff[i]);
        i++;
    } while(buff[i]);

    free(buff);
    close(ch);
        
    return EXIT_SUCCESS;
}
