#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char ** argv) {

    printf("UID: %d\n", S_ISUID);
    printf("GID: %d\n", S_ISGID);
    printf("RUSR: %d\n", S_IRUSR);
    printf("WUSR: %d\n", S_IWUSR);
    printf("XUSR %d\n", S_IXUSR);

    return EXIT_SUCCESS;
}
