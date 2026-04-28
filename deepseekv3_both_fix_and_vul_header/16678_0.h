#include <stdint.h>

#define IORING_SETUP_R_DISABLED  (1U << 0)
#define EBADFD 77

struct io_restriction {
    int registered;
};

struct io_ring_ctx {
    unsigned int flags;
    struct io_restriction restrictions;
    int restricted;
};

void io_sq_offload_start(struct io_ring_ctx *ctx);