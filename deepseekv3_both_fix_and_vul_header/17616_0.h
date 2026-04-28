#include <string.h>
#include <limits.h>

struct printbuf {
    char *buf;
    int size;
    int bpos;
};

int printbuf_extend(struct printbuf *pb, int size_needed);