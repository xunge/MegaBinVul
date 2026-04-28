#include <stdint.h>
#include <stdlib.h>

#define av_cold

#define AV_PIX_FMT_PAL8 0
#define MAX_CODEBOOK_SIZE 0x10000
#define VQA_HEADER_SIZE 0x2A

#define AV_LOG_ERROR 0
#define AVERROR(e) (-(e))
#define EINVAL 22
#define AVERROR_PATCHWELCOME (-0x5b)
#define AVERROR_INVALIDDATA (-0x3eb2b2b7)
#define ENOMEM 12

typedef struct AVCodecContext {
    int pix_fmt;
    int extradata_size;
    uint8_t *extradata;
    void *priv_data;
} AVCodecContext;

typedef struct VqaContext {
    AVCodecContext *avctx;
    int vqa_version;
    int width;
    int height;
    int vector_width;
    int vector_height;
    int partial_count;
    int partial_countdown;
    int codebook_size;
    uint8_t *codebook;
    uint8_t *next_codebook_buffer;
    int next_codebook_buffer_index;
    int decode_buffer_size;
    uint8_t *decode_buffer;
} VqaContext;

static inline uint16_t AV_RL16(const uint8_t *p) {
    return p[0] | (p[1] << 8);
}

static void av_log(void *avctx, int level, const char *fmt, ...) {}
static void avpriv_report_missing_feature(void *avctx, const char *fmt, ...) {}
static void avpriv_request_sample(void *avctx, const char *fmt, ...) {}
static int av_image_check_size(int w, int h, int log_offset, void *log_ctx) { return 0; }
static void *av_malloc(size_t size) { return malloc(size); }
static void *av_mallocz(size_t size) { return calloc(1, size); }
static void av_freep(void *ptr) { free(*(void**)ptr); }