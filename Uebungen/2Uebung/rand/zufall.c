#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WUERFEL 6

#define NEWLINE printf("\n");


int main(int argc, char* argv[])
{
  float soll = 1 / 6.0f;
  int feld[WUERFEL] = {0};
  long anzahl;

  printf("Wie oft ist zu Wuerfeln? ");
  scanf("%ld",&anzahl);

  printf("OK! Wuerfele %'ld mal.\n", anzahl); 

  long i = 0;
  int t1 = time(NULL);
  srand(t1);
  while( i++ < anzahl ) feld[ rand() % WUERFEL ] ++; 
  NEWLINE
  printf("Zahl\t");
  for( i = 0; i < WUERFEL; printf("| %12ld\t", i+++1));
  NEWLINE
  for( i = 0; i < WUERFEL; printf("------------------"), i++);
  NEWLINE
  printf("Wuerfe\t");
  for( i = 0; i < WUERFEL; printf("| %12i\t", feld[i++]));
  NEWLINE
  printf("Prozent\t");
  for( i = 0; i < WUERFEL; printf("| %12lf\t", (float)feld[i++]/anzahl));
  NEWLINE
  printf("Abweich\t");
  for( i = 0; i < WUERFEL; printf("| %12f\t", (float)feld[i++]/anzahl - soll));
  NEWLINE
  NEWLINE
  int t2 = time(NULL);
  printf("Das hat %ds gedauert.\n", t2 - t1);
  return EXIT_SUCCESS;
}
