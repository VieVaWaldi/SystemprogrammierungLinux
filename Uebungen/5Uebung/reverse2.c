#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <error.h>

#define NL '\n'

void println(int fd) {
    
    char c;

    while( read(fd, &c, 1) > 0 ) {
        write(STDOUT_FILENO, &c, 1);
        if( c == NL ) break;
    }
}

int main(int argc, char *argv[]) {

    if(argc < 2) error(1, EINVAL, "./reverse 'filename'");

    int fd = open(argv[1], O_RDONLY );
    if( fd < 0 ) error(2, errno, "Datei kann nicht geoeffnet werden.");

    if( lseek(fd, -1L, SEEK_END) < 0 ) perror("lseek");

    char c;

    do {
        read(fd, &c, 1);
        if(c == NL) {
            off_t pos = lseek(fd, 0L, SEEK_CUR);
            println(fd);
            lseek(fd, pos, SEEK_SET);
        }
    } while( lseek(fd, -2L, SEEK_CUR) > 0 );

    lseek(fd, 0L, SEEK_SET);
    println(fd);

    close(fd);

    return EXIT_SUCCESS;
}
