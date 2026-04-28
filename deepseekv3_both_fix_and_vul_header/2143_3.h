#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define CONFIG_DV_DEMUXER 1
#define AVERROR_EOF 1
#define AVSEEK_FLAG_ANY 0
#define AVSEEK_FLAG_BACKWARD 1
#define AV_PKT_FLAG_KEY 1
#define AV_PKT_DATA_PALETTE 1
#define AVPALETTE_SIZE 1024
#define AV_TIME_BASE 1000000
#define CODEC_ID_MPEG4 1
#define AVMEDIA_TYPE_VIDEO 0
#define AVMEDIA_TYPE_SUBTITLE 2
#define AVINDEX_KEYFRAME 1
#define AV_LOG_ERROR 16
#define AV_LOG_INFO 24
#define SEEK_SET 0

typedef struct AVIOContext AVIOContext;
typedef struct AVStream AVStream;
typedef struct AVIndexEntry AVIndexEntry;
typedef struct AVRational AVRational;
typedef struct AVIContext AVIContext;
typedef struct AVIStream AVIStream;
typedef struct AVPacket AVPacket;
typedef struct AVFormatContext AVFormatContext;

struct AVRational {
    int num;
    int den;
};

struct AVIndexEntry {
    int64_t pos;
    int64_t timestamp;
    int flags;
    int size;
};

struct AVPacket {
    uint8_t *data;
    int size;
    int64_t dts;
    int64_t pos;
    int flags;
    int stream_index;
    void *destruct;
};

struct AVStream {
    void *priv_data;
    int nb_index_entries;
    AVIndexEntry *index_entries;
    AVRational time_base;
    struct {
        int codec_type;
        int codec_id;
        int codec_tag;
    } *codec;
};

struct AVIContext {
    void *dv_demux;
    int non_interleaved;
    int stream_index;
    int64_t last_pkt_pos;
    int index_loaded;
    int64_t dts_max;
};

struct AVIStream {
    int64_t frame_offset;
    int remaining;
    int sample_size;
    int has_pal;
    uint8_t pal[AVPALETTE_SIZE];
    int packet_size;
    int64_t seek_pos;
};

struct AVFormatContext {
    AVIContext *priv_data;
    AVIOContext *pb;
    int nb_streams;
    AVStream **streams;
};

static const AVRational AV_TIME_BASE_Q = {1, AV_TIME_BASE};

static inline int FFMAX(int a, int b) { return a > b ? a : b; }
static inline int FFMIN(int a, int b) { return a < b ? a : b; }

static int avpriv_dv_get_packet(void *dv_demux, AVPacket *pkt) { return 0; }
static int avpriv_dv_produce_packet(void *dv_demux, AVPacket *pkt, uint8_t *data, int size, int pos) { return 0; }
static int get_subtitle_pkt(AVFormatContext *s, AVStream *st, AVPacket *pkt) { return 0; }
static int read_gab2_sub(AVStream *st, AVPacket *pkt) { return 0; }
static int get_duration(AVIStream *ast, int size) { return 0; }
static int avi_sync(AVFormatContext *s, int flags) { return 0; }
static int64_t av_rescale_q(int64_t a, AVRational bq, AVRational cq) { return 0; }
static int64_t avio_tell(AVIOContext *pb) { return 0; }
static int av_get_packet(AVIOContext *pb, AVPacket *pkt, int size) { return 0; }
static int av_index_search_timestamp(AVStream *st, int64_t timestamp, int flags) { return 0; }
static int64_t avio_seek(AVIOContext *pb, int64_t offset, int whence) { return 0; }
static void av_free_packet(AVPacket *pkt) {}
static uint8_t *av_packet_new_side_data(AVPacket *pkt, int type, int size) { return NULL; }
static void av_log(AVFormatContext *s, int level, const char *fmt, ...) {}