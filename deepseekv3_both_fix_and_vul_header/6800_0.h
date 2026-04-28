#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define PATH_MAX 4096

char *uwsgi_malloc(int size);
void uwsgi_error_realpath(char *path);