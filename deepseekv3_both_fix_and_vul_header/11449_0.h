#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;

typedef struct sc_file {
    u8 *sec_attr;
    size_t sec_attr_len;
} sc_file_t;

#define SC_ERROR_INVALID_ARGUMENTS 1
#define SC_ERROR_OUT_OF_MEMORY 2

static inline int sc_file_valid(sc_file_t *file) {
    return file != NULL;
}