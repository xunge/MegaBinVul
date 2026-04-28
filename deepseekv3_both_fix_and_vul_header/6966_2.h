#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>
#include <errno.h>

#define NUT_MIN_VERSION 1
#define NUT_MAX_VERSION 4
#define NUT_MAX_STREAMS 256
#define FLAG_INVALID 0
#define MAIN_STARTCODE 0x7A561F5F04ADULL

#define AV_LOG_ERROR 16
#define AV_LOG_DEBUG 48
#define AVERROR(e) (-(e))
#define AVERROR_INVALIDDATA AVERROR(EINVAL)
#define ENOSYS 38
#define ENOMEM 12
#define EINVAL 22

typedef struct AVIOContext {
    uint8_t *buffer;
    int buffer_size;
    int eof_reached;
    void *opaque;
    int (*read_packet)(void *opaque, uint8_t *buf, int buf_size);
    int64_t (*seek)(void *opaque, int64_t offset, int whence);
    int64_t pos;
    int must_flush;
    int write_flag;
    int max_packet_size;
    int error;
    int (*write_packet)(void *opaque, uint8_t *buf, int buf_size);
    int (*read_pause)(void *opaque, int pause);
    int64_t (*read_seek)(void *opaque, int stream_index, int64_t timestamp, int flags);
    int seekable;
    int direct;
    int64_t bytes_read;
    int64_t bytes_written;
} AVIOContext;

typedef struct AVFormatContext {
    AVIOContext *pb;
} AVFormatContext;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct StreamContext {
    int dummy;
} StreamContext;

typedef struct NUTContext {
    AVFormatContext *avf;
    int version;
    int minor_version;
    unsigned int max_distance;
    unsigned int time_base_count;
    AVRational *time_base;
    struct {
        int flags;
        int pts_delta;
        int stream_id;
        int size_mul;
        int size_lsb;
        int reserved_count;
        int header_idx;
    } frame_code[256];
    int header_count;
    uint8_t *header[128];
    int header_len[128];
    int flags;
    StreamContext *stream;
} NUTContext;

#define GET_V(dst, check) \
    do { \
        tmp = ffio_read_varlen(bc); \
        if (!(check)) { \
            av_log(s, AV_LOG_ERROR, "invalid " #dst ": %"PRIu64"\n", tmp); \
            ret = AVERROR_INVALIDDATA; \
            goto fail; \
        } \
        dst = tmp; \
    } while (0)

static uint64_t get_packetheader(NUTContext *nut, AVIOContext *bc, int skip, uint64_t code);
static uint64_t ffio_read_varlen(AVIOContext *bc);
static int get_s(AVIOContext *bc);
static int skip_reserved(AVIOContext *bc, uint64_t pos);
static int ffio_get_checksum(AVIOContext *bc);
static void *av_malloc(size_t size);
static void *av_malloc_array(size_t nmemb, size_t size);
static void *av_calloc(size_t nmemb, size_t size);
static void av_freep(void *ptr);
static void av_log(void *avcl, int level, const char *fmt, ...);
static int avformat_new_stream(AVFormatContext *s, void *options);
static int64_t avio_tell(AVIOContext *s);
static int av_gcd(int a, int b);
static void av_assert0(int cond);
static int avio_read(AVIOContext *s, unsigned char *buf, int size);