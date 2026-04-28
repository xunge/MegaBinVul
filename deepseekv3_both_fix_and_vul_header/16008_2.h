#include <stdint.h>
#include <unistd.h>
#include <errno.h>

typedef int32_t __s32;

struct file;
struct io_uring_ctx {
    void *file_data;
};

struct io_kiocb {
    struct {
        uint64_t arg;
        unsigned int nr_args;
    } rsrc_update;
    struct io_uring_ctx *ctx;
};

#define u64_to_user_ptr(x) ((void*)(uintptr_t)(x))
#define __user
#define IORING_FILE_INDEX_ALLOC 0
#define ENXIO 6
#define EFAULT 14
#define EBADF 9

static inline int copy_from_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

struct file *fget(int fd);
int io_fixed_fd_install(struct io_kiocb *req, unsigned int issue_flags, struct file *file, int alloc);
void __io_close_fixed(struct io_kiocb *req, unsigned int issue_flags, int fd);