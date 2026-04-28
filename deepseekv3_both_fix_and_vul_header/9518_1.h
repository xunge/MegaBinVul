#include <stdint.h>

typedef struct vga_state {
    uint8_t *vram_ptr;
} vga_state;

typedef struct CirrusVGAState {
    struct vga_state vga;
    uint32_t cirrus_blt_dstaddr;
    uint32_t cirrus_addr_mask;
    void (*cirrus_rop)(struct CirrusVGAState *, uint8_t *, const uint8_t *,
                      int, int, int, int);
    int cirrus_blt_dstpitch;
    int cirrus_blt_width;
    int cirrus_blt_height;
} CirrusVGAState;

#define BLTUNSAFE(s) (0)

static void cirrus_invalidate_region(CirrusVGAState *s, uint32_t addr,
                                    int pitch, int width, int height);