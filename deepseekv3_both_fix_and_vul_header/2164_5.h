#include <stdint.h>
#include <stdlib.h>

#define OS_HDR_ID 0x12345678
#define BS_8BIT_PEL (1 << 0)
#define BS_MV_X_HALF (1 << 1)
#define BS_MV_Y_HALF (1 << 2)

#define AV_LOG_ERROR 16
#define AV_LOG_DEBUG 48

typedef struct AVCodecContext AVCodecContext;

typedef struct Indeo3DecodeContext {
    int frame_num;
    int frame_flags;
    int data_size;
    int cb_offset;
    int width;
    int height;
    uint32_t y_data_size;
    uint32_t v_data_size;
    uint32_t u_data_size;
    const uint8_t *y_data_ptr;
    const uint8_t *v_data_ptr;
    const uint8_t *u_data_ptr;
    const uint8_t *alt_quant;
} Indeo3DecodeContext;

static inline uint32_t bytestream_get_le32(const uint8_t **b) {
    uint32_t v = *(*b)++;
    v |= *(*b)++ << 8;
    v |= *(*b)++ << 16;
    v |= *(*b)++ << 24;
    return v;
}

static inline uint16_t bytestream_get_le16(const uint8_t **b) {
    uint16_t v = *(*b)++;
    v |= *(*b)++ << 8;
    return v;
}

static inline int av_image_check_size(int w, int h, int log_offset, AVCodecContext *avctx) {
    return 0;
}

static inline void av_dlog(AVCodecContext *avctx, const char *fmt, ...) {}

static inline void av_log(AVCodecContext *avctx, int level, const char *fmt, ...) {}

static inline void av_log_ask_for_sample(AVCodecContext *avctx, const char *fmt, ...) {}

static inline void avcodec_set_dimensions(AVCodecContext *avctx, int width, int height) {}

static inline void free_frame_buffers(Indeo3DecodeContext *ctx) {}

static inline int allocate_frame_buffers(Indeo3DecodeContext *ctx, AVCodecContext *avctx, ...) {
    return 0;
}

#define AVERROR_INVALIDDATA -1
#define AVERROR_PATCHWELCOME -2

#define FFMAX3(a, b, c) ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
#define FFMIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))