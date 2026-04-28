#include <stdlib.h>
#include <stdint.h>

#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))
#define FF_INPUT_BUFFER_PADDING_SIZE 16

typedef struct G2MContext {
    int width;
    int height;
    int old_width;
    int old_height;
    int tile_width;
    int tile_height;
    int old_tile_w;
    int old_tile_h;
    int framebuf_stride;
    int tile_stride;
    uint8_t *framebuf;
    uint8_t *synth_tile;
    uint8_t *jpeg_tile;
    uint8_t *kempf_buf;
    uint8_t *kempf_flags;
} G2MContext;

#define AVERROR(e) (-(e))
#define ENOMEM 12

void *av_mallocz(size_t size);
void av_free(void *ptr);