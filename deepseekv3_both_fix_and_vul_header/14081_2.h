#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#define av_cold

typedef struct AVIOContext AVIOContext;
typedef struct AVStream AVStream;
typedef struct AVFormatContext AVFormatContext;
typedef struct AVCodecParameters AVCodecParameters;

struct AVStream {
    AVCodecParameters *codecpar;
};

struct AVFormatContext {
    AVIOContext *pb;
    AVStream **streams;
};

struct AVCodecParameters {
    int codec_type;
    int codec_id;
    int codec_tag;
    int width;
    int height;
    int extradata_size;
    int channels;
    int bits_per_coded_sample;
    int sample_rate;
    int bit_rate;
    int block_align;
};

enum AVMediaType {
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO
};

enum AVCodecID {
    AV_CODEC_ID_RL2,
    AV_CODEC_ID_PCM_U8
};

enum AVLogLevel {
    AV_LOG_ERROR
};

#define EXTRADATA1_SIZE 4
#define RLV3_TAG 0
#define AVINDEX_KEYFRAME 0

#define AVERROR_INVALIDDATA (-1)
#define AVERROR(ENOMEM) (-2)

static inline void avio_skip(AVIOContext *pb, int size) {}
static inline unsigned int avio_rl32(AVIOContext *pb) { return 0; }
static inline unsigned int avio_rb32(AVIOContext *pb) { return 0; }
static inline unsigned short avio_rl16(AVIOContext *pb) { return 0; }
static inline AVStream *avformat_new_stream(AVFormatContext *s, void *codec) { return NULL; }
static inline void avpriv_set_pts_info(AVStream *s, int pts_wrap_bits, int pts_num, int pts_den) {}
static inline void *av_malloc(size_t size) { return NULL; }
static inline void av_free(void *ptr) {}
static inline int ff_get_extradata(AVFormatContext *s, AVCodecParameters *par, AVIOContext *pb, int size) { return 0; }
static inline void av_add_index_entry(AVStream *st, int64_t pos, int64_t timestamp, int size, int distance, int flags) {}
static inline void av_log(AVFormatContext *s, int level, const char *fmt, ...) {}