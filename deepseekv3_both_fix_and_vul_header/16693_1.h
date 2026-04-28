#include <stdint.h>
#include <stddef.h>
#include <sys/uio.h>

struct vmctx;
struct vring_desc {
    uint64_t addr;
    uint32_t len;
    uint16_t flags;
    uint16_t next;
};

void *paddr_guest2host(struct vmctx *ctx, uint64_t addr, size_t len);