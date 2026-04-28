#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct AVIOContext {
    int eof_reached;
} AVIOContext;

typedef struct AVDictionary AVDictionary;

typedef struct AVFormatContext {
    void *priv_data;
    AVIOContext *pb;
    AVDictionary *metadata;
} AVFormatContext;

typedef enum NSVState {
    NSV_UNSYNC,
    NSV_HAS_READ_NSVF
} NSVState;

typedef struct NSVContext {
    NSVState state;
    uint32_t NSVf_end;
    int64_t duration;
    int index_entries;
    uint32_t *nsvs_file_offset;
    uint32_t *nsvs_timestamps;
    int64_t base_offset;
} NSVContext;

#define av_unused
#define av_dlog(s, ...)
#define avio_rl32(pb) 0
#define avio_tell(pb) 0
#define avio_read(pb, buf, size) 0
#define avio_seek(pb, offset, whence) 0
#define av_malloc(size) malloc(size)
#define av_mallocz(size) calloc(1, size)
#define av_free(ptr) free(ptr)
#define av_dict_set(dict, key, value, flags) 0
#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((d) << 24))
#define PRId64 "lld"
#define AVERROR(e) (-(e))
#define ENOMEM 12