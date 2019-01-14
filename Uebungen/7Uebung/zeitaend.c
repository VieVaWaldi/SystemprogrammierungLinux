#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <utime.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <error.h>
#include <getopt.h>

#define MINUTES_TO_SECONDS(m) ((m)*60)
#define HOURS_TO_SECONDS(m) ((m)*60*60)
#define DAYS_TO_SECONDS(m) ((m)*24*60*60)

struct option long_opt[] = { 
    {"file", required_argument, NULL, 'f'},
    {"day", required_argument, NULL, 'd'},
    {"hour", required_argument, NULL, 'h'},
    {"minute", required_argument, NULL, 'm'},
    {"second", required_argument, NULL, 's'},
    {NULL, no_argument, NULL, 0}
};

int main(int argc, char ** argv) {

    if(argc < 2) error(1, errno, "Dateiname erforderlich");

    char *short_opt = "f:d:h:m:s:";
    int ch;

    int fd = -1;
    char *file;
    struct stat fstat;
    int d=0, h=0, m=0, s=0;
    int tmp;

    while((ch = getopt_long(argc, argv, short_opt, long_opt, NULL)) != -1) {

        switch(ch) {
            case 'f':
                if(optarg == NULL) error(2, errno, "Cant open file");
                file = optarg; 
                if((fd = open(file, O_RDWR)) == -1) error(2, errno, "Cant open file"); 
                break;
            case 'd':
                if(optarg == NULL) error(3, errno, "Number exception.");
                tmp = atoi(optarg);
                d = tmp;
                break;
            case 'h':
                if(optarg == NULL) error(3, errno, "Number exception.");
                tmp = atoi(optarg);
                if(tmp < 1 || 24 < tmp) error(4, errno, "Format exception: hour");
                h = tmp;
                break;
            case 'm':
                if(optarg == NULL) error(3, errno, "Number exception.");
                tmp = atoi(optarg);
                if(tmp < 1 || 59 < tmp) error(4, errno, "Format exception: minute");
                m = tmp;
                break;
            case 's':
                if(optarg == NULL) error(3, errno, "Number exception.");
                tmp = atoi(optarg);
                if(tmp < 1 || 59 < tmp) error(4, errno, "Format exception: second");
                s = tmp;
                break;
        }
    }



    if(stat(file, &fstat) < 0) error(5, errno, "Stat exception");

    printf("Alte Zeit von %s:\n\t%s\t%s", file, ctime(&fstat.st_mtime), ctime(&fstat.st_atime));

    if(fd == -1) error(1, errno, "Dateiname erforderlich"); 
    if(stat(file, &fstat) < 0) error(5, errno, "Stat exception");
    
    struct utimbuf ftime;

    time_t newTime = time(NULL) + DAYS_TO_SECONDS(d) + HOURS_TO_SECONDS(h) + MINUTES_TO_SECONDS(m) + s;

    ftime.actime = newTime;
    ftime.modtime = newTime;

    if(utime(file, &ftime) == -1) error(5, errno, "Time exception");
    if(stat(file, &fstat) < 0) error(5, errno, "Stat exception");

    printf("Neue Zeit von: %s:\n\t%s\t%s", file, ctime(&fstat.st_mtime), ctime(&fstat.st_atime));

    return EXIT_SUCCESS;
}
