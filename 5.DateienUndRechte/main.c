// Uebung 3.1
// Is number a plaindrom?

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argsc, char *argv[]) {

    if( lseek(STDIN_FILENO, 0L, SEEK_SET ) == -1 ) {
        perror("kann icht in std in positionieren.");
    }
        
    return EXIT_SUCCESS;
}

