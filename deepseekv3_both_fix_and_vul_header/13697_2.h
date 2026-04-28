#include <stdlib.h>
#include <stdint.h>

#define GFP_KERNEL 0

struct dc;
struct resource_pool {
    // 添加必要的成员字段
    int dummy;  // 示例字段，实际应根据需要定义
};
struct dce110_resource_pool {
    struct resource_pool base;
};

void* kzalloc(size_t size, int flags);
void BREAK_TO_DEBUGGER(void);
int construct(uint8_t num_virtual_links, struct dc* dc, struct dce110_resource_pool* pool);