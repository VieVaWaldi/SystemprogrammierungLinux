#define _XOPEN_SOURCE_EXTENDED 1

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <getopt.h>

static struct option long_opt[] = {
    {"vfork", no_argument, NULL, 'v'}, {0}
};

int main(int argc, char **argv) {

    int useFork = 1;

    char ch;
    char *short_opt = "v";

    if((ch = getopt_long(argc, argv, short_opt, long_opt, NULL)) != -1) {
        printf("Using vfork() instead of fork().");
        useFork = 0;
    }

    int pid = getpid();
    int chid;

    
    if(useFork) if((chid = fork()) == -1) {
        printf("fork error\n");
        exit(0);
    } 
    if(!useFork) if((chid = vfork()) == -1) {
        printf("fork error\n");
        exit(0);
    }
    
    if(chid == 0) {
        chid = getpid();
    }
    printf("Parent id = %d\n", pid);
    printf("Child id = %d\n", chid);

    int i = 0;
    while(i < 20) {
        i++;
        if(getpid() == pid) {
            if(i%2==0) printf("Parent: %d\n", i);            
        }
        if(getpid() == chid) {
            if(i%2!=0) printf("Child: %d\n", i);            
        }
    }

    if(chid == getpid()) {
        printf("Child exiting...");
        exit(0);
    }
    
    return 0;
}
