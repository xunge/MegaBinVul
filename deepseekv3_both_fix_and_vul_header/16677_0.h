#include <pthread.h>

struct io_ring_ctx {
    pthread_mutex_t uring_lock;
    int sqo_dead;
    unsigned int flags;
    void *rings;
};

#define IORING_SETUP_R_DISABLED (1U << 0)

void io_sq_offload_start(struct io_ring_ctx *ctx);
void io_ring_set_wakeup_flag(struct io_ring_ctx *ctx);