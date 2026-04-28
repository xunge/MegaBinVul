#include <stdlib.h>
#include <stdint.h>

struct dc;
struct resource_pool {
    /* empty structure definition to make it complete */
};
struct dce110_resource_pool {
    struct resource_pool base;
};

#define GFP_KERNEL 0
#define BREAK_TO_DEBUGGER()

void* kzalloc(size_t size, int flags);
int construct(uint8_t num_virtual_links, struct dc *dc, struct dce110_resource_pool *pool);