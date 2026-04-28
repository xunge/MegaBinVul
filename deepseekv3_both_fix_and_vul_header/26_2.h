#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    int flags;
    int key_frame;
    void *buf[0];
} AVFrame;

typedef struct Picture {
    AVFrame f;
    int poc;
    int mmco_reset;
    int recovered;
} Picture;

typedef struct H264Context {
    int flags;
    int data_partitioning;
    Picture *cur_pic_ptr;
    Picture *delayed_pic[16];
    int nal_unit_type;
    int mb_y;
    int mb_height;
    Picture *next_output_pic;
    void *priv_data;
} H264Context;

typedef struct AVCodecContext {
    int flags;
    int flags2;
    int skip_frame;
    void *priv_data;
} AVCodecContext;

#define AVERROR_INVALIDDATA (-1)
#define AV_LOG_ERROR 0
#define AVDISCARD_NONREF 0
#define CODEC_FLAG_OUTPUT_CORRUPT (1 << 0)
#define CODEC_FLAG2_CHUNKS (1 << 0)
#define AV_FRAME_FLAG_CORRUPT (1 << 0)
#define NAL_END_SEQUENCE 0

static void av_log(void *avctx, int level, const char *fmt, ...) {}

static int decode_nal_units(H264Context *h, const uint8_t *buf, int buf_size, int flag) { return 0; }
static int output_frame(H264Context *h, AVFrame *pict, AVFrame *f) { return 0; }
static int decode_postinit(H264Context *h, int flag) { return 0; }
static void field_end(H264Context *h, int flag) {}
static int get_consumed_bytes(int buf_index, int buf_size) { return 0; }