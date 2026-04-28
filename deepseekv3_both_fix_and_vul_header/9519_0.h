#include <stdint.h>

typedef struct CirrusVGAState {
    struct {
        uint32_t start_addr;
    } vga;
    uint32_t cirrus_blt_dstaddr;
    uint32_t cirrus_blt_srcaddr;
    int cirrus_blt_width;
    int cirrus_blt_height;
} CirrusVGAState;

#define BLTUNSAFE(s) (0)

static void cirrus_do_copy(CirrusVGAState *s, int dst, int src, int w, int h);