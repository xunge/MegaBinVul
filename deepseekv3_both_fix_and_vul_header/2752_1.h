#include <stdint.h>
#include <stdlib.h>

#define attribute_align_arg

#define AV_LOG_ERROR 0
#define AV_LOG_DEBUG 1
#define AV_LOG_WARNING 2
#define AVMEDIA_TYPE_AUDIO 0
#define CODEC_CAP_DELAY 0
#define AV_SAMPLE_FMT_NONE 0
#define AV_NOPTS_VALUE INT64_MIN
#define AV_NUM_DATA_POINTERS 8
#define AV_PKT_DATA_SKIP_SAMPLES 0
#define AVERROR(e) (-(e))
#define EINVAL 22

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecContext {
    const struct AVCodec *codec;
    int sample_fmt;
    uint64_t channel_layout;
    int channels;
    int sample_rate;
    int frame_number;
    struct AVPacket *pkt;
    struct {
        int skip_samples;
    } *internal;
    AVRational pkt_timebase;
    void (*log)(void*, int, const char*, ...);
} AVCodecContext;

typedef struct AVFrame {
    uint8_t *data[AV_NUM_DATA_POINTERS];
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
} AVFrame;

typedef struct AVPacket {
    uint8_t *data;
    int size;
    int64_t dts;
    uint8_t *side_data;
    int side_data_elems;
} AVPacket;

typedef struct AVCodec {
    int type;
    int capabilities;
    int (*decode)(AVCodecContext *, AVFrame *, int *, const AVPacket *);
} AVCodec;

void avcodec_get_frame_defaults(AVFrame *frame);
void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
int av_packet_split_side_data(AVPacket *pkt);
void apply_param_change(AVCodecContext *avctx, AVPacket *pkt);
int64_t guess_correct_pts(AVCodecContext *ctx, int64_t pts, int64_t dts);
void add_metadata_from_side_data(AVCodecContext *avctx, AVFrame *frame);
uint8_t *av_packet_get_side_data(const AVPacket *pkt, int type, int *size);
uint32_t AV_RL32(const uint8_t *p);
int av_sample_fmt_is_planar(int sample_fmt);
void av_samples_copy(uint8_t **dst, uint8_t **src, int dst_offset, int src_offset, int nb_samples, int channels, int sample_fmt);
int64_t av_rescale_q(int64_t a, AVRational bq, AVRational cq);
void ff_packet_free_side_data(AVPacket *pkt);