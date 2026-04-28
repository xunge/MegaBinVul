#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

#define EBUSY 16
#define EAGAIN 11

struct io_ring_ctx {
    unsigned long sq_check_overflow;
    void *cq_overflow_list;
    unsigned int sq_entries;
    void *refs;
    int ring_fd;
    struct file *ring_file;
};

struct io_submit_state {
    void *comp;
};

struct io_kiocb {
    int opcode;
    uint64_t user_data;
};

struct io_uring_sqe {
    // sqe fields
};

struct file {
    // file fields
};

#define min(a, b) ((a) < (b) ? (a) : (b))
#define min3(x, y, z) min((x), min((y), (z)))
#define unlikely(x) (x)
#define test_bit(nr, addr) ((*(addr) & (1UL << (nr))) != 0)

static inline int list_empty(void *list) { return 1; }
static inline int io_cqring_overflow_flush(void *ctx, bool b, void *c, void *d) { return 0; }
static inline int io_sqring_entries(void *ctx) { return 0; }
static inline int percpu_ref_tryget_many(void *refs, unsigned int nr) { return 0; }
static inline void io_submit_state_start(void *state, void *ctx, unsigned int nr) {}
static inline const struct io_uring_sqe *io_get_sqe(void *ctx) { return NULL; }
static inline void io_consume_sqe(void *ctx) {}
static inline struct io_kiocb *io_alloc_req(void *ctx, void *state) { return NULL; }
static inline int io_init_req(void *ctx, void *req, const void *sqe, void *state) { return 0; }
static inline void io_put_req(void *req) {}
static inline void io_req_complete(void *req, int err) {}
static inline void trace_io_uring_submit_sqe(void *ctx, int opcode, uint64_t data, bool b, int c) {}
static inline int io_submit_sqe(void *req, const void *sqe, struct io_kiocb **link, void *comp) { return 0; }
static inline void percpu_ref_put_many(void *refs, unsigned int nr) {}
static inline void io_queue_link_head(struct io_kiocb *link, void *comp) {}
static inline void io_submit_state_end(void *state) {}
static inline void io_commit_sqring(void *ctx) {}
static inline int io_async_submit(void *ctx) { return 0; }