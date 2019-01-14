#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
  printf("Berechnung der Wurzeln im Interval [min; max]\n");

  int min, max, precision;
  
  printf("min = ");
  scanf("%d", &min);
  
  printf("max = ");
  scanf("%d", &max);
  
  printf("Genauigkeit = ");
  scanf("%d", &precision);
 
  int tmp;
  if( min > max ) { tmp = min; min = max; max = tmp;  }

  printf("Berechnung im Intervall [%d;%d] mit Genauigkeit %d.\n", min, max, precision);

  int width = 1;
  tmp = max;
  
  while( tmp /= 10 ) 
    width++;

  for( int i = min; i <= max; i++ ) { 
    printf("%1$*4$d : %2$.*3$lf\n", i, sqrt(i), precision, width);
  }

  return EXIT_SUCCESS;
}
