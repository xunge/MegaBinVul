#include <stdio.h>
#include <stdlib.h>

typedef struct jas_stream_obj_s jas_stream_obj_t;
typedef struct jas_stream_memobj_s jas_stream_memobj_t;

struct jas_stream_memobj_s {
    long len_;
    long pos_;
};

#define JAS_DBGLOG(level, msg)