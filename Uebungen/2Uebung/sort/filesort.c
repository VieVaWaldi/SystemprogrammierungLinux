#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>

int compare( const void *p1, const void *p2)
{
  return *(char *)p1 - *(char *)p2;
}

int main(int argc, char *argv[])
{

  if( argc < 2 ) 
  {
    fprintf(stderr, "Aufruf: %s <Dateiname>\n", basename(argv[0]));
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");

  if( fp == NULL ) { perror("fopen"); exit(EXIT_FAILURE); }

  unsigned long filesize = 0;
  fseek(fp, 0, SEEK_END);
  filesize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  printf("filesize: %ld\n", filesize);

  char *buffer = (char*) malloc(filesize * sizeof(char));
  
  long i = 0;
  while( i < filesize ) buffer[i++] = fgetc(fp);
  printf("%s\n", buffer); 

  qsort(buffer, (size_t) filesize, sizeof(char), &compare);

  printf("%s\n", buffer);


  free(buffer);
  fclose(fp); 
  
  return EXIT_SUCCESS;
}

