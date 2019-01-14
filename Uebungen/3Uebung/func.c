#include <stdio.h>

int z;
extern int b;//is global in main 
//extern int c;//is static in main

void func(int a, int c)
{
  register int *x = NULL;
  x = (int*) &func;
  //((void(*)())x)();
  printf("func: a: -, b: %d, c: -, z: %d\n", b, z);
}

