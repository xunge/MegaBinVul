#include <stddef.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>

typedef unsigned int fmode_t;

struct kiocb {
    unsigned long ki_flags;
    void *private;
    void (*ki_complete)(struct kiocb *iocb, long res, long res2);
};

struct file_operations {
    int (*iopoll)(struct kiocb *kiocb, bool spin);
};

struct file {
    fmode_t f_mode;
    unsigned int f_flags;
    struct file_operations *f_op;
};

struct io_ring_ctx {
    unsigned int flags;
};

struct io_kiocb {
    struct {
        struct kiocb kiocb;
        int flags;
    } rw;
    struct io_ring_ctx *ctx;
    struct file *file;
    unsigned int flags;
    unsigned int iopoll_completed;
};

#define EBADF 9
#define EOPNOTSUPP 95
#define EINVAL 22

#define IOCB_NOWAIT (1 << 0)
#define IOCB_DIRECT (1 << 1)
#define IOCB_HIPRI (1 << 2)
#define IOCB_ALLOC_CACHE (1 << 3)

#define REQ_F_SUPPORT_NOWAIT_BIT 0
#define REQ_F_NOWAIT (1 << 0)

#define IORING_SETUP_IOPOLL (1U << 0)

static inline int io_req_ffs_set(struct io_kiocb *req) { return 0; }
static inline unsigned int io_file_get_flags(struct file *file) { return 0; }
static inline unsigned int iocb_flags(struct file *file) { return 0; }
static inline int kiocb_set_rw_flags(struct kiocb *kiocb, int flags) { return 0; }
static inline bool io_file_supports_nowait(struct io_kiocb *req) { return false; }
static void io_complete_rw_iopoll(struct kiocb *iocb, long res, long res2) {}
static void io_complete_rw(struct kiocb *iocb, long res, long res2) {}