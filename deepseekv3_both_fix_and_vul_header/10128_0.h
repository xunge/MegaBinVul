#include <assert.h>
#include <string.h>
#include <unistd.h>

typedef struct jas_stream_obj_t jas_stream_obj_t;
typedef struct jas_stream_memobj_t {
    int len_;
    int pos_;
    char *buf_;
} jas_stream_memobj_t;

#define JAS_MIN(a, b) ((a) < (b) ? (a) : (b))
#define JAS_DBGLOG(level, msg)