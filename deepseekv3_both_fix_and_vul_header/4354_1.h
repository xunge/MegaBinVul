#include <errno.h>

struct fuse_conn;
struct file {
    void *private_data;
};

struct fuse_conn *fuse_conn_get(struct fuse_conn *fc);