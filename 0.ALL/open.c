#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv) {

    int ch = open("open.c", O_RDWR);
    printf("ch = %d\n", ch);

    return EXIT_SUCCESS;
}
