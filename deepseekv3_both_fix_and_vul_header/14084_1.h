#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SEEK_SET 0

#define AVMEDIA_TYPE_VIDEO 0
#define AV_CODEC_ID_RAWVIDEO 0
#define AVERROR(e) (-(e))
#define ENOMEM 12
#define EINVAL 22
#define AVERROR_INVALIDDATA (-EINVAL)
#define AVINDEX_KEYFRAME 0
#define BMP_RGB 0
#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define CC_RGB 0
#define CC_UNINT 1
#define CC_LEAD 2
#define CFA_BAYER 0
#define CFA_BAYERFLIP 1
#define AV_DICT_DONT_STRDUP_VAL 0

enum AVPixelFormat {
    AV_PIX_FMT_GRAY8,
    AV_PIX_FMT_GRAY16LE,
    AV_PIX_FMT_BGR24,
    AV_PIX_FMT_BGR48LE,
    AV_PIX_FMT_BAYER_GBRG8,
    AV_PIX_FMT_BAYER_GBRG16LE,
    AV_PIX_FMT_BAYER_RGGB8,
    AV_PIX_FMT_BAYER_RGGB16LE
};

typedef struct AVCodecParameters {
    int codec_type;
    int codec_id;
    unsigned int codec_tag;
    int width;
    int height;
    int format;
    int bits_per_coded_sample;
    char *extradata;
    int extradata_size;
} AVCodecParameters;

typedef struct AVStream {
    AVCodecParameters *codecpar;
    int64_t duration;
    void *metadata;
} AVStream;

typedef struct AVFormatContext {
    void *pb;
} AVFormatContext;

typedef struct AVIOContext {
    int dummy;
} AVIOContext;

typedef struct AVDictionary {
    int dummy;
} AVDictionary;

static void *av_malloc(size_t size) { return malloc(size); }
static void av_free(void *ptr) { free(ptr); }
static char *av_strdup(const char *s) { return strdup(s); }
static void av_dict_set(AVDictionary **pm, const char *key, const char *value, int flags) {}
static void avpriv_set_pts_info(AVStream *st, int pts_wrap_bits, int pts_num, int pts_den) {}
static void avpriv_request_sample(AVFormatContext *avctx, const char *msg, ...) {}
static void set_metadata_int(AVDictionary **pm, const char *key, int value, int flags) {}
static void set_metadata_float(AVDictionary **pm, const char *key, float value, int flags) {}
static void av_add_index_entry(AVStream *st, int64_t pos, int64_t timestamp, int size, int distance, int flags) {}
static AVStream *avformat_new_stream(AVFormatContext *s, void *c) { return NULL; }
static unsigned int avio_rl16(AVIOContext *s) { return 0; }
static unsigned int avio_rl32(AVIOContext *s) { return 0; }
static uint64_t avio_rl64(AVIOContext *s) { return 0; }
static void avio_skip(AVIOContext *s, int64_t offset) {}
static void avio_seek(AVIOContext *s, int64_t offset, int whence) {}
static uint64_t avio_get_str(AVIOContext *pb, int maxlen, char *buf, int buflen) { return 0; }
static float av_int2float(int32_t i) { union { int32_t i; float f; } u; u.i = i; return u.f; }