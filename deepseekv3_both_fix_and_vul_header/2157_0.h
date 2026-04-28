#include <stdint.h>

#define MAX_FRAMESIZE 4096

typedef struct PutBitContext {
    uint32_t bit_buf;
    int bit_left;
    uint8_t *buf, *buf_ptr, *buf_end;
} PutBitContext;

typedef struct AudioFrame {
    int nb_samples;
} AudioFrame;

typedef struct WmallChannelCdlms {
    int order;
} WmallChannelCdlms;

typedef struct WmallDecodeCtx {
    int packet_loss;
    int packet_done;
    int num_saved_bits;
    uint8_t frame_data[MAX_FRAMESIZE];
    PutBitContext pb;
    int frame_offset;
    int next_packet_start;
    WmallChannelCdlms cdlms[2][32];
    AudioFrame frame;
} WmallDecodeCtx;

typedef struct AVCodecContext {
    void *priv_data;
} AVCodecContext;

static inline void init_put_bits(PutBitContext *s, uint8_t *buffer, int buffer_size) {}