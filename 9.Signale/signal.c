#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

    // while(1);    Run in Bg and kill, then fg 1
    
    signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);
    signal(SIGSTOP, SIG_IGN);

    while(1);   // kill -s SIGALRM 'pid'

    return EXIT_SUCCESS;
}
