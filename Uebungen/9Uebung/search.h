#ifndef SEARCH_H_
#define SEARCH_H_

#include <sys/stat.h>

int traverse(const char *pfad, const struct stat *fstat, int typeflags );
int searchFile(char *dir, char *file);

#endif
