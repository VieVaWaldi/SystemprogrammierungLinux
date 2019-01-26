#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <error.h>

int main(int argc, char *argv[]) {

    int chid;
    int pid = getpid();

    for(int i=0; i<10; i++) {
        if((chid = fork()) == -1) error(1, errno, "Fork EXCEPTION");
        if(pid != getpid()) printf("New Child with pid %d\n", getpid());
        if(chid == 0) break;
    }

    if(pid == getpid()) system("ps | grep 'defunct'");

    return 0;
}
