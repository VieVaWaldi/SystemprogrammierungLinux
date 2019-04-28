#include <unistd.h>
#include <sys/types.h>

int main(void) {

    printf("pid %d, ppid %d, uid %d, gid %d, euid %d, guid %d\n", getpid(), getppid(), getuid(), getpid(), geteuid(), getegid());
        
    return 0;
}
