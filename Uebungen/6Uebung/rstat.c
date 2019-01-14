#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <errno.h>
#include <error.h>

int main(int argc, char **argv) {

    if (argc < 2) error(1, errno, "Zu wenig Argument"); 

    int i = 1;
    char *file;
    struct stat rstat;
    
    printf("%10s |%10s |%10s |%10s |%10s |%10s |%10s |%10s\n", "File","DevID", "Inode", "Rechte", "UID", "GID", "BLKSize", "BLKCnt");

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    for(int i=0; i<w.ws_col; ++i) printf("*");
    printf("\n");

    while(argv[i]){

        file = argv[i];
        
        if(stat(file, &rstat) < 0) {
            error(2, errno, "%s exisitiert nicht", file);
            exit(EXIT_FAILURE);
        }
        
        printf("%10s |%10ld |%10ld |%10d |%10d |%10d |%10ld |%10ld\n", file, rstat.st_dev, rstat.st_ino, rstat.st_mode, rstat.st_uid, rstat.st_gid, rstat.st_blksize, rstat.st_blocks);
        
        i++;
    }

    return EXIT_SUCCESS;

}
