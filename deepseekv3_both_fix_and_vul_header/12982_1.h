#include <stdint.h>
#include <stdlib.h>

#define AV_NOPTS_VALUE          ((int64_t)UINT64_C(0x8000000000000000))
#define FF_SANE_NB_CHANNELS     64
#define AVERROR(e) (-(e))
#define EINVAL 22
#define ENOSYS 38
#define AV_LOG_ERROR 16

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct AVCodecContext {
    struct {
        struct {
            int64_t pts;
            int64_t pos;
            int64_t duration;
            int size;
        } *pkt;
    } *internal;
    int64_t reordered_opaque;
    struct {
        int type;
    } *codec;
    int pix_fmt;
    AVRational sample_aspect_ratio;
    int colorspace;
    int color_range;
    int sample_rate;
    int sample_fmt;
    uint64_t channel_layout;
    int channels;
} AVCodecContext;

typedef struct AVFrame {
    int64_t pkt_pts;
    int format;
    AVRational sample_aspect_ratio;
    int sample_rate;
    uint64_t channel_layout;
    int64_t reordered_opaque;
} AVFrame;

void av_frame_set_pkt_pos(AVFrame *frame, int64_t pos);
void av_frame_set_pkt_duration(AVFrame *frame, int64_t duration);
void av_frame_set_pkt_size(AVFrame *frame, int size);
int av_frame_get_colorspace(const AVFrame *frame);
void av_frame_set_colorspace(AVFrame *frame, int val);
int av_frame_get_color_range(const AVFrame *frame);
void av_frame_set_color_range(AVFrame *frame, int val);
int av_get_channel_layout_nb_channels(uint64_t channel_layout);
void av_log(void *avcl, int level, const char *fmt, ...);
void av_frame_set_channels(AVFrame *frame, int channels);

enum AVMediaType {
    AVMEDIA_TYPE_VIDEO,
    AVMEDIA_TYPE_AUDIO
};

enum AVColorSpace {
    AVCOL_SPC_UNSPECIFIED
};

enum AVColorRange {
    AVCOL_RANGE_UNSPECIFIED
};