#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <error.h>

#include <time.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char **argv) {

    #ifdef _POSIX_CHOWN_RESTRICTED  // Wenn definiert darf nur root das machen

        if( getuid() == 0) {

            if( chown("testChown.c", 25, 25) == -1 ) {
                perror("chown");
            }
            else {
                printf("you must be root");
            }
        }
        else {
            printf(" you must be root");
        }
    #else                           // es ist nicht definiert also kann jeder den eigentuemer aendern

        printf("also alright");

    #endif

    return EXIT_SUCCESS;
}

