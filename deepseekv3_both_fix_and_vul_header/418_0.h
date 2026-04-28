#include <stddef.h>

struct string_buf {
    size_t len;
    unsigned char *data;
    unsigned char *dataptr;
};