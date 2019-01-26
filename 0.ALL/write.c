#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define DIR "fuck/"

int main(int argc, char *argv[]) {
    
    for(int i=0; i<200; i++) {

        char *num = (char*) malloc(sizeof(char));
        char *file = "file";
        char *newfile;
        
        sprintf(num, "%d", i);

        strcat(newfile, DIR);
        strcat(newfile, file);
        strcat(newfile, num);

        printf("%s %s %s\n",num, file, newfile );

        int ch = open(newfile, O_RDWR|O_CREAT, 751);       

        char *buf = "lol";

        // write(ch, buf, sizeof(buf));
        free(num);
        close(ch);
   
        newfile = "";
    }

    printf("Job DOne!\n");
        
    return EXIT_SUCCESS;
}
