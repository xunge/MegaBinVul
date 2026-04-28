#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>

#define IOCB_HIPRI 0x00000001
#define IOCB_NOWAIT 0x00000002
#define READ 0
#define WRITE 1

struct kiocb {
    int ki_flags;
};

struct file_operations {
    ssize_t (*read)(struct file *, void *, size_t, off_t *);
    ssize_t (*write)(struct file *, const void *, size_t, off_t *);
};

struct file {
    struct file_operations *f_op;
};

struct io_kiocb {
    struct {
        struct kiocb kiocb;
        size_t len;
        uint64_t addr;
    } rw;
    struct file *file;
};

struct iov_iter {
    // Minimal stub definition
    unsigned int type;
    size_t count;
};

static off_t *io_kiocb_ppos(struct kiocb *kiocb) { return NULL; }
static size_t iov_iter_count(struct iov_iter *iter) { return iter->count; }
static bool iov_iter_is_bvec(struct iov_iter *iter) { return iter->type == 2; }
static struct iovec iov_iter_iovec(struct iov_iter *iter) { return (struct iovec){0}; }
static void iov_iter_advance(struct iov_iter *iter, size_t bytes) { iter->count -= bytes; }
static void *u64_to_user_ptr(uint64_t addr) { return (void *)(uintptr_t)addr; }