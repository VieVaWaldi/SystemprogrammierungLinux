#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

    pid_t pid = getpid();
    int chid;

    printf("Parent: %d\n", pid);

    if((chid = vfork()) == -1) { printf("fork Exception"); exit(1); }

    if(chid == 0) {
        printf("Child: %d\n", getpid());
        execv("./wuerfel", argv);
    }
    
    printf("I am: %d\n", getpid());

    return 0;
}
