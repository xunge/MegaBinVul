#include <stddef.h>
#include <errno.h>
#include <stdbool.h>

#define IORING_MSG_DATA 0
#define IORING_MSG_SEND_FD 1
#define IOU_OK 0
#define IOU_ISSUE_SKIP_COMPLETE (-ECANCELED)

struct io_kiocb {
    struct file *file;
};

struct io_msg {
    int cmd;
};

struct file;

int io_msg_ring_data(struct io_kiocb *req, ...);
int io_msg_send_fd(struct io_kiocb *req, unsigned int issue_flags);
bool io_is_uring_fops(struct file *file);
void req_set_fail(struct io_kiocb *req);
void io_req_set_res(struct io_kiocb *req, int res, unsigned int flags);
#define io_kiocb_to_cmd(req, type) ((type *)(req))