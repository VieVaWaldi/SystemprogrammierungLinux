#include <stdio.h>
#include <stdlib.h>

int b;//auto (-> global) variable, reachable from everywhere

static int c;//static variable, only reachable in this module

extern int z;//extern variable, defined elsewhere

void func(int, int);

int main(int argc, char *argv[])
{

  int a;//auto (-> local) variable

  void (*y)(int, int);

  a = 0;
  b = 1;
  c = 2;
  z = 3;
  y = &func;
  
  y(a, c);

  return EXIT_SUCCESS;
}
