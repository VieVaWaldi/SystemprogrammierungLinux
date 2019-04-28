#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *env[]) {

    //  char cwd[256]; getcwd(cwd, sizeof(cwd));
    //  char *env = getenv(cwd);
    //  printf("cwd = %s\n", cwd);
    int i = 0; while(env[i++]) { printf("%d: %s\n", i, env[i]);  }
    if(setenv("TERM", "xterm-256color", 1) != 0) printf("cant ser env");
    i = 0; while(env[i++]) { printf("%d: %s\n", i, env[i]);  }
    //clearenv();
    printf("no error\n"); return 0;    
}
