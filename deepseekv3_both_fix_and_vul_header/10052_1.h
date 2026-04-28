#include <stdlib.h>
#include <stdint.h>

#define VREND_MAX_CTX 256

struct vrend_decode_ctx {
    void *grctx;
    void *ds;
    void *ids;
};

extern struct vrend_decode_ctx *dec_ctx[VREND_MAX_CTX];
extern void *vrend_create_context(uint32_t handle, uint32_t nlen, const char *debug_name);