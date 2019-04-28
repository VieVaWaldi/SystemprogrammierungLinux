#include <stdio.h>
#include <unistd.h>

int main(void) {

    char *cwd = getcwd(NULL, 256);

    printf("%s\n", cwd);

    return 0;
}
