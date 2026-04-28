#include <stdint.h>
#include <stddef.h>

typedef struct VncPixelFormat {
    uint32_t rmax;
    uint8_t rbits;
    uint8_t rshift;
    uint32_t rmask;
    uint32_t gmax;
    uint8_t gbits;
    uint8_t gshift;
    uint32_t gmask;
    uint32_t bmax;
    uint8_t bbits;
    uint8_t bshift;
    uint32_t bmask;
    uint8_t bits_per_pixel;
    uint8_t bytes_per_pixel;
    uint8_t depth;
} VncPixelFormat;

typedef struct VncState {
    VncPixelFormat client_pf;
    int client_be;
} VncState;

static inline int hweight_long(unsigned long w) {
    w -= (w >> 1) & 0x55555555;
    w = (w & 0x33333333) + ((w >> 2) & 0x33333333);
    w = (w + (w >> 4)) & 0x0f0f0f0f;
    return (w * 0x01010101) >> 24;
}

void vnc_client_error(VncState *vs);
void set_pixel_conversion(VncState *vs);
void graphic_hw_invalidate(void *opaque);
void graphic_hw_update(void *opaque);