#include <stdbool.h>

struct io_ring_ctx;
struct io_kiocb;
struct file;

struct file *io_file_get_fixed(struct io_ring_ctx *ctx, struct io_kiocb *req, int fd, ...);
struct file *io_file_get_normal(struct io_ring_ctx *ctx, struct io_kiocb *req, int fd);