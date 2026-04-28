#include <stdlib.h>

#define REF_TABLE_SIZE 256

struct buf {
    size_t size;
    size_t asize;
    char *data;
};

struct link_ref {
    struct buf *label;
    struct buf *link;
    struct buf *title;
    struct link_ref *next;
};

void bufrelease(struct buf *);