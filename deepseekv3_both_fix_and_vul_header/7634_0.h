#include <stdio.h>
#include <string.h>

#define INDX_INFLBUF_SIZEMAX 4096

typedef enum {
    MOBI_SUCCESS,
    MOBI_DATA_CORRUPT
} MOBI_RET;

void debug_print(const char *format, ...);