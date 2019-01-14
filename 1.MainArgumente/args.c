#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char ** argv) {

    printf("anzahl args: %d\n", argc);

    for(int i=0; i<argc; i++) {
        printf("arg: %s\n", argv[i]);
    }

    printf("\n");

    int i = 0;

    while(argv[++i]) {
    
        if(argv[i] == NULL) {
            break;
        }
            
        printf("arg: %s\n", argv[i]);
    }


    return EXIT_SUCCESS;
}
