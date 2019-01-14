#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <error.h>

#include <time.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv) {

    struct stat inode;

    if(stat("testStat.c", &inode) == -1 ) {
        error(1, errno, "Could not stat");
    } 

    printf("INodeNr: %d\n",(int)inode.st_ino);

    if( S_ISDIR(inode.st_mode) )
        printf("dir\n");
    else if( S_ISREG(inode.st_mode) )
        printf("reg \n");
    else 
        printf("st_mode: ");

    printf("letzte aenderung: %s", ctime(&(inode.st_ctime)));

    return 1;
}

