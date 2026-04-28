#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define MKBETAG(a,b,c,d) ((d) | ((c) << 8) | ((b) << 16) | ((unsigned)(a) << 24))

#define AV_LOG_DEBUG 0
#define AVERROR_INVALIDDATA -1
#define AVERROR(ENOMEM) -2
#define ENOMEM 1
#define SEEK_CUR 1

typedef struct AVIOContext {
    // Minimal fields needed for compilation
    void *opaque;
} AVIOContext;

typedef struct AVStream {
    void *priv_data;
    int64_t duration;
} AVStream;

typedef struct AVFormatContext {
    AVIOContext *pb;
} AVFormatContext;

static void av_log(AVFormatContext *s, int level, const char *fmt, ...) {}
static int64_t avio_tell(AVIOContext *pb) { return 0; }
static unsigned avio_rl32(AVIOContext *pb) { return 0; }
static unsigned avio_rb16(AVIOContext *pb) { return 0; }
static unsigned avio_r8(AVIOContext *pb) { return 0; }
static unsigned avio_rb32(AVIOContext *pb) { return 0; }
static void avio_skip(AVIOContext *pb, int64_t offset) {}
static int avio_feof(AVIOContext *pb) { return 0; }
static int64_t avio_rb64(AVIOContext *pb) { return 0; }
static int avio_get_str(AVIOContext *pb, int maxlen, char *buf, int buflen) { return 0; }
static AVStream *avformat_new_stream(AVFormatContext *s, void *codec) { return NULL; }
static void *ff_rm_alloc_rmstream(void) { return NULL; }
static int ffio_ensure_seekback(AVIOContext *pb, int64_t len) { return 0; }
static void avio_seek(AVIOContext *pb, int64_t offset, int whence) {}
static int rm_read_multi(AVFormatContext *s, AVIOContext *pb, AVStream *st, void *arg) { return 0; }
static int ff_rm_read_mdpr_codecdata(AVFormatContext *s, AVIOContext *pb, AVStream *st, void *priv_data, int len, void *arg) { return 0; }