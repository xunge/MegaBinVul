#include <stdint.h>

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
    int size_in_bits;
} GetBitContext;

typedef struct AVCodecContext {
    int debug;
} AVCodecContext;

typedef struct MpegEncContext {
    GetBitContext gb;
    AVCodecContext *avctx;
} MpegEncContext;

typedef struct H264Context {
    MpegEncContext s;
} H264Context;

#define FF_DEBUG_STARTCODE 1
#define AV_LOG_DEBUG 0

#define SEI_TYPE_PIC_TIMING 1
#define SEI_TYPE_USER_DATA_UNREGISTERED 2
#define SEI_TYPE_RECOVERY_POINT 3
#define SEI_BUFFERING_PERIOD 4

static int get_bits_count(GetBitContext *gb);
static unsigned int show_bits(GetBitContext *gb, int n);
static unsigned int get_bits(GetBitContext *gb, int n);
static void skip_bits(GetBitContext *gb, int n);
static void align_get_bits(GetBitContext *gb);
static void av_log(AVCodecContext *avctx, int level, const char *fmt, ...);
static int decode_picture_timing(H264Context *h);
static int decode_unregistered_user_data(H264Context *h, int size);
static int decode_recovery_point(H264Context *h);
static int decode_buffering_period(H264Context *h);