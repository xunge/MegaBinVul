#include <stdlib.h>
#include <limits.h>

struct printbuf {
    char *buf;
    int size;
    int bpos;
};