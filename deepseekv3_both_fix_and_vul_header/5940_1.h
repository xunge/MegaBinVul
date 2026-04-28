#include <stdint.h>
#include <stdlib.h>

#define FFMAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct AVCodecContext {
    void *priv_data;
    void (*release_buffer)(struct AVCodecContext *, struct AVFrame *);
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
} AVPacket;

typedef struct AVFrame {
    uint8_t *data[8];
} AVFrame;

typedef struct AVPicture {
    uint8_t *data[8];
} AVPicture;

typedef struct GetBitContext {
    const uint8_t *buffer;
    int index;
} GetBitContext;

typedef struct ParseContext {
    int last_index;
} ParseContext;

typedef struct MpegEncContext {
    AVCodecContext *avctx;
    GetBitContext gb;
    ParseContext parse_context;
    int low_delay;
} MpegEncContext;

typedef struct AVSContext {
    MpegEncContext s;
    int got_keyframe;
    int pic_type;
    AVPicture DPB[2];
    AVPicture picture;
    uint32_t stc;
} AVSContext;

enum {
    CAVS_START_CODE,
    PIC_I_START_CODE,
    PIC_PB_START_CODE,
    EXT_START_CODE,
    USER_START_CODE,
    SLICE_MAX_START_CODE
};

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

static void init_get_bits(GetBitContext *s, const uint8_t *buffer, int bit_size);
static int decode_seq_header(struct AVSContext *h);
static int decode_pic(struct AVSContext *h);
static int decode_slice_header(struct AVSContext *h, GetBitContext *gb);
static const uint8_t *ff_find_start_code(const uint8_t *p, const uint8_t *end, uint32_t *state);