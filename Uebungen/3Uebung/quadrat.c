#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <libgen.h>
#include <error.h>

// specific
#include <unistd.h>
#include <getopt.h>

int main(int argc, char **argv) {

  int min = 1, max = 400;

  char *optstr = "u:o:";
  char match = '\0';
  int argcounter = 1;

  while( (match = getopt(argc, argv, optstr)) != -1 ) {

      argcounter++;

      switch(match) {
            case 'u': 
                if(optarg != NULL) {
                    min = atoi(optarg);
                }
                break;
            case 'o':
                if(optarg != NULL) {    
                    max = atoi(optarg);
                }
                break;
            default:
                argcounter--;
                fprintf(stderr,"omg an error\n");
            break;
      }
  }

  if(argcounter == 2 || 3 < argcounter ) {
    fprintf(stderr, "Wrong number of arguments: %d\n", argc);
    exit(EXIT_FAILURE);
  }

  // Fehler abfangen
  int tmp;
  if( min > max ) { tmp = min; min = max; max = tmp;  }

  printf("Berechnung der Quadratzahlen im Interval [%d; %d]\n", min, max);
  
  int z = 0;
  for( int i = min; i <= max; i++ ) 
  {
    double wurzel = sqrt(i);
    if( (wurzel - (int) wurzel) == 0.0 )
    {
      printf("%3d: %3i\n", (int) wurzel, i);
      z++;
    }
  }
  printf("Im gewaehlten Intervall gibt es %d Quadratzahlen.\n", z);
  return EXIT_SUCCESS;
}
