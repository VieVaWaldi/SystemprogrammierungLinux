#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void) {

    struct rlimit limit; 
    if(getrlimit(RLIM_INFINITY, &limit) == 0) { printf("limerror"); exit(1); }
    printf("Limitcur: %ld\nLimitmax: %ld\n", limit.rlim_cur, limit.rlim_max);
 
    if(setrlimit(RLIM_INFINITY, &limit) == 0) { printf("limerror"); exit(1); }

    if(getrlimit(RLIM_INFINITY, &limit) == 0) { printf("limerror"); exit(1); }
    printf("Limitcur: %ld\nLimitmax: %ld\n", limit.rlim_cur, limit.rlim_max);
    
    return 1;
}
