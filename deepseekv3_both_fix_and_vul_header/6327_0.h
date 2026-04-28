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
    // dummy definition, actual implementation may vary
};

static inline struct htx_blk *htx_add_blk(struct htx *htx, int type, size_t size);
static inline void *htx_get_blk_ptr(struct htx *htx, struct htx_blk *blk);
static inline void ist2bin_lc(char *dst, struct ist src);

#define HTX_BLK_HDR 0