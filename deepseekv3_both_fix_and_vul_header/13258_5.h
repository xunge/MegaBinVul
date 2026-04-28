#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>

struct file;
struct io_uring_ctx;

struct io_splice {
    struct file *file_out;
    unsigned int flags;
    int splice_fd_in;
    off_t off_in;
    off_t off_out;
    size_t len;
};

struct io_kiocb {
    struct io_uring_ctx *ctx;
    struct io_splice splice;
};

#define SPLICE_F_FD_IN_FIXED 0x01
#define IO_URING_F_NONBLOCK  0x02
#define EAGAIN              11
#define EBADF                9

static struct file *io_file_get(struct io_uring_ctx *ctx, struct io_kiocb *req, int fd, bool fixed, ...) {
    return NULL;
}
static void io_put_file(struct file *file) {}
static void req_set_fail(struct io_kiocb *req) {}
static void io_req_complete(struct io_kiocb *req, long ret) {}
static long do_splice(struct file *in, off_t *off_in, struct file *out, off_t *off_out, size_t len, unsigned int flags) {
    return 0;
}