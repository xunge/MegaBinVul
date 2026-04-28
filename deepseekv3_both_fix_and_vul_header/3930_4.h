#include <stdbool.h>
#include <stddef.h>

struct io_kiocb;
struct io_comp_state;

struct files_struct {
    struct fdtable *fdt;
    void *file_lock;
};

struct fdtable {
    unsigned int max_fds;
    struct file **fd;
};

struct file {
    struct file_operations *f_op;
};

struct file_operations {
    int (*flush)(struct file *);
};

extern const struct file_operations io_uring_fops;

struct io_close {
    int fd;
    struct file *put_file;
};

struct io_kiocb {
    struct io_close close;
    struct {
        unsigned int flags;
        struct {
            struct files_struct *files;
        } *identity;
    } work;
    unsigned int flags;
};

#define EBADF 9
#define EAGAIN 11
#define ENOENT 2

#define REQ_F_NOWAIT (1 << 0)
#define REQ_F_NO_FILE_TABLE (1 << 1)
#define IO_WQ_WORK_NO_CANCEL (1 << 0)

extern struct {
    struct files_struct *files;
} *current;

extern void spin_lock(void *);
extern void spin_unlock(void *);
extern struct fdtable *files_fdtable(struct files_struct *);
extern int __close_fd_get_file(int, struct file **);
extern int filp_close(struct file *, struct files_struct *);
extern void req_set_fail_links(struct io_kiocb *);
extern void fput(struct file *);
extern void __io_req_complete(struct io_kiocb *, int, int, struct io_comp_state *);
extern int close_fd_get_file(int, struct file **);