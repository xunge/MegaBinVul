#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

typedef struct AVCodecContext {
    int active_thread_type;
    int height;
    int width;
    int err_recognition;
    int noise_reduction;
    int xvmc_acceleration;
} AVCodecContext;

typedef struct MpegEncContext MpegEncContext;
typedef struct Picture Picture;

enum AVPictureType {
    AV_PICTURE_TYPE_NONE = 0,
    AV_PICTURE_TYPE_I,
    AV_PICTURE_TYPE_P,
    AV_PICTURE_TYPE_B,
    AV_PICTURE_TYPE_S,
    AV_PICTURE_TYPE_SI,
    AV_PICTURE_TYPE_SP,
    AV_PICTURE_TYPE_BI
};

enum CodecID {
    CODEC_ID_NONE,
    CODEC_ID_MPEG1VIDEO,
    CODEC_ID_MPEG2VIDEO,
    CODEC_ID_H263,
    CODEC_ID_H264,
    CODEC_ID_SVQ3,
    CODEC_ID_FLV1
};

enum PixelFormat {
    FMT_NONE,
    FMT_H261,
    FMT_H263,
    FMT_H264,
    FMT_MPEG1,
    FMT_MPEG2
};

enum PictureStructure {
    PICT_FRAME,
    PICT_TOP_FIELD,
    PICT_BOTTOM_FIELD
};

enum AVLogLevel {
    AV_LOG_ERROR,
    AV_LOG_INFO,
    AV_LOG_DEBUG
};

#define FF_THREAD_FRAME 1
#define CONFIG_MPEG_XVMC_DECODER 0
#define HAVE_THREADS 0

struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int reference;
    int key_frame;
    int pict_type;
    int top_field_first;
    int interlaced_frame;
    int field_picture;
    int coded_picture_number;
    int quality;
};

struct Picture {
    struct AVFrame f;
    void *owner2;
    int field_picture;
};

struct MpegEncContext {
    int mb_skipped;
    Picture *last_picture_ptr;
    int out_format;
    int codec_id;
    int pict_type;
    Picture *next_picture_ptr;
    int encoding;
    Picture picture[32];
    int picture_count;
    int dropable;
    int coded_picture_number;
    Picture *current_picture_ptr;
    int top_field_first;
    int picture_structure;
    int first_field;
    int progressive_frame;
    int progressive_sequence;
    Picture current_picture;
    Picture last_picture;
    Picture next_picture;
    int err_recognition;
    int mpeg_quant;
    void (*dct_unquantize_intra)(struct MpegEncContext *s, int16_t *block, int n, int qscale);
    void (*dct_unquantize_inter)(struct MpegEncContext *s, int16_t *block, int n, int qscale);
    void (*dct_unquantize_mpeg2_intra)(struct MpegEncContext *s, int16_t *block, int n, int qscale);
    void (*dct_unquantize_mpeg2_inter)(struct MpegEncContext *s, int16_t *block, int n, int qscale);
    void (*dct_unquantize_h263_intra)(struct MpegEncContext *s, int16_t *block, int n, int qscale);
    void (*dct_unquantize_h263_inter)(struct MpegEncContext *s, int16_t *block, int n, int qscale);
    void (*dct_unquantize_mpeg1_intra)(struct MpegEncContext *s, int16_t *block, int n, int qscale);
    void (*dct_unquantize_mpeg1_inter)(struct MpegEncContext *s, int16_t *block, int n, int qscale);
    int dct_error_sum;
    AVCodecContext *avctx;
};

int ff_alloc_picture(MpegEncContext *s, Picture *pic, int shared);
void ff_copy_picture(Picture *dst, Picture *src);
void ff_release_unused_pictures(MpegEncContext *s, int remove_current);
int ff_find_unused_picture(MpegEncContext *s, int shared);
void free_frame_buffer(MpegEncContext *s, Picture *pic);
void ff_thread_report_progress(struct AVFrame *f, int progress, int field);
int ff_xvmc_field_start(MpegEncContext *s, AVCodecContext *avctx);
void update_noise_reduction(MpegEncContext *s);
void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);