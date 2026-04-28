#include <stdbool.h>
#include <stddef.h>

struct io_uring_ctx {
    unsigned int flags;
    bool compat;
};

struct io_kiocb {
    struct io_uring_ctx *ctx;
    void *file;
    struct fs_struct *fs;
    unsigned int flags;
};

struct io_uring_sqe {
    unsigned int msg_flags;
    unsigned long addr;
    unsigned long user_data;
};

struct socket;
struct user_msghdr {
    /* dummy structure */
};
#define __user

struct fs_struct {
    int users;
    void *lock;
};

#define IORING_SETUP_IOPOLL (1U << 0)
#define REQ_F_NOWAIT (1U << 0)
#define MSG_DONTWAIT (1U << 0)
#define MSG_CMSG_COMPAT (1U << 0)
#define EINVAL 22
#define EAGAIN 11
#define ERESTARTSYS 512
#define EINTR 4

#define unlikely(x) (x)
#define READ_ONCE(x) (x)

static inline struct socket *sock_from_file(void *file, int *err) { return NULL; }
static inline void io_req_put_fs(struct io_kiocb *req) {}
static inline void io_cqring_add_event(struct io_uring_ctx *ctx, unsigned long user_data, int ret) {}
static inline void io_put_req(struct io_kiocb *req) {}
static inline void free_fs_struct(struct fs_struct *fs) {}
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}