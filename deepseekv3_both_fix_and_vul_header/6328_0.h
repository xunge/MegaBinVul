#include <stdint.h>
#include <string.h>

struct ist {
    const char *ptr;
    size_t len;
};

struct htx_blk {
    uint32_t info;
};

struct htx {
    // minimal definition needed for compilation
};

static inline void *htx_get_blk_ptr(struct htx *htx, struct htx_blk *blk);
static inline struct htx_blk *htx_add_blk(struct htx *htx, int type, size_t size);
static inline void ist2bin_lc(void *dst, struct ist src);

#define HTX_BLK_TLR 0