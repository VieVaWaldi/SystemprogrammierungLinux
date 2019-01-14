#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void p(char s[], int b);

int main(int argc, char** argv) {


    p("CHAR_BIT:", __CHAR_BIT__);

    __caddr_t caddr;
    __clock_t clock;
    __dev_t dev;
    fpos_t fpos;
    __gid_t gid;
    __ino_t ino;
    __mode_t mode;
    __nlink_t nlink;
    __off_t off;
    __pid_t pid;
    __ptr_t ptrdiff;
    __rlim_t rlim;

    p("caddr_t:", sizeof(caddr));
    p("clock_t:", sizeof(clock));
    p("dev:", sizeof(dev));
    p("fpos:", sizeof(fpos));
    p("gid:", sizeof(gid));
    p("ino:", sizeof(ino));
    p("mode:", sizeof(mode));
    p("nlink:", sizeof(nlink));
    p("off:", sizeof(off));
    p("pid:", sizeof(pid));
    p("ptrdiff:", sizeof(ptrdiff));
    p("rlim:", sizeof(rlim));

    return EXIT_SUCCESS;
}


void p(char s[], int b) {
    printf("%10s: %d\n", s, b);
}
