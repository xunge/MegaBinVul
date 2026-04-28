#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <errno.h>

typedef struct AVIOContext AVIOContext;
typedef struct AVStream AVStream;
typedef struct MOVContext MOVContext;
typedef struct MOVAtom {
    uint32_t size;
    uint32_t type;
} MOVAtom;
typedef struct MOVStreamContext MOVStreamContext;
typedef struct MOVDref MOVDref;

struct AVFormatContext {
    unsigned int nb_streams;
    AVStream **streams;
};

struct AVStream {
    void *priv_data;
};

struct MOVContext {
    struct AVFormatContext *fc;
};

struct MOVDref {
    uint32_t type;
    char volume[28];
    char filename[64];
    int16_t nlvl_from;
    int16_t nlvl_to;
    char *path;
    char *dir;
};

struct MOVStreamContext {
    MOVDref *drefs;
    int drefs_count;
};

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define AVERROR(e) (-(e))
#define AVERROR_INVALIDDATA (-1094995529)
#define AVERROR_EOF (-541478725)
#define FFMIN(a,b) ((a) > (b) ? (b) : (a))
#define AV_LOG_DEBUG 0

static void av_free(void *ptr) { free(ptr); }
static void *av_malloc(size_t size) { return malloc(size); }
static void *av_mallocz(size_t size) { return calloc(1, size); }
static int url_feof(AVIOContext *s) { return 0; }
static int64_t avio_tell(AVIOContext *s) { return 0; }
static void avio_skip(AVIOContext *s, int64_t offset) {}
static uint32_t avio_rb32(AVIOContext *s) { return 0; }
static uint32_t avio_rl32(AVIOContext *s) { return 0; }
static uint16_t avio_rb16(AVIOContext *s) { return 0; }
static uint8_t avio_r8(AVIOContext *s) { return 0; }
static int avio_read(AVIOContext *s, void *buf, int size) { return 0; }
static int64_t avio_seek(AVIOContext *s, int64_t offset, int whence) { return 0; }
static void av_dlog(void *ctx, const char *fmt, ...) {}
static void av_log(void *ctx, int level, const char *fmt, ...) {}

#define SEEK_SET 0