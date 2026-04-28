#include <stdint.h>
#include <stddef.h>

typedef struct _Jbig2Ctx Jbig2Ctx;

typedef enum {
    JBIG2_COMPOSE_OR,
    JBIG2_COMPOSE_AND,
    JBIG2_COMPOSE_XOR,
    JBIG2_COMPOSE_XNOR,
    JBIG2_COMPOSE_REPLACE
} Jbig2ComposeOp;

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t stride;
    uint8_t *data;
} Jbig2Image;

void jbig2_image_compose_opt_OR(uint8_t *ss, uint8_t *dd, int early, int late, uint8_t leftmask, uint8_t rightmask, uint32_t bytewidth, uint32_t h, uint32_t shift, uint32_t dst_stride, uint32_t src_stride);
void jbig2_image_compose_opt_AND(uint8_t *ss, uint8_t *dd, int early, int late, uint8_t leftmask, uint8_t rightmask, uint32_t bytewidth, uint32_t h, uint32_t shift, uint32_t dst_stride, uint32_t src_stride);
void jbig2_image_compose_opt_XOR(uint8_t *ss, uint8_t *dd, int early, int late, uint8_t leftmask, uint8_t rightmask, uint32_t bytewidth, uint32_t h, uint32_t shift, uint32_t dst_stride, uint32_t src_stride);
void jbig2_image_compose_opt_XNOR(uint8_t *ss, uint8_t *dd, int early, int late, uint8_t leftmask, uint8_t rightmask, uint32_t bytewidth, uint32_t h, uint32_t shift, uint32_t dst_stride, uint32_t src_stride);
void jbig2_image_compose_opt_REPLACE(uint8_t *ss, uint8_t *dd, int early, int late, uint8_t leftmask, uint8_t rightmask, uint32_t bytewidth, uint32_t h, uint32_t shift, uint32_t dst_stride, uint32_t src_stride);