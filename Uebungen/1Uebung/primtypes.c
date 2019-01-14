#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void p(char s[], int b, int i);

int main(int argc, char** argv) {

    char ch;
    unsigned char Uch;
    signed char Sch;

    int i;
    unsigned int Ui;
    signed int Si;

    short s;
    unsigned short Us;
    signed short Ss;

    long l;
    unsigned long Ul;

    p("char", sizeof(ch), CHAR_BIT);
    p("u char max", sizeof(Uch), UCHAR_MAX);
    p("s char min", sizeof(Sch), SCHAR_MIN);
    p("s char max", sizeof(Sch), SCHAR_MAX);

    p("int", sizeof(i), 0);
    p("u int max", sizeof(Ui), UINT_MAX);
    p("s int min", sizeof(Si), INT_MIN);
    p("s int max", sizeof(Si), INT_MAX);

    p("short", sizeof(s), 0);
    p("u short max", sizeof(Us), USHRT_MAX);
    p("s chort min", sizeof(Ss), SHRT_MIN);
    p("s short max", sizeof(Ss), SHRT_MAX);
    
    p("long", sizeof(l), 0);
    p("u long max", sizeof(Ul), ULONG_MAX);
    
    return EXIT_SUCCESS;
}


void p(char s[], int b, int i) {
    printf("%-15s: %-8d, %-10ld\n", s, b, i);
}
