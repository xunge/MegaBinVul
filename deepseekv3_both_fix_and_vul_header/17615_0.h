#include <limits.h>
#include <string.h>

struct printbuf {
    char *buf;
    int size;
    int bpos;
};

int printbuf_extend(struct printbuf *p, int new_size);