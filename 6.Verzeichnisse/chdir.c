#define _DEFAULT_SOURCE     // fuer fchdir, setzt use flags. Wird von features.h nicht geloscht 

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>      // RDONLY
#include <sys/stat.h>
#include <ftw.h>        // ftw und flags
#include <string.h>

// Hilfsfunktion zur schoenen ausgabe. Zaehlt '/'
int dir_tiefe(const char* pfad) {
    
    int z = 0;
    char *ptr = (char*) pfad;

    while((ptr = strchr(ptr, '/'))) {   // zaehlt hier nur gefundene '/', bricht ueber \0 ab
        ptr++;
        z++;
    }
    
    return z;
}

int traverse(const char* pfad, const struct stat *sb, int typeflags) {

    static char erstemal = 1;
    static int ausgangs_tiefe = 0;

    if( !erstemal ) {       // hier rein wenn reg Datei
        
        for(int i=1;i < dir_tiefe(pfad) - ausgangs_tiefe; ++i) {
           printf("%4c|", ' '); 
        }
        printf("----%s", strrchr(pfad, '/') +1);
    }
    else {  
        ausgangs_tiefe = dir_tiefe(pfad);
        printf("%s", pfad);
        erstemal = 0;
    }

    // siehe man ftw

    switch(typeflags) {
        case FTW_F:     // reg Datei
            printf("\n");
            break;
        case FTW_D:     // dir
            printf("/\n");
            break;
        case FTW_DNR:   // dir nicht lesbar
            break;
        case FTW_NS:    
            break;
        default:
            perror("file traverse walk");
    }

    // 0 beutet fuer ftw mach weiter(Erfolg), alles andere bedeutet brich ab und liefere den 
    // wert zurueck
    return 0;
}

int main(int argc, char ** argv) {

    int fd = open("..", O_RDONLY);    // dir: ../ gibt es ueberall

    fchdir(fd);                       // wechsel in den ordner
    
    char *cwd = getcwd(NULL, 0);     // current working dir

    printf("%s\n", cwd);

    free(cwd);
    close(fd);

    chdir("testdir");

    ftw(".", &traverse, 100);

    return EXIT_SUCCESS;
}
