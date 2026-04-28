#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define AV_LOG_TRACE 0
#define AV_LOG_ERROR 0
#define PRId64 "lld"
#define UINT_MAX 0xFFFFFFFF
#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))

typedef struct AVFormatContext {
    void *priv_data;
    void *pb;
    void *metadata;
} AVFormatContext;

typedef struct AVIOContext {
} AVIOContext;

typedef struct NSVContext {
    int state;
    uint32_t NSVf_end;
    int64_t duration;
    int index_entries;
    uint32_t *nsvs_file_offset;
    uint32_t *nsvs_timestamps;
    int64_t base_offset;
} NSVContext;

enum {
    NSV_UNSYNC,
    NSV_HAS_READ_NSVF
};

#define av_unused
#define avio_rl32(pb) 0
#define avio_feof(pb) 0
#define avio_tell(pb) 0
#define avio_read(pb, buf, size) 0
#define avio_seek(pb, offset, whence) 0
#define av_log(s, level, fmt, ...) 
#define av_mallocz(size) calloc(1, size)
#define av_malloc_array(n, size) malloc((n) * (size))
#define av_free(ptr) free(ptr)
#define av_dict_set(metadata, key, value, flags) 
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define AVERROR_INVALIDDATA (-1)