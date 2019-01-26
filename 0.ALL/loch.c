#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {

    int fd = open("error.log", O_RDWR);

    lseek(fd, 10, SEEK_END);

    char *buf = "fdsa\n";

    dup2(STDOUT_FILENO, fd);
    
    write(fd, buf, sizeof(buf));

    close(fd);

    return 0;
}
