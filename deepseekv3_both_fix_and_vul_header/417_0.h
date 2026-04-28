#include <stddef.h>

struct string_buf {
    unsigned char *data;
    unsigned char *dataptr;
    size_t len;
};