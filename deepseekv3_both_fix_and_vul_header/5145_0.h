#include <stdlib.h>
#include <string.h>

struct buffer_st {
    char *data;
    size_t size;
    size_t offset;
};

void buffer_new(struct buffer_st *b);
void buffer_add(struct buffer_st *b, char c);

static char dtable[64];