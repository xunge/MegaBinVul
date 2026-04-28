#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

#define NSV_MAX_RESYNC_TRIES 10
#define NSV_UNSYNC 0
#define NSV_FOUND_NSVS 1
#define NSV_HAS_READ_NSVS 2
#define NSV_FOUND_BEEF 3
#define NSV_ST_VIDEO 0
#define NSV_ST_AUDIO 1
#define AVERROR_INVALIDDATA -1
#define AV_CODEC_ID_PCM_U8 0x10000
#define AVSTREAM_PARSE_NONE 0
#define AV_PKT_FLAG_KEY 0x0001
#define AV_LOG_TRACE 56

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define FFMIN(a,b) ((a) > (b) ? (b) : (a))

typedef struct AVPacket {
    uint8_t *data;
    int stream_index;
    int64_t dts;
    int flags;
} AVPacket;

typedef struct AVCodecParameters {
    unsigned int codec_tag;
    int codec_id;
    int channels;
    int sample_rate;
} AVCodecParameters;

typedef struct NSVStream {
    int frame_offset;
} NSVStream;

typedef struct AVStream {
    int id;
    int index;
    void *priv_data;
    AVCodecParameters *codecpar;
    int need_parsing;
} AVStream;

typedef struct AVIOContext {
    int eof_reached;
} AVIOContext;

typedef struct NSVContext {
    int state;
    AVPacket ahead[2];
    int avsync;
    struct {
        int num;
        int den;
    } framerate;
} NSVContext;

typedef struct AVFormatContext {
    NSVContext *priv_data;
    AVIOContext *pb;
    int nb_streams;
    AVStream **streams;
} AVFormatContext;

static int nsv_resync(AVFormatContext *s) { return 0; }
static int nsv_parse_NSVs_header(AVFormatContext *s) { return 0; }

#define av_unused
#define avio_r8(pb) 0
#define avio_rl16(pb) 0
#define avio_rl32(pb) 0
#define avio_skip(pb, size)
#define av_get_packet(pb, pkt, size) 0
#define av_log(s, level, fmt, ...)