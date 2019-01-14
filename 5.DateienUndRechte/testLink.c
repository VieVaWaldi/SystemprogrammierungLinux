#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <error.h>

#include <time.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char **argv) {

    char link[20] = {0};

    if( symlink("/home/walterehren/Uni/SysL/5.DateienUndRechte/link.txt", "link") ) {
        perror("Erirrr");
    }

    printf("%d \n", readLink("link", link, sizeof(link)));

    return 1;
}

