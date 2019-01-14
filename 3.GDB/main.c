// Uebung 3.1
// Is number a plaindrom?

#include <stdio.h>
#include <math.h>
#define TOP 1000

int isPalin(int num);
int isPalinVers2(int num);

void pI(int x);
void pS(char s[]);
void pD(char s[], int x);
void pIAr(int ar[], int cnt);

int main(int argsc, char *argv[]) {

    int num = 14341; 

    if(isPalin(num))
        pD("Is a palindrom", num);
    else
        pD("Is not a paplindrom", num);
        
    return 1;
}

int isPalinVer2(int num) {

    int tmp = num;
    int stellen = 0;

    while(tmp != 0) {
        tmp / 10;
        stellen ++;
    }

    char palin[stellen];

    while(num != 0) {
        
        int x = tmp % 10;
        tmp = tmp / 10;
        
    }
}

int isPalin(int num) {

    int stellen = 0;
    int mod = 0;
    int fak = 10;

    // 1. Erkenne Anzahl der Stellen

    while(num != mod) {
        stellen++;
        mod = num % fak;
        fak *= 10;
    }

    int palin[stellen];
    int max = stellen;
    int tmp = num;

    pD("stellen", stellen);

    // 2. Fuege ziffern in array

    for(int i=0; i<max; ++i) {

        tmp = tmp % 10;

        pD("num:", tmp);
        pD("ste:", stellen);

        stellen--;
        palin[i] = tmp / (int) pow(10, stellen); 
    }

    pIAr(palin, max);

    // 3. Vergleiche Arrays

    for(int i=0; i<max; i++) {

        if(palin[i] != palin[(max-1)-i]) {
            return 0;
        }
    }

    return 1;
}

void pI(int x) {
    printf("%d\n", x);
}

void pS(char s[]) {
    printf("%s\n", s);
}

void pD(char s[], int x) {
    printf("%s %d\n",s ,x);
}

void pIAr(int ar[], int cnt) {
    for(int i=0; i<cnt; ++i) {
        printf("Idx [%d] is: %d\n", i, ar[i]);
    }
}
