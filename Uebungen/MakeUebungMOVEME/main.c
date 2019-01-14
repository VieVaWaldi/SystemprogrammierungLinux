#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char *argv[])
{
      int width = 15, precision = 4, len, written = 0;
      char mem[] = {0101, 0102, 0103, 0104, 0105, 0106, 0107, 00}, byte = 0xFF;

      printf("%3$*1$.*2$d, %3$*1$.*2$u, %3$#*1$.*2$x, %3$#*1$.*2$X, %3$*1$.*2$i\n  %4$n", width,
            precision, byte, &len);
      written += len;
      
      printf("%2$*1$s, %3$*1$c, %3$0*1$d\n%4$n", width, mem, *mem, &len);
      written += len;
      
      float num = 0.4F;
     
      printf("%3$0*1$.*2$f, %3$0*1$.*2$g, %3$0#*1$.*2$lf, %3$0#*1$.*2$e\n%4$n", 
            width, precision, num, &len);
      written += len;
      
      printf("written: %d\n", written);
      
      return EXIT_SUCCESS;
}
