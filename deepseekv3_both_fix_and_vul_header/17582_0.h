#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define AV_LOG_WARNING 0
#define AV_LOG_ERROR 1
#define AVERROR_INVALIDDATA 1
#define AVERROR(ENOMEM) 1
#define ENOMEM 1
#define AV_RB16(p) 0
#define AV_INPUT_BUFFER_PADDING_SIZE 0

typedef struct AVBufferRef AVBufferRef;
typedef struct CodedBitstreamContext {
    void *log_ctx;
} CodedBitstreamContext;
typedef struct CodedBitstreamFragment {
    uint8_t *data;
    size_t data_size;
    AVBufferRef *data_ref;
} CodedBitstreamFragment;

#define JPEG_MARKER_SOI 0xd8
#define JPEG_MARKER_EOI 0xd9
#define JPEG_MARKER_SOS 0xda

static void av_log(void *log_ctx, int level, const char *fmt, ...);
static void *av_malloc(size_t size);
static int ff_cbs_insert_unit_data(CodedBitstreamContext *ctx, CodedBitstreamFragment *frag, int unit, int marker, uint8_t *data, size_t data_size, AVBufferRef *data_ref);