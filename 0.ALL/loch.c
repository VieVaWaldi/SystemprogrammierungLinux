#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {

    int fd = open("lol.log", O_RDWR);

    lseek(fd, 50, SEEK_END);

    char *buf = "fdsa\n";

    write(fd, buf, sizeof(buf));

    dup2(STDOUT_FILENO, fd);
    
    write(fd, buf, sizeof(buf));

    close(fd);

    return 0;
}
