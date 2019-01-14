#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

// macht was mit paramertern
// zB -a, -b, -ab, -a b, -a=b

int main(int argc, char *argv[]) {

    char *optstr = "a:bc";      // Hier mit ':' bedeutet a hat eine option
                                // Nur ein ':' ist oft besser weil dann ein leerzeichen 
                                // dazwischen stehen kann
    char match = '\0';

    int aFlag = -1;

    // optind = 1;
    // opterr = 0;     // Fehlerausgabe aus
    
    // getopt()
    // Im Erfolgsfall bekomme ich die Option
    // Im Fehlfall bzw bei unbekannten optionen ein '?', in dem fall zeigt er das unbekannt zeichen 
    // Wenn nichts mehr da ist eine -1
   
    if(1) {
    while( (match = getopt(argc, argv, optstr)) != -1) {
        printf("%c %s %d %c \n", match, optarg, optind, optopt);
    
        switch( match ){        // Hier entscheiden wir was mit den optionen passiert
            case 'a':
                    aFlag = atoi(optarg);
                    // hat parameter, konvertieren und prüfen
                    // break;
                case 'b':
                break;
            case 'c':
                break;
            case '?': // Fehlerbehandlung
                printf("Benutzung des Programms %s gescheitert", argv[0]);
                exit(-1);
                break;
            default:
                printf("lol\n"); 
                break;

        }
    }

    printf("aFlag: %d", aFlag);
    printf("\n");

    }

//##################### Long opts ############################################# 

    if(0) {
        int value = -1;             // Wird hier in a verwendet um es am ende zu setzen
    
        struct option longopts[] =  { {"alpha", required_argument, &value, 'a'},
                                      {"bravo", no_argument, NULL, 'b'},
                                      {"charlie", no_argument, NULL, 'c'}, {0}};

        while( (match = getopt_long(argc, argv, optstr, longopts, NULL)) != -1) {
            printf("%c %s %d %c \n", match, optarg, optind, optopt);
        }

        printf("value: %c\n", value);
    }

    return 0;
}
