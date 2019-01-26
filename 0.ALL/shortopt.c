#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

int main(int argc, char**argv) {

    char *short_opt = "h:";
    int ch;

    while((ch = getopt(argc, argv, short_opt)) != -1) {

        switch(ch) {
            case 'h':
                if(optarg == NULL) printf("nice\n");
                else printf("nice with %s\n", optarg);
        }
    }

    printf("opterr = %d\noptind = %d\noptopt = %d\n", opterr, optind, optopt);

    return EXIT_SUCCESS;
}
