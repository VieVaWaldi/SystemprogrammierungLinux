// ergibt so keinen sinn weil wir dafuer 2 prozesse braeuchten

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    
    int fifo = open("myfifo",O_RDWR);

    FILE *fp = fdopen(fifo, "rw");

    fprintf(fp, "HALLLLLLLLLLLLO hell\n");

    char buf[256];
    fscanf(fp, "%ns", buf);

    printf("%s\n", buf);

    return 0;
}
