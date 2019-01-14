#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argv, char **argc) {

    #if defined _POSIX_CHOWN_RESTRICTED
    #define TEST getuid() == 0
    #else
    #define TEST 1
    #endif

    if(TEST) 
        if( chown("testFile", 25, 25) == -1 ) perror("chown");
    else printf("you gotta be root...");

    char link[200] = {0};
    if( symlink("~/Uni/SysL/Uebungen/6Uebung/testFile", "link") ) perror("symlink");

    printf("%d\n", readlink("link", link, sizeof(link)));
    printf("%s\n", link);

    return EXIT_SUCCESS;
}
