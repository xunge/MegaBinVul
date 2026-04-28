#include <stdint.h>
#include <stdlib.h>

typedef struct AVRational {
    int num;
    int den;
} AVRational;

#define AV_LOG_ERROR 0
#define AV_LOG_INFO 0
#define FF_DEBUG_PICT_INFO 0
#define AV_PIX_FMT_RGB32 0
#define AV_PIX_FMT_RGB555 0
#define AV_PIX_FMT_RGB565 0
#define AVERROR_INVALIDDATA 0
#define AVERROR_PATCHWELCOME 0

#define FLAG_KEYFRAME 1
#define FLAG_INTERFRAME 2
#define FLAG_SPRITE 4
#define FLAG_INTERPOLATED 8

#define ALGO_RGB24H 0

struct frame_header {
    int header_size;
    int compression;
    int deltaset;
    int vectable;
    int ysize;
    int xsize;
    int checksum;
    int version;
    int header_type;
    int flags;
    int control;
};

typedef struct {
    int algorithm;
    int block_width;
    int block_height;
    int block_type;
} CompressionType;

typedef struct {
    int width;
    int height;
    int pix_fmt;
    int debug;
    void (*log)(void*, int, const char*, ...);
    int (*set_dimensions)(void*, int, int);
    AVRational sample_aspect_ratio;
} AVCodecContext;

typedef struct {
    uint8_t *buf;
    int size;
    int w;
    int h;
    int flags;
    int last_deltaset;
    int last_vectable;
    int compression;
    int block_width;
    int block_height;
    int block_type;
    AVCodecContext *avctx;
    void *frame;
    uint8_t *mb_change_bits;
    uint8_t *index_stream;
    int index_stream_size;
    int mb_change_bits_row_size;
    void *vert_pred;
    size_t vert_pred_size;
} TrueMotion1Context;

static const CompressionType compression_types[17];
static const uint8_t pc_tbl2[256];
static const uint8_t *tables[3];

static void avpriv_request_sample(void*, const char*);
static void av_log(void*, int, const char*, ...);
static int ff_set_dimensions(void*, int, int);
static void av_frame_unref(void*);
static void av_fast_malloc(void**, size_t*, size_t);
static void select_delta_tables(TrueMotion1Context*, int);
static void gen_vector_table24(TrueMotion1Context*, const uint8_t*);
static void gen_vector_table15(TrueMotion1Context*, const uint8_t*);
static void gen_vector_table16(TrueMotion1Context*, const uint8_t*);

#define AV_RL16(x) ((x)[0] | ((x)[1] << 8))