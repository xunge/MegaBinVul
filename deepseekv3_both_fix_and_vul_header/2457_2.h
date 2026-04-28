#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

typedef struct AVIOContext {
    // Minimal fields needed for compilation
    int dummy;
} AVIOContext;

typedef struct AVStream {
    // Minimal fields needed for compilation
    int dummy;
} AVStream;

typedef struct AVFormatInternal {
    int64_t data_offset;
} AVFormatInternal;

typedef struct AVFormatContext {
    AVIOContext *pb;
    void *priv_data;
    AVStream **streams;
    int packet_size;
    AVFormatInternal *internal;
} AVFormatContext;

typedef struct ASFContext {
    int64_t data_object_offset;
    int64_t data_object_size;
    int index_read;
    struct {
        int64_t preroll;
    } hdr;
} ASFContext;

typedef struct ff_asf_guid {
    uint8_t data[16];
} ff_asf_guid;

#define AV_LOG_DEBUG 0
#define AVERROR_INVALIDDATA 1
#define AVINDEX_KEYFRAME 0
#define SEEK_SET 0

extern const ff_asf_guid ff_asf_simple_index_header;

int64_t avio_tell(AVIOContext *s);
int64_t avio_seek(AVIOContext *s, int64_t offset, int whence);
int ff_get_guid(AVIOContext *s, ff_asf_guid *g);
int ff_guidcmp(const ff_asf_guid *g1, const ff_asf_guid *g2);
int64_t avio_rl64(AVIOContext *s);
int avio_feof(AVIOContext *s);
void avio_skip(AVIOContext *s, int64_t offset);
int avio_rl32(AVIOContext *s);
int avio_rl16(AVIOContext *s);
void av_log(void* avcl, int level, const char *fmt, ...);
int64_t av_rescale(int64_t a, int64_t b, int64_t c);
void av_add_index_entry(AVStream *st, int64_t pos, int64_t timestamp,
                        int size, int distance, int flags);

#define FFMAX(a,b) ((a) > (b) ? (a) : (b))
#define av_unused __attribute__((unused))