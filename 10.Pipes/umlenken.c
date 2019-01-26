#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    int fd[2];

    if(pipe(fd) ) perror("Pipe Error");
   
    int pid = fork();

    if(pid) {
       
        close(fd[0]);
        if(dup2(fd[1], STDOUT_FILENO) == -1) perror("dup2 error");

        char *line = "WHatssss up bitches!?\n";
        if(write(STDOUT_FILENO, line, strlen(line)) == -1) perror("Write Error");
    
        close(fd[1]);
    }
    else if(pid == 0){
        
        if(dup2(fd[0], STDIN_FILENO) == -1) perror("dup2 error");

        close(fd[1]);

        char buf[128];
        // kann nicht mit lseek suchen: da keine file ?
        int anz = 0;
        if((anz = read(STDIN_FILENO, buf, sizeof(buf))) == -1) perror("Read error");

        write(STDOUT_FILENO, buf, anz);
        
        close(fd[1]);
    }    

    return 0;
}
