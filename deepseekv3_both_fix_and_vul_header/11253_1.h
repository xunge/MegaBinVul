#include <stdint.h>
#include <stdlib.h>

#define AV_NOPTS_VALUE          ((int64_t)UINT64_C(0x8000000000000000))
#define PVA_MAGIC               0x41565024
#define PVA_VIDEO_PAYLOAD       0x01
#define PVA_AUDIO_PAYLOAD       0x02
#define PVA_MAX_PAYLOAD_LENGTH  65535
#define AVINDEX_KEYFRAME        0

typedef struct AVFormatContext {
    struct AVIOContext *pb;
    struct AVStream **streams;
    void *priv_data;
} AVFormatContext;

typedef struct AVIOContext {
    int dummy;
} AVIOContext;

typedef struct PVAContext {
    int continue_pes;
} PVAContext;

typedef struct AVStream {
    int dummy;
} AVStream;

enum AVLogLevel {
    AV_LOG_ERROR,
    AV_LOG_WARNING
};

#define AVERROR_EOF            (-541478725)
#define AVERROR(EIO)           (-5)
#define AVERROR_INVALIDDATA    (-1094995529)

static int avio_rb16(struct AVIOContext *s);
static int avio_r8(struct AVIOContext *s);
static int avio_rb24(struct AVIOContext *s);
static int avio_rb32(struct AVIOContext *s);
static int64_t avio_tell(struct AVIOContext *s);
static int avio_feof(struct AVIOContext *s);
static void avio_skip(struct AVIOContext *s, int size);
static int avio_read(struct AVIOContext *s, unsigned char *buf, int size);
static void pva_log(AVFormatContext *s, int level, const char *fmt, ...);
static int64_t ff_parse_pes_pts(unsigned char *buf);
static void av_add_index_entry(AVStream *st, int64_t pos, int64_t timestamp, int size, int distance, int flags);