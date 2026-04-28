#include <stdint.h>

typedef struct VGACommonState {
    void *vram;
} VGACommonState;

typedef struct CirrusVGAState {
    VGACommonState vga;
    uint32_t cirrus_addr_mask;
} CirrusVGAState;

void memory_region_set_dirty(void *mr, unsigned offset, unsigned size);