#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

// sendet sigal an sich selbst fuer 10 s
// wir koennen es ueber den zwweitenhandler aufwecken
//
// ./coutdown 100
// kills -s SIGUSR2 pid

void handler(int sig) {
    
    int rest = alarm(0);
    printf("%d %s\n", rest,  strsignal(sig));
    alarm(rest);
}

int main(int argc, char *argv[]) {


    int dur = 10;
    if(argc == 3) dur = atoi(argv[2]);
       
    struct sigaction act = {0};
    act.sa_handler = &handler;

    signal(SIGUSR1, handler);
    sigaction(SIGUSR2, &act, NULL);

    alarm(dur);

    while(dur-->0)  {
        raise(SIGUSR1);
        if(sleep(1)) { printf("errorsleep"); }
        printf("dauer: %d\n", dur);
    }

    return 0;
}
