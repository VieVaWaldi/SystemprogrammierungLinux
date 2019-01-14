#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <error.h>

#include <time.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char **argv) {

    mode_t oldMask = umask(0);

    if(chmod("testUmask.c", 0600) == -1 ) {
        perror("chmod");
    }

    
    printf("alte umask: %d\n", oldMask);
    printf("verwendete umask: %d\n", umask(oldMask));

    return 1;
}

