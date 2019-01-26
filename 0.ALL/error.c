#include <stdio.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char ** argv) {

    printf("In line: %d\n", __LINE__);
    perror("Perror: Error");
    error_at_line(1, errno, __FILE__, __LINE__, "Errormessage");

    printf("Job Done!");
    
    return EXIT_SUCCESS;
}
