#include <stdlib.h>
#include <stdint.h>

struct resource_pool {
    // base structure definition
};

struct dc {
    // dc structure definition
};

struct hw_asic_id {
    // asic_id structure definition
};

struct dce110_resource_pool {
    struct resource_pool base;
    // other members
};

#define GFP_KERNEL 0
#define BREAK_TO_DEBUGGER()

void* kzalloc(size_t size, int flags);
int construct(uint8_t num_virtual_links, struct dc* dc, struct dce110_resource_pool* pool, struct hw_asic_id asic_id);