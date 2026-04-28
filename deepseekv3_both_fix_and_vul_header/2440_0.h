#include <stdint.h>
#include <stdlib.h>

typedef struct AVIOContext AVIOContext;

typedef struct MXFIndexTableSegment {
    int nb_index_entries;
    int8_t *temporal_offset_entries;
    int8_t *flag_entries;
    int64_t *stream_offset_entries;
} MXFIndexTableSegment;

#define AVERROR_INVALIDDATA (-1)
#define AVERROR(ENOMEM) (-2)

int avio_rb32(AVIOContext *pb);
int8_t avio_r8(AVIOContext *pb);
int64_t avio_rb64(AVIOContext *pb);
void avio_skip(AVIOContext *pb, int len);
int avio_feof(AVIOContext *pb);
void *av_calloc(size_t nmemb, size_t size);
void av_freep(void *ptr);