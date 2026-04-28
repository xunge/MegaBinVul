#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#define NSV_MAX_RESYNC_TRIES 10
#define NSV_ST_VIDEO 0
#define NSV_ST_AUDIO 1
#define AV_PKT_FLAG_KEY 0x0001
#define AVSTREAM_PARSE_NONE 0
#define CODEC_ID_PCM_U8 0x10000
#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define FFMIN(a,b) ((a) > (b) ? (b) : (a))
#define av_unused __attribute__((unused))

enum NSVState {
    NSV_UNSYNC,
    NSV_FOUND_NSVS,
    NSV_FOUND_BEEF,
    NSV_HAS_READ_NSVS
};

typedef struct AVPacket {
    uint8_t *data;
    int stream_index;
    int64_t dts;
    int flags;
} AVPacket;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct NSVStream {
    int frame_offset;
} NSVStream;

typedef struct AVCodecContext {
    unsigned int codec_tag;
    int codec_id;
    int channels;
    int sample_rate;
} AVCodecContext;

typedef struct AVStream {
    int id;
    int index;
    int need_parsing;
    AVCodecContext *codec;
    void *priv_data;
} AVStream;

typedef struct AVIOContext {
    int eof_reached;
} AVIOContext;

typedef struct AVFormatContext {
    void *priv_data;
    AVIOContext *pb;
    int nb_streams;
    AVStream **streams;
} AVFormatContext;

typedef struct NSVContext {
    enum NSVState state;
    AVPacket ahead[2];
    int avsync;
    AVRational framerate;
} NSVContext;

static inline int url_feof(AVIOContext *pb) {
    return pb->eof_reached;
}

static inline void av_dlog(void *s, const char *fmt, ...) {}

static inline uint8_t avio_r8(AVIOContext *pb) { return 0; }
static inline uint16_t avio_rl16(AVIOContext *pb) { return 0; }
static inline uint32_t avio_rl32(AVIOContext *pb) { return 0; }
static inline void avio_skip(AVIOContext *pb, int size) {}
static inline int av_get_packet(AVIOContext *pb, AVPacket *pkt, int size) { return 0; }
static inline int nsv_resync(AVFormatContext *s) { return 0; }
static inline int nsv_parse_NSVs_header(AVFormatContext *s, void *p) { return 0; }