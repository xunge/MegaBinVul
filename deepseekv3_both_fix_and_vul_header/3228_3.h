#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#define attribute_align_arg

typedef struct AVCodecContext AVCodecContext;
typedef struct AVFrame AVFrame;
typedef struct AVPacket AVPacket;
typedef struct AVCodec AVCodec;

typedef struct AVRational {
    int num;
    int den;
} AVRational;

struct AVCodecContext {
    AVCodec *codec;
    int sample_fmt;
    uint64_t channel_layout;
    int channels;
    int sample_rate;
    struct {
        int skip_samples;
    } *internal;
    AVPacket *pkt;
    AVRational pkt_timebase;
    int frame_number;
};

struct AVFrame {
    uint8_t **data;
    uint8_t **extended_data;
    int format;
    uint64_t channel_layout;
    int channels;
    int sample_rate;
    int nb_samples;
    int64_t pkt_pts;
    int64_t pkt_dts;
    int64_t best_effort_timestamp;
    int64_t pkt_duration;
};

struct AVPacket {
    uint8_t *data;
    int size;
    int64_t dts;
};

struct AVCodec {
    int type;
    int capabilities;
    int (*decode)(AVCodecContext *, AVFrame *, int *, const AVPacket *);
};

#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 0
#define AV_LOG_WARNING 0
#define AVMEDIA_TYPE_AUDIO 0
#define CODEC_CAP_DELAY 0
#define AV_SAMPLE_FMT_NONE 0
#define AV_NOPTS_VALUE INT64_MIN
#define AV_NUM_DATA_POINTERS 8
#define AV_PKT_DATA_SKIP_SAMPLES 0

#define AVERROR(e) (-(e))
#define EINVAL 1

void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
void avcodec_get_frame_defaults(AVFrame *frame);
int av_packet_split_side_data(AVPacket *pkt);
void apply_param_change(AVCodecContext *avctx, AVPacket *pkt);
uint8_t *av_packet_get_side_data(const AVPacket *pkt, int type, int *size);
void add_metadata_from_side_data(AVCodecContext *avctx, AVFrame *frame);
int64_t av_rescale_q(int64_t a, AVRational bq, AVRational cq);
int av_sample_fmt_is_planar(int fmt);
int av_get_channel_layout_nb_channels(uint64_t channel_layout);
void ff_packet_free_side_data(AVPacket *pkt);
int64_t guess_correct_pts(AVCodecContext *ctx, int64_t pts, int64_t dts);
void av_samples_copy(uint8_t **dst, uint8_t **src, int dst_offset, int src_offset, int nb_samples, int channels, int sample_fmt);

#define AV_RL32(x) (*(uint32_t*)(x))