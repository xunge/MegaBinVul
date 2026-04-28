#include <assert.h>
#include <stdlib.h>

typedef struct {
    unsigned char *buf_;
    int bufsize_;
} jas_stream_memobj_t;

void *jas_realloc2(void *ptr, size_t num, size_t size);