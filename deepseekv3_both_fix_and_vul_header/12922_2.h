#include <stdbool.h>
#include <stddef.h>
#include <linux/errno.h>

struct io_msg {
    int cmd;
};

struct io_kiocb {
    struct file *file;
    unsigned int flags;
};

struct file;

#define EBADFD 77
#define EINVAL 22
#define IOU_OK 0
#define IORING_MSG_DATA 0
#define IORING_MSG_SEND_FD 1
#define REQ_F_FIXED_FILE (1U << 0)

int io_msg_ring_data(struct io_kiocb *req);
int io_msg_send_fd(struct io_kiocb *req, unsigned int issue_flags);
bool io_is_uring_fops(struct file *file);
void req_set_fail(struct io_kiocb *req);
void io_req_set_res(struct io_kiocb *req, int res, unsigned int cflags);
void io_put_file(struct file *file);
#define io_kiocb_to_cmd(req, type) ((type *)(req))