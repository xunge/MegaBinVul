#include <stdlib.h>
#include <assert.h>

typedef struct {
    unsigned char *buf_;
    int bufsize_;
} jas_stream_memobj_t;

#define JAS_DBGLOG(level, msg)