#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <libgen.h>
#include <error.h>

int main(int argc, char **argv)
{
  int min = 1, max = 100;

  if( argc > 2 ) max = atoi(argv[2]);
  if( argc > 1 ) min = atoi(argv[1]);

  else fprintf(stderr, "Aufruf: %s min max\n", basename(argv[0]));

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
