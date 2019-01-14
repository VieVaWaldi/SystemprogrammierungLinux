#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <error.h>

void printPermissions(char *file, struct stat);

int main(int argc, char **argv) {

    if(argc < 3) error(1, errno, "2 Dateien erforderlich.");

    char *file1 = argv[1];
    char *file2 = argv[2];

    int fd1;
    int fd2;

    struct stat fstat1;
    struct stat fstat2;

    if(stat(file1, &fstat1) < 0) 
        error(2, errno, "Datei kann nicht geoeffnet werden.");
    if(stat(file2, &fstat2) < 0) 
        error(3, errno, "Datei kann nicht geoeffnet werden.");
    printPermissions(file1, fstat1);
    printPermissions(file2, fstat2);


    if((fd1 = open(file1, O_RDWR | O_CREAT, fstat1.st_mode & 7777 )) < 0)
        error(4, errno, "Datei kann nicht geoeffnet werden.");
    if((fd2 = creat(file2, O_RDWR)) < 0)
        error(5, errno, "Datei kann nicht geoeffnet werden.");

    const char *text = "NewLine";

    write(fd1, text, 5);
    write(fd2, text, 7);
    

    if(stat(file1, &fstat1) < 0) 
        error(5, errno, "Datei kann nicht geoeffnet werden.");
    if(stat(file2, &fstat2) < 0) 
        error(6, errno, "Datei kann nicht geoeffnet werden.");
    printPermissions(file1, fstat1);
    printPermissions(file2, fstat2);
    
    close(fd1);
    close(fd2);
    
    return EXIT_SUCCESS;
}


void printPermissions(char *file, struct stat fstat) {

    printf("%s's Rechte sind: \t", file);
    printf( (S_ISDIR(fstat.st_mode)) ? "d" : "-");
    
    printf( (fstat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fstat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fstat.st_mode & S_IXUSR) ? "x" : "-");
    
    printf( (fstat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fstat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fstat.st_mode & S_IXGRP) ? "x" : "-");
    
    printf( (fstat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fstat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fstat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}
