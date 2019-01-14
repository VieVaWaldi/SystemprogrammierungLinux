#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <getopt.h> 
#include <error.h>
#include <errno.h>

struct option long_opt[] = {
    {"file", required_argument, NULL, 'f'},
    {"searchFrom", required_argument, NULL, 's'}
};

void searchDirectoryRec(char *searchDir, char *file) {

    DIR *dir;
    struct dirent *dirStat;

    if((dir = opendir(searchDir)) == NULL) error(3, errno, "DIR Excpetion");

    while((dirStat = readdir(dir)) != NULL) {

        char *currFile = dirStat->d_name;

        printf("D current file: %s\n", currFile);

        if(strstr(currFile, ".")) {
            continue;
        } 

        if(strcmp(currFile, file) == 1) {
           printf("%s is in: %s\n", file, searchDir);
           exit(1);
        }

        currFile = "/home";

        struct stat tmpDirStat;
        stat(currFile, &tmpDirStat);

        if(S_ISDIR(tmpDirStat.st_mode)) {
            printf("%s is a dir", currFile);
            char *concatDir = strcat(searchDir, "/");
            concatDir = strcat(searchDir, currFile);
            searchDirectoryRec(concatDir, file);
        }

    }

    closedir(dir);
}

int main(int argc, char ** argv) {

    if(argc < 2) error(1, errno, "Please enter -f 'filename' optional: -s 'searchFrom'");

    char *short_opt = "f:s:";
    int ch;

    char *file;
    char *searchDir = "/";
    
    while((ch = getopt_long(argc, argv, short_opt, long_opt, NULL)) != -1) {

        switch(ch) {
            case 'f':
                if(optarg == NULL) error(2, errno, "OPTARG exception");
                file = optarg;
            case 's':
                if(optarg == NULL) error(2, errno, "OPTARG exception");
                searchDir = optarg;
            }
    }

    searchDirectoryRec(searchDir, file);

    return EXIT_SUCCESS;
}


