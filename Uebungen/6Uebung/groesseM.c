#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>

int main(int argc, char ** argv) {

    if(argc < 2) error(1, errno, "Aufruf: file1 file2 ...");

    int gesamtGroesse = 0;
    int gesamtBloecke = 0;
    struct stat buf;

    printf("%20s %10s %10s %10s\n", "Datei", "Groesse", "Bloecke", "Speicher");

    for(int i=0; i<argc; i++) {

        if(stat(argv[i], &buf)) error(2, errno, "Stat fehler");
        else {
            printf("%20s %10ld %10ld %10ld\n", argv[i], buf.st_size, buf.st_blksize, buf.st_blksize * buf.st_size);
        }
    }

    return EXIT_SUCCESS;
}
