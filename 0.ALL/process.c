#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int pid = getpid();

    int cpid;

    if((cpid = fork()) == -1) printf("error fork");
    if((cpid = fork()) == -1) printf("error fork");
    if((cpid = fork()) == -1) printf("error fork");
    if((cpid = fork()) == -1) printf("error fork");
    
    if(getpid() != pid) {
        printf("Child: PID: %d, PPID: %d\n", getpid(), getppid());
        //exit(0);
    }
    else {
        printf("Parent: PID: %d, PPID: %d\n", getpid(), getppid());
        exit(1);
    }

    printf("Process: %d, is alive, zombie army!\n", getpid());
}
