#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {

    int fd1, fd2;

    umask(0);

    if((fd1 = open("txt2.log", O_CREAT | O_TRUNC | O_RDWR, 0770)) == -1) perror("Cant open\n");
    fd2 = dup(fd1);
//    close(fd1);

    char *buf = "fufufufufumsure\n";
    write(fd2, buf, sizeof(buf));

    // fcntl(fd1, O_APPEND, F_SETFL); 

    buf = "dududusure\n";
    write(fd1, buf, sizeof(buf));

//    fchmod(fd1, S_IRWXU | S_IRWXG | S_IRWXO);

    close(fd2);
    close(fd1);
    
    return 0;
}
