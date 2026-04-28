#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define io_kiocb_to_cmd(ptr, type) ((type *)(ptr))
#define io_poll_find(ctx, find, cd, table, bucket) NULL
#define io_poll_disarm(req) 0
#define io_ring_submit_lock(ctx, flags) do {} while (0)
#define io_ring_submit_unlock(ctx, flags) do {} while (0)
#define io_poll_add(req, flags) 0
#define req_set_fail(req) do {} while (0)
#define io_req_set_res(req, res, val) do {} while (0)
#define io_req_task_complete(req, ts) do {} while (0)
#define spin_unlock(lock) do {} while (0)
#define WARN_ON_ONCE(cond) (0)

struct io_kiocb {
    struct io_ring_ctx *ctx;
    int opcode;
    struct {
        uint64_t user_data;
    } cqe;
};

struct io_poll_update {
    uint64_t old_user_data;
    uint64_t new_user_data;
    bool update_events;
    bool update_user_data;
    uint32_t events;
};

struct io_poll {
    uint32_t events;
};

struct io_ring_ctx {
    void *cancel_table;
    void *cancel_table_locked;
};

struct io_hash_bucket {
    int lock;
};

struct io_cancel_data {
    uint64_t data;
};

struct io_tw_state {
    bool locked;
};

#define IORING_OP_POLL_ADD 0
#define IO_URING_F_UNLOCKED 0
#define IOU_OK 0
#define ENOENT 2
#define EIOCBQUEUED 0
#define ECANCELED 0
#define EFAULT 0
#define IO_POLL_UNMASK 0x80000000