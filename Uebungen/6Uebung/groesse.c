// einfach stat auslesen
//
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <error.h>
#include <errno.h>

int main(int argc, char **argv) {

    struct stat mystat;

    int gesamt = 0, gesamtBloecke = 0;

    printf("%20s %10s %10s %10s\n", "Datei", "Groesse", "Bloecke", "Speicher" );

    for(int i=0; i <argc; ++i) {
        if(stat(argv[i], &mystat)) {
            error(0, errno, "stat nicht ausführbar fuer datei %s\n", argv[i]);
        }
        else {
            printf("%20s %10i %10i %10i\n", argv[i], gesamt += (int) mystat.st_size, gesamtBloecke +=  (int) mystat.st_blocks, (int) mystat.st_blocks * 512);
        
            //gesamt += ;
            //gesamtBloecke +=;
        }
        
    }

    return EXIT_SUCCESS;
}
