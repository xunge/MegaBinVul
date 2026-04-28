#include <stdlib.h>
#include <stdbool.h>

typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_MP4MuxCtx GF_MP4MuxCtx;
typedef struct TrackWriter TrackWriter;
typedef enum {
    GF_OK,
    GF_TRUE
} GF_Err;

#define Bool bool

struct GF_MP4MuxCtx {
    void *tracks;
    TrackWriter *ref_tkw;
    GF_FilterPid *opid;
    void *file;
    bool init_movie_done;
    unsigned int flush_size;
};