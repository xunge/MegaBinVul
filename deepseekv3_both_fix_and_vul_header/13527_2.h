#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef enum {
    GF_OK,
    GF_OUT_OF_MEM
} GF_Err;

typedef struct {
    char *buffer;
    uint32_t line_size;
    uint32_t alloc_size;
} GF_SAXParser;

#define u32 uint32_t

void *gf_realloc(void *ptr, size_t size);