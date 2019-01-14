#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <error.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <utime.h>
#include <fcntl.h>

#define BUFSIZE 512

// Kopieren von Quelldatei in Zieldatei

int main(int argc, char **argv) {

    if(argc < 3 )   
        error(EXIT_FAILURE, EINVAL, "Aufruf: %s <quelle> <ziel>", argv[0]);
    
    int src, dest;

    if((src = open(argv[1], O_RDONLY)) == -1) 
        error(EXIT_FAILURE, errno, "Datei %s kann nicht gelesen werden", argv[1]);

    struct stat info;
    if( fstat(src, &info) )     // Hier bekommen wir die Rechte her
        perror("fstat");

    if((dest = open(argv[2], O_WRONLY | O_CREAT, info.st_mode & 7777 )) == -1)              // 7777 maske = allperms
        error(EXIT_FAILURE, errno, "Datei %s kann nicht geschrieben  werden", argv[2]);
    
    // Jetzt können wir kopieren
    // mit Read und Write über die Größe des Puffers.    

    char buffer[BUFSIZE];

    int anz = 0;

    while( (anz = read(src, buffer, BUFSIZE)) ) {
        if( anz == -1 )
            error(EXIT_FAILURE, errno, "read abgebrochen");  // error = exit, perror = notify

        if(write(dest, buffer, anz) != anz) 
            perror("Schreibfehler!");
    }

    close(src);
    close(dest);

    struct utimbuf times = {
        info.st_atime, info.st_mtime
    };

    if(utime(argv[2], &times))
        perror("?");

    return EXIT_SUCCESS;
}

