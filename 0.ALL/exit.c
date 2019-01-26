#include <stdlib.h>
#include <stdio.h>


void clean(void) {
    printf("Cleaned ptr");
}

void main(void) {

    int *ptr = (int*) malloc(sizeof(int));

    int a = 3; ptr = &a; printf("*ptr = %d\n", *ptr);

    atexit(clean);
}
