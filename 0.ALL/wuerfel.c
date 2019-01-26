#include "myhead.h"
#include <getopt.h>

struct param {
  unsigned int anz;
  int min;
  int max;
} myparam;

int main(int argc, char *argv[])
{

  myparam.anz = 1;
  myparam.min = 1;
  myparam.max = 6;

  struct option longopts[] = {{"min", required_argument, NULL, 'a'}, {"max", required_argument, NULL, 'b'}, {0}};

  char opt;
  while( (opt = getopt_long_only(argc, argv, ":a:b:", longopts, NULL)) > 0)
  {
    switch(opt)
    {
    case 'a':
      if( optarg ) myparam.min = atoi(optarg);
      break;
    case 'b':
      if( optarg ) myparam.max = atoi(optarg);
    }
  }
  if( optind < argc ) myparam.anz = atoi(argv[optind]);
  

  int fd = open("/dev/urandom", O_RDONLY);

  if( fd < 0 ) perror("failed to open /dev/urandom");

  unsigned int val;
  int i = 0;
  while( i++ < myparam.anz )
  {
    if( read(fd, &val, sizeof(int)) != sizeof(int) ) perror("read");
    val = val % (myparam.max - myparam.min +1) +myparam.min;
    printf("%d\n", val);
  }
  
  close(fd);
 
  return EXIT_SUCCESS;
}

