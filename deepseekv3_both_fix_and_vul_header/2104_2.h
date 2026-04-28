#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

#define CONFIG_MPEG_XVMC_DECODER 1

typedef struct AVFrame {
    uint8_t *data[4];
    int linesize[4];
    int reference;
    int key_frame;
    int pict_type;
    int top_field_first;
    int interlaced_frame;
    int coded_picture_number;
} AVFrame;

typedef struct AVCodecContext {
    int active_thread_type;
    int err_recognition;
    int width;
    int height;
    int (*update_noise_reduction)(void *s);
    int xvmc_acceleration;
    int noise_reduction;
} AVCodecContext;

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

enum {
    FF_THREAD_FRAME = 1,
    AV_LOG_ERROR,
    AV_LOG_INFO,
    AV_LOG_DEBUG
};

enum {
    FMT_H263,
    FMT_H261,
    FMT_H264,
    FMT_MPEG1,
    FMT_MPEG2,
};

enum {
    CODEC_ID_MPEG1VIDEO,
    CODEC_ID_MPEG2VIDEO,
    CODEC_ID_H263,
    CODEC_ID_H264,
    CODEC_ID_SVQ3,
    CODEC_ID_FLV1,
};

enum {
    PICT_FRAME,
    PICT_TOP_FIELD,
    PICT_BOTTOM_FIELD,
};

typedef struct Picture {
    AVFrame f;
    int reference;
    int key_frame;
    int coded_picture_number;
    void *owner2;
    int field_picture;
} Picture;

typedef struct MpegEncContext {
    int mb_skipped;
    Picture *last_picture_ptr;
    Picture *next_picture_ptr;
    Picture *current_picture_ptr;
    int out_format;
    int codec_id;
    int pict_type;
    int encoding;
    int picture_count;
    Picture *picture;
    int dropable;
    int picture_structure;
    int top_field_first;
    int first_field;
    int progressive_frame;
    int progressive_sequence;
    int coded_picture_number;
    Picture current_picture;
    Picture last_picture;
    Picture next_picture;
    int width;
    int height;
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
} MpegEncContext;

void free_frame_buffer(MpegEncContext *s, Picture *pic);
void ff_release_unused_pictures(MpegEncContext *s, int release_all);
int ff_find_unused_picture(MpegEncContext *s, int shared);
int ff_alloc_picture(MpegEncContext *s, Picture *pic, int shared);
void ff_copy_picture(Picture *dst, Picture *src);
void ff_thread_report_progress(AVFrame *f, int progress, int field);
void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
int update_noise_reduction(MpegEncContext *s);
int ff_xvmc_field_start(MpegEncContext *s, AVCodecContext *avctx);