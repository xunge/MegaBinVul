#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define VREND_MAX_CTX 256

struct vrend_decode_ctx {
    void *grctx;
};

extern struct vrend_decode_ctx *dec_ctx[VREND_MAX_CTX];

bool vrend_destroy_context(void *grctx);
void vrend_hw_switch_context(void *grctx, bool flag);