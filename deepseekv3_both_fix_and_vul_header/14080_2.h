#include <stdint.h>
#include <stdlib.h>

#define AV_LOG_ERROR 16
#define AVERROR_INVALIDDATA (-1)
#define AVERROR_PATCHWELCOME (-2)
#define AVERROR(ENOMEM) (-3)
#define AUDIO_FORMAT_SIGNED 1

#define AVMEDIA_TYPE_VIDEO 0
#define AVMEDIA_TYPE_AUDIO 1

#define AV_CODEC_ID_MVC1 0x100
#define AV_CODEC_ID_RAWVIDEO 0x101
#define AV_CODEC_ID_PCM_S16BE 0x102
#define AV_CODEC_ID_NONE 0x103

#define AV_PIX_FMT_ARGB 0x200
#define AVINDEX_KEYFRAME 0x300

typedef struct AVFormatContext AVFormatContext;
typedef struct AVIOContext AVIOContext;
typedef struct AVStream AVStream;
typedef struct MvContext MvContext;
typedef struct AVRational {
    int num;
    int den;
} AVRational;

struct AVFormatContext {
    MvContext *priv_data;
    AVIOContext *pb;
};

struct AVIOContext {
    // Minimal definition for compilation
};

struct AVStream {
    int nb_frames;
    AVRational time_base;
    AVRational avg_frame_rate;
    struct {
        int codec_type;
        int codec_id;
        int format;
        int width;
        int height;
        int sample_rate;
        int channels;
        int bits_per_coded_sample;
        int codec_tag;
    } *codecpar;
};

struct MvContext {
    int nb_audio_tracks;
    int nb_video_tracks;
    int acompression;
    int aformat;
};

static void avio_skip(AVIOContext *pb, int n) {}
static uint16_t avio_rb16(AVIOContext *pb) { return 0; }
static uint32_t avio_rb32(AVIOContext *pb) { return 0; }
static AVStream *avformat_new_stream(AVFormatContext *s, void *codec) { return NULL; }
static void avpriv_set_pts_info(AVStream *s, int pts_wrap_bits, int pts_num, int pts_den) {}
static void av_log(AVFormatContext *avctx, int level, const char *fmt, ...) {}
static void avpriv_request_sample(AVFormatContext *avctx, const char *fmt, ...) {}
static void av_add_index_entry(AVStream *st, uint32_t pos, uint64_t timestamp, uint32_t size, int distance, int flags) {}
static int set_channels(AVFormatContext *avctx, AVStream *ast, int channels) { return 0; }
static int var_read_metadata(AVFormatContext *avctx, const char *name, int size) { return 0; }
static int read_table(AVFormatContext *avctx, AVStream *st, int (*parse)(AVFormatContext *, AVStream *, const char *, const char *)) { return 0; }
static int parse_global_var(AVFormatContext *avctx, AVStream *st, const char *name, const char *value) { return 0; }
static int parse_audio_var(AVFormatContext *avctx, AVStream *st, const char *name, const char *value) { return 0; }
static int parse_video_var(AVFormatContext *avctx, AVStream *st, const char *name, const char *value) { return 0; }
static void read_index(AVIOContext *pb, AVStream *st) {}
static AVRational av_inv_q(AVRational q) { return (AVRational){q.den, q.num}; }