#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv) {

    printf("pid: %d, ppid: %d\n", getpid(), getppid());
    printf("uid: %d, gid: %d\n", getuid(), getgid());
    printf("euid: %d, egid: %d\n", geteuid(), getegid());

    int k = 0;

    while( ++k < 10 ) {

        // Kindprozess ist hier 0, Elternprozess nicht
        // Programm gibt es ab hier 2 mal
        pid_t pid = fork();

        if( pid == 0) {
    
            printf("Kindprozess\n");
            printf("Kind: pid: %d, ppid: %d\n", getpid(), getppid());
            printf("Kind: uid: %d, gid: %d\n", getuid(), getgid());
            printf("Kind: euid: %d, egid: %d\n", geteuid(), getegid());
            exit(0);
        }
        else if( pid < 0 ){
            printf("Could not fork()...\n");
        }
    }

    printf("Elternprozess");

    printf("Eltern: pid: %d, ppid: %d\n", getpid(), getppid());
    printf("Eltern: uid: %d, gid: %d\n", getuid(), getgid());
    printf("Eltern: euid: %d, egid: %d\n", geteuid(), getegid());

    int status; 
    pid_t pid;

    while( (pid = wait(&status)) > 0) {     // Lass mal > 0 weg
        printf("Eltern: Kind: %d beendet", wait(&status));
        if(WIFEXITED(status)) printf("Eltern: normal beendet mit %d\n", WEXITSTATUS(status));
    }

    return EXIT_SUCCESS;
}
