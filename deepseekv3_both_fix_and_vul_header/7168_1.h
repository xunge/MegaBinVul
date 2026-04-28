#include <stddef.h>

struct LibRaw_buffer_datastream {
    unsigned char *buf;
    size_t streampos;
    size_t streamsize;
    char *gets(char *s, int sz);
};