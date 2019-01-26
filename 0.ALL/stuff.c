#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct adresse *ptr;

struct addresse {
    char name[100];
    int alter;
} addresse;

void* allokiere(int size) {
    char arr[size];
    return arr;
}

int divi(int a, int b) {
    int *ptr;

    if(b != 0) {
        int erg;
        erg = a+b;
        ptr = &erg;
    }

    return *ptr;
}

void stufn() {
    //    strcpy(ptr->name, "Hans Meyer");
    //    ptr->alter = 10;
}

int main(int argc, char **argv) {

    char *ar = (char*) allokiere(3);
    ar = "123";

    printf("%s\n", ar);
    printf("%d\n", divi(12, 0));  
    //printf("%s is %d years old", ptr->name, ptr->alter);
    printf("%s\n", argv[0]);

    return EXIT_SUCCESS;
}
