#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  double summe = 0;

  for( int i = 0; i < argc; summe += atof(argv[i++]));
    
  printf("%g\n", summe);
  
  return EXIT_SUCCESS;
}

