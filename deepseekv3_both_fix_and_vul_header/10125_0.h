#include <assert.h>
#include <string.h>
#include <stddef.h>

typedef struct jas_stream_obj_s jas_stream_obj_t;
typedef struct jas_stream_memobj_s jas_stream_memobj_t;

#define JAS_DBGLOG(level, msg)
#define JAS_MIN(a, b) ((a) < (b) ? (a) : (b))
#define JAS_CAST(type, val) ((type)(val))

struct jas_stream_memobj_s {
    long pos_;
    long len_;
    long bufsize_;
    int growable_;
    char *buf_;
};

static int mem_resize(jas_stream_memobj_t *m, long newbufsize);