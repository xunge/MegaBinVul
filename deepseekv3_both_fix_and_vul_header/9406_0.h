#include <stdint.h>
#include <stdlib.h>

#define FRAME_ID 0x69637072
#define FF_MIN_BUFFER_SIZE 32
#define AV_PICTURE_TYPE_I 1
#define AV_PKT_FLAG_KEY (1 << 0)
#define CODEC_FLAG_INTERLACED_DCT (1 << 0)
#define QUANT_MAT_DEFAULT 0

typedef struct AVCodecContext {
    void *priv_data;
    int width;
    int height;
    int flags;
    int color_primaries;
    int color_trc;
    int colorspace;
    int mb_width;
    int mb_height;
    struct AVFrame *coded_frame;
    int (*execute2)(struct AVCodecContext *c, int (*func)(struct AVCodecContext *c2, void *arg, int jobnr, int threadnr), void *arg2, void *arg3, int ret);
    int frame_size_upper_bound;
} AVCodecContext;

typedef struct AVPacket {
    uint8_t *data;
    int size;
    int flags;
} AVPacket;

typedef struct AVFrame {
    int pict_type;
    int key_frame;
    int top_field_first;
} AVFrame;

typedef struct PutBitContext {
    uint8_t *buf;
    int size_in_bits;
} PutBitContext;

typedef struct ProresContext {
    int num_planes;
    int frame_size_upper_bound;
    char vendor[4];
    int chroma_factor;
    int alpha_bits;
    int quant_sel;
    uint8_t quant_mat[64];
    int cur_picture_idx;
    int pictures_per_frame;
    int slices_per_picture;
    int mbs_per_slice;
    int slices_width;
    int *slice_q;
    int force_quant;
    int mb_width;
    int mb_height;
} ProresContext;

int ff_alloc_packet2(AVCodecContext *avctx, AVPacket *avpkt, int size);
int encode_slice(AVCodecContext *avctx, const AVFrame *pic, PutBitContext *pb, int *sizes, int x, int y, int q, int mbs_per_slice);
int find_quant_thread(AVCodecContext *avctx, void *arg, int jobnr, int threadnr);
int av_log2(unsigned v);

static inline void bytestream_put_be16(uint8_t **b, unsigned int value);
static inline void bytestream_put_be32(uint8_t **b, unsigned int value);
static inline void bytestream_put_byte(uint8_t **b, unsigned int value);
static inline void bytestream_put_buffer(uint8_t **b, const uint8_t *src, unsigned int size);
static inline void init_put_bits(PutBitContext *s, uint8_t *buffer, int buffer_size);