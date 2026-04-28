#include <stdint.h>

typedef struct VGAState {
    uint8_t *vram_ptr;
} VGAState;

typedef struct CirrusVGAState {
    VGAState vga;
    int cirrus_blt_pixelwidth;
    uint32_t cirrus_blt_dstaddr;
    uint32_t cirrus_addr_mask;
    uint32_t cirrus_blt_dstpitch;
    uint32_t cirrus_blt_width;
    uint32_t cirrus_blt_height;
} CirrusVGAState;

typedef void (*cirrus_fill_t)(CirrusVGAState *s, uint8_t *dst, uint32_t dstpitch, uint32_t width, uint32_t height);

extern int BLTUNSAFE(CirrusVGAState *s);
extern cirrus_fill_t cirrus_fill[][3];
extern const int rop_to_index[];
extern void cirrus_invalidate_region(CirrusVGAState *s, uint32_t addr, uint32_t pitch, uint32_t width, uint32_t height);
extern void cirrus_bitblt_reset(CirrusVGAState *s);