#include <stdbool.h>
#include <assert.h>

struct CirrusVGAState {
    int cirrus_blt_width;
    int cirrus_blt_height;
    int cirrus_blt_dstpitch;
    int cirrus_blt_srcpitch;
    unsigned int cirrus_blt_dstaddr;
    unsigned int cirrus_blt_srcaddr;
    unsigned int cirrus_addr_mask;
};

#define CIRRUS_BLTBUFSIZE 4096

bool blit_region_is_unsafe(struct CirrusVGAState *s, int pitch, unsigned int addr);