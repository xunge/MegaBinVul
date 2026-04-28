#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct buffer {
    void *data;
    int refs;
};

struct slice {
    struct buffer *buffer;
};

struct command {
    struct slice slice;
    int64_t offset;
};