#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

struct file {
    void *private_data;
};

struct fuse_file {
    struct fuse_conn *fc;
};

struct fuse_conn {
    size_t max_write;
    size_t max_read;
};

struct fuse_req {
    struct {
        struct {
            int error;
        } h;
    } out;
};

struct task_struct {
    struct files_struct *files;
};

extern struct task_struct *current;

typedef struct files_struct *fl_owner_t;

#define __user
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define EIO 5
#define min(a, b) ((a) < (b) ? (a) : (b))

ssize_t fuse_get_req(struct fuse_conn *fc);
int fuse_get_user_pages(struct fuse_req *req, const char *buf, size_t *nbytes, int write);
size_t fuse_send_write(struct fuse_req *req, struct file *file, loff_t pos, size_t nbytes, fl_owner_t owner);
size_t fuse_send_read(struct fuse_req *req, struct file *file, loff_t pos, size_t nbytes, fl_owner_t owner);
void fuse_release_user_pages(struct fuse_req *req, int write);
void fuse_put_request(struct fuse_conn *fc, struct fuse_req *req);