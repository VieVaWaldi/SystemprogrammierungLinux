#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {

    int fd = open("error.log", O_RDWR);
    
    lseek(fd, 0L, SEEK_END);
    int sz = lseek(fd, 0, SEEK_CUR);
    lseek(fd, 0L, SEEK_SET);

    char buf[sz];
    size_t size = read(fd, buf, sz);

    printf("sz = %d, size = %ld\n", sz, size);
    
    return 0;
}

