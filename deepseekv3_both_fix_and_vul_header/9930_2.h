#include <stdint.h>
#include <limits.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>

#define MKTAG(a,b,c,d) ((a) | ((b) << 8) | ((c) << 16) | ((unsigned)(d) << 24))
#define APE_MIN_VERSION 3950
#define APE_MAX_VERSION 3990
#define MAC_FORMAT_FLAG_HAS_PEAK_LEVEL 1
#define MAC_FORMAT_FLAG_HAS_SEEK_ELEMENTS 2
#define MAC_FORMAT_FLAG_8_BIT 4
#define MAC_FORMAT_FLAG_24_BIT 8
#define MAC_FORMAT_FLAG_CREATE_WAV_HEADER 16
#define MAC_SUBFRAME_SIZE 4608
#define APE_EXTRADATA_SIZE 6
#define AV_LOG_ERROR 16
#define AV_LOG_DEBUG 48
#define SEEK_SET 0
#define SEEK_CUR 1
#define AVMEDIA_TYPE_AUDIO 1
#define CODEC_ID_APE 0x617065
#define AVINDEX_KEYFRAME 0
#define EINVAL 22
#define ENOMEM 12

typedef struct AVIOContext {
    int dummy;
} AVIOContext;

typedef struct AVFormatContext {
    AVIOContext *pb;
    void *priv_data;
} AVFormatContext;

typedef struct AVStream {
    struct AVCodecContext *codec;
    int nb_frames;
    int64_t start_time;
    int64_t duration;
} AVStream;

typedef struct AVFormatParameters {
    int dummy; 
} AVFormatParameters;

typedef struct AVCodecContext {
    int codec_type;
    int codec_id;
    int codec_tag;
    int channels;
    int sample_rate;
    int bits_per_coded_sample;
    int frame_size;
    uint8_t *extradata;
    int extradata_size;
} AVCodecContext;

typedef struct APEContext {
    int junklength;
    int fileversion;
    int padding1;
    int descriptorlength;
    int headerlength;
    int seektablelength;
    int wavheaderlength;
    int audiodatalength;
    int audiodatalength_high;
    int wavtaillength;
    uint8_t md5[16];
    int compressiontype;
    int formatflags;
    int blocksperframe;
    int finalframeblocks;
    int totalframes;
    int bps;
    int channels;
    int samplerate;
    uint32_t *seektable;
    struct APEFrame *frames;
    int64_t firstframe;
    int currentframe;
    int64_t totalsamples;
} APEContext;

typedef struct APEFrame {
    int64_t pos;
    int size;
    int nblocks;
    int skip;
    int64_t pts;
} APEFrame;

static uint32_t avio_rl32(AVIOContext *pb) { return 0; }
static uint16_t avio_rl16(AVIOContext *pb) { return 0; }
static int avio_read(AVIOContext *pb, uint8_t *buf, int size) { return 0; }
static int64_t avio_seek(AVIOContext *pb, int64_t offset, int whence) { return 0; }
static void av_log(AVFormatContext *s, int level, const char *fmt, ...) {}
static void *av_malloc(size_t size) { return malloc(size); }
static AVStream *av_new_stream(AVFormatContext *s, int id) { return NULL; }
static void av_set_pts_info(AVStream *s, int pts_num, int pts_den, int pts_reduction) {}
static void av_add_index_entry(AVStream *s, int64_t pos, int64_t timestamp, int size, int distance, int flags) {}
static void AV_WL16(uint8_t *p, uint16_t v) {}
static int url_is_streamed(AVIOContext *pb) { return 0; }
static void ape_dumpinfo(AVFormatContext *s, APEContext *ape) {}
static void ff_ape_parse_tag(AVFormatContext *s) {}
static int AVERROR(int err) { return -err; }