#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    
    if(argc < 2) error(1, errno, "gimme dir");
    char *dirname = argv[1];

    DIR *dir;
    struct dirent *sdir;

    if((dir = opendir(dirname)) == NULL) error(2, errno, "Cant open dir");

    while((sdir = readdir(dir)) != NULL) {
        char *name = sdir->d_name;
        
        struct stat fstat;
        stat(name, &fstat);
        
        if(S_ISDIR(fstat.st_mode) == 0) printf("DIR: %s\n", name);
        else if(S_ISLNK(fstat.st_mode) == 0) {
            unlink(name);
            printf("unLINKed: %s\n", name);
        }        
    }

    closedir(dir);

    return EXIT_SUCCESS;
}
