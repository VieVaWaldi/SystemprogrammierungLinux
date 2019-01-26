#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *environ[]) {

    //  char cwd[256]; getcwd(cwd, sizeof(cwd));
    //  char *env = getenv(cwd);
    //  printf("cwd = %s\n", cwd);
    int i = 0; while(environ[i++]) { printf("%d: %s\n", i, environ[i]);  }
    if(setenv("TERM", "xterm-256color", 1) != 0) printf("cant ser env");
    i = 0; while(environ[i++]) { printf("%d: %s\n", i, environ[i]);  }
    //clearenv();
    printf("no error\n"); return 0;    
}
