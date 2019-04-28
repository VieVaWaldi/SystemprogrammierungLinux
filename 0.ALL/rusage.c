#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {

    struct rusage *usage = (rusage*) (malloc(sizeof(rusage)));

    getrusage(RUSAGE_SELF, &usage);

    printf("cpu time %ld\n", usage.ru_ixrss);
        
    return 0;
}
