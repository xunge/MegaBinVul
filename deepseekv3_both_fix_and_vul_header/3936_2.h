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

#define IO_URING_F_NONBLOCK 0
#define IO_POLL_UNMASK 0
#define EALREADY 114
#define ENOENT 2
#define ECANCELED 125

static void io_ring_submit_lock(struct io_ring_ctx *ctx, int nonblock) {}
static void io_ring_submit_unlock(struct io_ring_ctx *ctx, int nonblock) {}
static struct io_kiocb *io_poll_find(struct io_ring_ctx *ctx, unsigned long user_data, bool locked) { return NULL; }
static bool io_poll_disarm(struct io_kiocb *req) { return false; }
static int io_poll_add(struct io_kiocb *req, unsigned int issue_flags) { return 0; }
static void req_set_fail(struct io_kiocb *req) {}
static void io_req_complete(struct io_kiocb *req, int status) {}
static void spin_lock(int *lock) {}
static void spin_unlock(int *lock) {}