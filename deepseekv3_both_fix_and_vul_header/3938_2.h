#include <stdbool.h>
#include <stddef.h>

struct io_kiocb {
    struct io_ring_ctx *ctx;
    union {
        struct {
            unsigned long old_user_data;
            unsigned long new_user_data;
            unsigned int events;
            bool update_events;
            bool update_user_data;
        } poll_update;
        struct {
            unsigned int events;
        } poll;
    };
    unsigned long user_data;
};

struct io_ring_ctx {
    int completion_lock;
};

static inline void io_ring_submit_lock(struct io_ring_ctx *ctx, bool nonblock) {}
static inline void io_ring_submit_unlock(struct io_ring_ctx *ctx, bool nonblock) {}
static inline bool io_poll_disarm(struct io_kiocb *req) { return false; }
static inline struct io_kiocb *io_poll_find(struct io_ring_ctx *ctx, unsigned long user_data, bool locked) { return NULL; }
static inline int io_poll_add(struct io_kiocb *req, unsigned int issue_flags) { return 0; }
static inline void req_set_fail(struct io_kiocb *req) {}
static inline void io_req_complete(struct io_kiocb *req, int res) {}

#define IO_URING_F_NONBLOCK 0x1
#define IO_POLL_UNMASK 0x10000
#define spin_lock(lock) (void)0
#define spin_unlock(lock) (void)0
#define EALREADY 114
#define ENOENT 2
#define ECANCELED 125