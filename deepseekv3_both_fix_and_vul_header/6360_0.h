#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    size_t offset;
    size_t maxlen;
    int error;
} MOBIBuffer;

#define MOBI_BUFFER_END 1

extern void debug_print(const char *format, ...);